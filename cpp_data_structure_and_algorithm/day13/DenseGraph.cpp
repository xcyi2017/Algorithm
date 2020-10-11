//
// Created by xcy on 2020/10/11.
//

#include "DenseGraph.h"

DenseGraph::DenseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
    for (int i = 0; i < n; i++)
        g.emplace_back(n, false);
}

int DenseGraph::V() const {
    return n;
}

int DenseGraph::E() const {
    return m;
}

void DenseGraph::addEdge(int v, int w) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    if (hasEdge(v, w)) return;
    g[v][w] = true;
    if (!directed) g[w][v] = true;
    m++;
}

bool DenseGraph::hasEdge(int v, int w) const {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    return g[v][w];
}

int DenseGraph::adjIterator::begin() {
    index = -1; // 不见得是第一个元素
    next();
}

int DenseGraph::adjIterator::next() {
    for (index += 1; index < G.V(); index++) {
        if (G.g[v][index])
            return index;
    }
    return -1;
}

bool DenseGraph::adjIterator::end() {
    return index >= G.V();
}
