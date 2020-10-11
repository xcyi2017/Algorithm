//
// Created by xcy on 2020/10/11.
//

#ifndef DAY13_DENSEGRAPH_H
#define DAY13_DENSEGRAPH_H

#include <vector>
#include <iostream>
#include <cassert>

// 稠密图 - 邻接矩阵
class DenseGraph {
private:
    int n, m; // 点数 边数
    bool directed;
    std::vector<std::vector<bool>> g;
public:
    explicit DenseGraph(int n, bool directed);

    ~DenseGraph() = default;

    int V() const; // 返回点数
    int E() const; // 返回边数

    void addEdge(int v, int w);

    bool hasEdge(int v, int w) const;

    class adjIterator {
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(DenseGraph& graph, int v): G(graph), v(v), index(-1){};
        int begin();
        int next();
        bool end();
    };



};


#endif //DAY13_DENSEGRAPH_H

