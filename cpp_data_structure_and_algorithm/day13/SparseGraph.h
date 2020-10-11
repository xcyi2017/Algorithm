//
// Created by xcy on 2020/10/11.
//

#ifndef DAY13_SPARSEGRAPH_H
#define DAY13_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

// 稀疏图 邻接表
class SparseGraph {
private:
    int n, m;
    bool directed;
    std::vector<std::vector<int>> g;
public:
    SparseGraph(int n, bool directed);

    ~SparseGraph() = default;

    int V() const; // 返回点数
    int E() const; // 返回边数

    void addEdge(int v, int w);

    bool hasEdge(int v, int w) const;

    class adjIterator {
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparseGraph& graph, int v): G(graph), v(v), index(0){};
        int begin();
        int next();
        bool end();
    };
};


#endif //DAY13_SPARSEGRAPH_H
