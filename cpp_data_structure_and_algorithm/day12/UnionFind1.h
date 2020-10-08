//
// Created by xcy on 2020/10/8.
//

#ifndef DAY12_UnionFind1_H
#define DAY12_UnionFind1_H

#include <iostream>
#include <cassert>

namespace UF1 {
    class UnionFind {
    private:
        int *id;
        int count;
    public:
        explicit UnionFind(int n);

        ~UnionFind();

        int find(int p) const;

        bool isConnected(int p, int q) const;

        void unionElements(int p, int q);
    };


    UnionFind::UnionFind(int n) : count(n), id(new int[n]) {
        for (int i = 0; i < n; ++i) // 同一组有相同的id号
            id[i] = i;
    }

    UnionFind::~UnionFind() {
        delete[] id;
    }

    int UnionFind::find(int p) const {
        assert(p >= 0 && p < count);
        return id[p];
    }

    bool UnionFind::isConnected(int p, int q) const {
        return find(p) == find(q);
    }

    void UnionFind::unionElements(int p, int q) {
        int pID = find(p);
        int qID = find(q);
        if (pID == qID)
            return;
        for (int i = 0; i < count; ++i)
            if (id[i] == pID)
                id[i] = qID;
    }

}
#endif //DAY12_UnionFind1_H
