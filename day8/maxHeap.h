//
// Created by xcy on 2020/10/4.
//

#ifndef DAY8_MAXHEAP_H
#define DAY8_MAXHEAP_H

#include <iostream>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <string>
#include <cmath>

template<typename Item>
class MaxHeap {
private:
    Item *data;
    int count = 0;
    int capacity;
public:
    explicit MaxHeap(int capacity) : data(new Item[capacity + 1]), capacity(capacity) {};

    explicit MaxHeap(Item arr[], int n) : data(new Item[n + 1]), capacity(n), count(n) {
        for (int i = 0; i < n; ++i) data[i + 1] = arr[i];
        for (int i = count / 2; i >= 1; --i) shiftDown(i);
    };

    ~MaxHeap() { delete[] data; };

    int size() const;

    bool isEmpty() const;

    void insert(Item item);

    Item extractMax();

    void testPrint();

private:
    void shiftUp(int k);

    void shiftDown(int k);

    void putNumberInLine(int num, std::string &line, int index_cur_level, int cur_tree_width, bool isLeft);

    void putBranchInLine(std::string &line, int index_cur_level, int cur_tree_width);
};

template<typename Item>
int MaxHeap<Item>::size() const {
    return count;
}

template<typename Item>
bool MaxHeap<Item>::isEmpty() const {
    return count == 0;
}

template<typename Item>
void MaxHeap<Item>::insert(Item item) {
    assert(this->capacity >= count + 1);
    data[count + 1] = item;
    ++count;
    shiftUp(count);
}

template<typename Item>
void MaxHeap<Item>::shiftUp(int k) {
    while (k > 1 && data[k / 2] < data[k]) {
        std::swap(data[k / 2], data[k]);
        k /= 2;
    }
}


// 以树状打印整个堆结构
template<typename Item>
void MaxHeap<Item>::testPrint() {

    // 我们的testPrint只能打印100个元素以内的堆的树状信息
    if (size() >= 100) {
        std::cout << "This print function can only work for less than 100 int";
        return;
    }

    // 我们的testPrint只能处理整数信息
    if (typeid(Item) != typeid(int)) {
        std::cout << "This print function can only work for int item";
        return;
    }

    std::cout << "The max heap size is: " << size() << std::endl;
    std::cout << "Data in the max heap: ";
    for (int i = 1; i <= size(); i++) {
        // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
        assert(data[i] >= 0 && data[i] < 100);
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int n = size();
    int max_level = 0;
    int number_per_level = 1;
    while (n > 0) {
        max_level += 1;
        n -= number_per_level;
        number_per_level *= 2;
    }

    int max_level_number = int(pow(2, max_level - 1));
    int cur_tree_max_level_number = max_level_number;
    int index = 1;
    for (int level = 0; level < max_level; level++) {
        std::string line1 = std::string(max_level_number * 3 - 1, ' ');

        int cur_level_number = std::min(count - int(std::pow(2, level)) + 1, int(std::pow(2, level)));
        bool isLeft = true;
        for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
            putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
            isLeft = !isLeft;
        }
        std::cout << line1 << std::endl;

        if (level == max_level - 1)
            break;

        std::string line2 = std::string(max_level_number * 3 - 1, ' ');
        for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
            putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
        std::cout << line2 << std::endl;

        cur_tree_max_level_number /= 2;
    }
}

template<typename Item>
void MaxHeap<Item>::putNumberInLine(int num, std::string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

    int sub_tree_width = (cur_tree_width - 1) / 2;
    int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
    assert(offset + 1 < line.size());
    if (num >= 10) {
        line[offset + 0] = '0' + num / 10;
        line[offset + 1] = '0' + num % 10;
    } else {
        if (isLeft)
            line[offset + 0] = '0' + num;
        else
            line[offset + 1] = '0' + num;
    }
}

template<typename Item>
void MaxHeap<Item>::putBranchInLine(std::string &line, int index_cur_level, int cur_tree_width) {

    int sub_tree_width = (cur_tree_width - 1) / 2;
    int sub_sub_tree_width = (sub_tree_width - 1) / 2;
    int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
    assert(offset_left + 1 < line.size());
    int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
    assert(offset_right < line.size());

    line[offset_left + 1] = '/';
    line[offset_right + 0] = '\\';
}

template<typename Item>
Item MaxHeap<Item>::extractMax() {
    assert(count > 0);
    Item ret = data[1];
    std::swap(data[1], data[count--]);
    shiftDown(1);
    return ret;

}

template<typename Item>
void MaxHeap<Item>::shiftDown(int k) {
    while (2 * k <= count) {
        int j = 2 * k;//在此纶循环中，data[k]和data[j]交换位置
        if (j + 1 <= count && data[j + 1] > data[j])
            j += 1;
        if (data[k] >= data[j]) break;
        std::swap(data[k], data[j]);
        k = j; // 新的父节点
    }

}


#endif //DAY8_MAXHEAP_H
