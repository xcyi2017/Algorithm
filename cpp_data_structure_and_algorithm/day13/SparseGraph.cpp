//
// Created by xcy on 2020/10/11.
//

#include "SparseGraph.h"

SparseGraph::SparseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
    for (int i = 0; i < n; i++)
        g.emplace_back();
}

int SparseGraph::V() const {
    return n;
}

int SparseGraph::E() const {
    return m;
}

void SparseGraph::addEdge(int v, int w) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    g[v].push_back(w);
    if (v != w && !directed) g[w].push_back(v);
    m++;
}

bool SparseGraph::hasEdge(int v, int w) const {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    for (int i = 0; i < g[v].size(); ++i)
        if (g[v][i] == w)
            return true;
    return false;
}

int SparseGraph::adjIterator::begin() {
    index = 0;
    if (!G.g[v].empty()) return G.g[v][index];
    return -1;
}

int SparseGraph::adjIterator::next() {
    index++;
    if (index < G.g[v].size()) return G.g[v][index];
    return -1;
}

bool SparseGraph::adjIterator::end() {
    return index >= G.g[v].size();
}
