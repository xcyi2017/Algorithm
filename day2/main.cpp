#include "linklist.h"


//int add(int a, int b) {
//    if (b == 0)
//        return a;
//    int sum = a ^b;
//    int carray = (a & b) << 1;
//    return add(sum, carray);
//}
//
//
//
//int main() {
//    // std::cout << add(-2, -1000) << std::endl;
//    // std::cout << "Hello, World!" << std::endl;
//    std::cout << sizeof(struct st) << std::endl;
//    return 0;
//}

int main() {
    LinkList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.insert(4, 123);
    list.print();
    list.remove(5);
    list.print();
    std::cout << list.find(3) << std::endl;
    return 0;
}