//
// Created by xcy on 2020/10/8.
//

#ifndef DAY12_UNIONFIND4_H
#define DAY12_UNIONFIND4_H

#include <cassert>
#include <iostream>

namespace UF4 {
    class UnionFind {
    private:
        int *parent;
        int *rank; // rank[i]表示以i为根的集合中层数
        int count;
    public:
        explicit UnionFind(int n);

        ~UnionFind();

        int find(int p) const;

        bool isConnected(int p, int q) const;

        void unionElements(int p, int q);

    };

    UnionFind::UnionFind(int n) : parent(new int[n]), rank(new int[n]), count(n) {
        for (int i = 0; i < count; i++) {
            parent[i] = i; // 初始状态两两元素互不连接
            rank[i] = 1; // 初始状态每个元素自身组成一个集合
        }
    }

    UnionFind::~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    int UnionFind::find(int p) const {
        assert(p >= 0 && p < count);
        while (p != parent[p])
            p = parent[p];
        return p;
    }

    bool UnionFind::isConnected(int p, int q) const {
        return find(p) == find(q);
    }

    void UnionFind::unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot)
            return;
        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else if (rank[pRoot] > rank[qRoot]) {
            parent[qRoot] = pRoot;
        } else {
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
}

#endif //DAY12_UNIONFIND4_H
