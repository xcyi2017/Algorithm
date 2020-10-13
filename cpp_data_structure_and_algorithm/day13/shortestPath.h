//
// Created by xcy on 2020/10/13.
//

#ifndef DAY13_SHORTESTPATH_H
#define DAY13_SHORTESTPATH_H

#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

template<typename Graph>
class ShortestPath {
private:
    Graph &G;
    int s; // 起始节点
    bool *visited;
    int *from;
    int *ord;
public:
    ShortestPath(Graph &graph, int s);

    ~ShortestPath();

    bool hasPath(int w);

    int length(int w);

    void path(int w, std::vector<int> &vec);

    void showPath(int w);
};

template<typename Graph>
ShortestPath<Graph>::ShortestPath(Graph &graph, int s)
        :G(graph),
         visited(new bool[G.V()]),
         from(new int[G.V()]),
         ord(new int[G.V()]) {
    // 算法初始化
    assert(s >= 0 && s < G.V());

    for (int i = 0; i < G.V(); ++i) {
        visited[i] = false;
        from[i] = -1;
        ord[i] = -1;
    }
    this->s = s;
    std::queue<int> q;
    // 无向图寻最短路径
    q.push(s);
    visited[s] = true;
    ord[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        typename Graph::adjIterator adj(G, v); // 访问与节点相连的所有节点

        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (visited[i]) {
                q.push(i);
                visited[i] = true;
                from[i] = v;
                ord[i]++;
            }
        }
    }

}

template<typename Graph>
ShortestPath<Graph>::~ShortestPath() {
    delete[] visited;
    delete[] from;
    delete[] ord;
}


template<typename Graph>
bool ShortestPath<Graph>::hasPath(int w) {
    assert(w >= 0 && w < G.V());
    return visited[w];
}

template<typename Graph>
void ShortestPath<Graph>::path(int w, std::vector<int> &vec) {
    std::stack<int> ss;
    int p = w;
    while (p != -1) { // 直到访问到原节点，原节点没有被赋值
        ss.push(p);
        p = from[p];
    }
    vec.clear();
    while (!ss.empty()) {
        vec.push_back(ss.top());
        ss.pop();
    }
}

template<typename Graph>
void ShortestPath<Graph>::showPath(int w) {
    std::vector<int> vec;
    path(w, vec);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1)
            std::cout << "->";
    }
    std::cout << std::endl;
}

template<typename Graph>
int ShortestPath<Graph>::length(int w) {
    assert(w >= 0 && w < G.V());
    return ord[w];
}

#endif //DAY13_SHORTESTPATH_H
