//
// Created by xcy on 2020/10/11.
//

#ifndef DAY13_COMPONENT_H
#define DAY13_COMPONENT_H

#include <iostream>
#include <cassert>

template<typename Graph>
class Component {
private:
    Graph &G;
    bool *visited;
    int ccount; // 连通分量
    int *id;// 和并查集一样的思路，相连的节点标号一致


    void dfs(int v);
private:
    explicit Component(Graph &graph);

    ~Component();

    int count() const;
    bool isConnected(int v, int w) const;
};

template<typename Graph>
Component<Graph>::Component(Graph &graph): G(graph), visited(new bool[G.V()]), ccount(0), id(new int[G.V]) {
    for (int i = 0; i < G.V(); i++) {
        visited[i] = false;
        id[i] = -1;
    }

    for (int i = 0; i < G.V(); ++i) {
        if (!visited[i]) {
            dfs(i);
            ccount++;
        }
    }

}

template<typename Graph>
Component<Graph>::~Component() {
    delete[] visited;
}

template<typename Graph>
int Component<Graph>::count() const {
    return ccount;
}

template<typename Graph>
void Component<Graph>::dfs(int v) {
    visited[v] = true;
    id[v] = ccount;
    typename Graph::adjIterator adj(G, v);
    for (int i = adj.begin(); !adj.end(); i = adj.next()) {
        if (!visited[i])
            dfs(i);
    }
}

template<typename Graph>
bool Component<Graph>::isConnected(int v, int w) const {
    assert(v >= 0 && v < G.V);
    assert(w >= 0 && w < G.V);
    return id[v] == id[w];
}

#endif //DAY13_COMPONENT_H
