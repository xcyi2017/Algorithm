//
// Created by xcy on 2020/10/8.
//

#ifndef DAY12_UNIONFIND2_H
#define DAY12_UNIONFIND2_H

#include <cassert>
#include <iostream>

namespace UF2 {
    class UnionFind {
    private:
        int *parent;
        int count;
    public:
        explicit UnionFind(int n);

        ~UnionFind();

        int find(int p) const;

        bool isConnected(int p, int q) const;

        void unionElements(int p, int q);

    };

    UnionFind::UnionFind(int n) : parent(new int[n]), count(n) {
        for (int i = 0; i < count; i++)
            parent[i] = i; // 初始状态两两元素互不连接
    }

    UnionFind::~UnionFind() {
        delete[] parent;
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
        parent[pRoot] = qRoot;
    }
}

#endif //DAY12_UNIONFIND2_H
