//
// Created by xcy on 2020/10/8.
//

#ifndef DAY12_UNIONFIND3_H
#define DAY12_UNIONFIND3_H

#include <cassert>
#include <iostream>

namespace UF3 {
    class UnionFind {
    private:
        int *parent;
        int *sz; // sz[i]表示以i为根的集合中元素的个数
        int count;
    public:
        explicit UnionFind(int n);

        ~UnionFind();

        int find(int p) const;

        bool isConnected(int p, int q) const;

        void unionElements(int p, int q);

    };

    UnionFind::UnionFind(int n) : parent(new int[n]), sz(new int[n]), count(n) {
        for (int i = 0; i < count; i++) {
            parent[i] = i; // 初始状态两两元素互不连接
            sz[i] = 1; // 初始状态每个元素自身组成一个集合
        }
    }

    UnionFind::~UnionFind() {
        delete[] parent;
        delete[] sz;
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
        if (sz[pRoot] < sz[qRoot]) {
            parent[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            parent[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }

    }
}

#endif //DAY12_UNIONFIND3_H
