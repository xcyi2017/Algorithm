//
// Created by xcy on 2020/10/8.
//

#ifndef DAY12_UNIONFINDTESTHELPER_H
#define DAY12_UNIONFINDTESTHELPER_H

#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include "UnionFind5.h"
#include "UnionFind6.h"

#include <ctime>

namespace UnionFindTestHelper {
    void testUF1(int n) {
        std::srand((unsigned int) time(nullptr));
        UF1::UnionFind uf = UF1::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.unionElements(a, b);
        }
        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.isConnected(a, b);
        }
        // 测试以上操作的所用时间
        time_t endTime = clock();
        std::cout << "UF1, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }


    void testUF2(int n) {
        std::srand((unsigned int) time(nullptr));
        UF2::UnionFind uf = UF2::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.unionElements(a, b);
        }
        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.isConnected(a, b);
        }
        // 测试以上操作的所用时间
        time_t endTime = clock();
        std::cout << "UF2, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }

    void testUF3(int n) {
        std::srand((unsigned int) time(nullptr));
        UF3::UnionFind uf = UF3::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.unionElements(a, b);
        }
        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.isConnected(a, b);
        }
        // 测试以上操作的所用时间
        time_t endTime = clock();
        std::cout << "UF3, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }

    void testUF4(int n) {
        std::srand((unsigned int) time(nullptr));
        UF4::UnionFind uf = UF4::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.unionElements(a, b);
        }
        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.isConnected(a, b);
        }
        // 测试以上操作的所用时间
        time_t endTime = clock();
        std::cout << "UF4, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }

    void testUF5(int n) {
        std::srand((unsigned int) time(nullptr));
        UF5::UnionFind uf = UF5::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.unionElements(a, b);
        }
        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.isConnected(a, b);
        }
        // 测试以上操作的所用时间
        time_t endTime = clock();
        std::cout << "UF5, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }

    void testUF6(int n) {
        std::srand((unsigned int) time(nullptr));
        UF6::UnionFind uf = UF6::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.unionElements(a, b);
        }
        for (int i = 0; i < n; ++i) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            uf.isConnected(a, b);
        }
        // 测试以上操作的所用时间
        time_t endTime = clock();
        std::cout << "UF6, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }
}
#endif //DAY12_UNIONFINDTESTHELPER_H
