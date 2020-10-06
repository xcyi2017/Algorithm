//#include "binarySearch.h"
//#include "utils.h"

//int main() {
//    int arr[] = {1, 5, 9, 2, 6, 0};
//    int n = sizeof(arr) / sizeof(n);
//    quickSort(arr, n);
//    std::cout << isSorted(arr, n) << std::endl;
//    printArray(arr, n);
//    std::cout << binarySearch_rec(arr, n, 2) << std::endl;
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

#include "BST.h"
#include "fileOps.h"
#include "sequenceST.h"

int main() {
    std::string filename = "/home/xcy/CLionProjects/Agorithm/cpp_data_structure_and_algorithm/day10/bible.txt";
    std::vector<std::string> words;
    if (fileOps::readFile(filename, words)) {
        std::cout << "There are totally " << words.size() << " words in " << filename << std::endl;

        // test BST
        time_t startTime = clock();
        BST<std::string, int> bst = BST<std::string, int>();
        for (auto &word : words) { // 计算词频
            int *res = bst.search(word);
            if (res == nullptr)
                bst.insert(word, 1);
            else
                (*res)++;
        }
        std::cout << "'god' :" << *bst.search("god") << std::endl;
        time_t endTime = clock();
        std::cout << "BST，time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;

        // test BST
        time_t startTime1 = clock();
        SequenceST<std::string, int> sst = SequenceST<std::string, int>();
        for (auto &word : words) { // 计算词频
            int *res = sst.search(word);
            if (res == nullptr)
                sst.insert(word, 1);
            else
                (*res)++;
        }
        std::cout << "'god' :" << *sst.search("god") << std::endl;
        time_t endTime1 = clock();
        std::cout << "SST，time: " << double(endTime1 - startTime1) / CLOCKS_PER_SEC << " s" << std::endl;
    }
    return 0;
}