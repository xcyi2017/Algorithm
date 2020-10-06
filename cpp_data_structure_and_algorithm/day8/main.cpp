#include "maxHeap.h"
#include "utils.h"

int main() {
    MaxHeap<int> maxheap = MaxHeap<int>(100);
    std::cout << maxheap.size() << std::endl;
    std::srand((unsigned int) time(nullptr));
    for (int i = 0; i < 15; ++i) {
        maxheap.insert(std::rand()%100);
    }
    maxheap.testPrint();

    while (!maxheap.isEmpty())
        std::cout << maxheap.extractMax() << std::endl;


    return 0;
}
