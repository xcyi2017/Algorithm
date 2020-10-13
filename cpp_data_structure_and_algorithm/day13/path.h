//
// Created by xcy on 2020/10/12.
//

#ifndef DAY13_PATH_H
#define DAY13_PATH_H

#include <cassert>
#include <iostream>
#include <vector>
#include <stack>

template<typename Graph>
class Path {
private:
    Graph &G;
    int s; // 起始节点
    bool *visited;
    int *from;
public:
    Path(Graph &graph, int s);

    ~Path();

    bool hasPath(int w);

    void dfs(int v);

    void path(int w, std::vector<int> &vec);

    void showPath(int w);
};

template<typename Graph>
Path<Graph>::Path(Graph &graph, int s):G(graph), visited(new bool[G.V()]), from(new int[G.V()]) {
    // 算法初始化
    assert(s >= 0 && s < G.V());

    for (int i = 0; i < G.V(); ++i) {
        visited[i] = false;
        from[i] = -1;
    }
    this->s = s;
    dfs(s);

    // 寻路算法
}

template<typename Graph>
Path<Graph>::~Path() {
    delete[] visited;
    delete[] from;
}

template<typename Graph>
void Path<Graph>::dfs(int v) {
    visited[v] = true;
    typename Graph::adjIterator adj(G, v);
    for (int i = adj.begin(); !adj.end(); i = adj.next()) {
        if (!visited[i]) {
            from[i] = v;
            dfs(i);
        }
    }
}

template<typename Graph>
bool Path<Graph>::hasPath(int w) {
    assert(w >= 0 && w < G.V());
    return visited[w];
}

template<typename Graph>
void Path<Graph>::path(int w, std::vector<int> &vec) {
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
void Path<Graph>::showPath(int w) {
    std::vector<int> vec;
    path(w, vec);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1)
            std::cout << "->";
    }
    std::cout << std::endl;
}

#endif //DAY13_PATH_H
