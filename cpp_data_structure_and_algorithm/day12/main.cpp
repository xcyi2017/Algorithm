#include "UnionFindTestHelper.h"

int main() {
    int n = 1000000;
//    UnionFindTestHelper::testUF1(n); // 无父节点
//    UnionFindTestHelper::testUF2(n); // 父节点
//    UnionFindTestHelper::testUF3(n);// size
    UnionFindTestHelper::testUF4(n); // rank
    UnionFindTestHelper::testUF5(n); // rank + 路径压缩1
    UnionFindTestHelper::testUF6(n); // rank + 路径压缩2
    return 0;
}
