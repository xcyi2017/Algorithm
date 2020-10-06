//
// Created by xcy on 2020/10/5.
//

#ifndef DAY9_INDEXMAXHEAP_P_H
#define DAY9_INDEXMAXHEAP_P_H

#include <iostream>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <string>
#include <cmath>

template<typename Item>
class IndexMaxHeap_p {
private:
    Item *data;
    int *indexes;
    int *reverse;
    int count;
    int capacity;
public:
    explicit IndexMaxHeap_p(int capacity);

//    explicit IndexMaxHeap(Item arr[], int n) : data(new Item[n + 1]), capacity(n), count(n) {
//        for (int i = 0; i < n; ++i) data[i + 1] = arr[i];
//        for (int i = count / 2; i >= 1; --i) shiftDown(i);
//    };

    ~IndexMaxHeap_p() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    };

    int size() const;

    bool isEmpty() const;

    void insert(int i, Item item);

    Item extractMax();

    int extractMaxIndex();

    int getItem(int i) const;

    void change(int i, Item newItem);

    void testPrint();

private:
    void shiftUp(int k);

    void shiftDown(int k);

    void putNumberInLine(int num, std::string &line, int index_cur_level, int cur_tree_width, bool isLeft);

    void putBranchInLine(std::string &line, int index_cur_level, int cur_tree_width);

    bool contain(int i) const;
};

template<typename Item>
IndexMaxHeap_p<Item>::IndexMaxHeap_p(int capacity) : data(new Item[capacity + 1]),
                                                     indexes(new int[capacity + 1]),
                                                     reverse(new int[capacity + 1]),
                                                     count(0),
                                                     capacity(capacity) {
    for (int i = 0; i <= capacity; ++i) reverse[i] = 0;
}

template<typename Item>
int IndexMaxHeap_p<Item>::size() const {
    return count;
}

template<typename Item>
bool IndexMaxHeap_p<Item>::isEmpty() const {
    return count == 0;
}


// 传入的i对于arr是从0开始的
template<typename Item>
void IndexMaxHeap_p<Item>::insert(int i, Item item) {
    assert(this->capacity >= count + 1);
    assert(i + 1 <= this->capacity && i + 1 >= 1);
    i += 1;
    data[i] = item;
    indexes[count + 1] = i;
    reverse[i] = count + 1;
    ++count;
    shiftUp(count);
}

template<typename Item>
void IndexMaxHeap_p<Item>::shiftUp(int k) {
    while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
        std::swap(indexes[k / 2], indexes[k]);
        reverse[indexes[k / 2]] = k / 2;
        reverse[indexes[k]] = k;
        k /= 2;
    }
}

// 以树状打印整个堆结构
template<typename Item>
void IndexMaxHeap_p<Item>::testPrint() {

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
        assert(data[indexes[i]] >= 0 && data[indexes[i]] < 100);
        std::cout << data[indexes[i]] << " ";
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
            putNumberInLine(data[indexes[index]], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
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
void
IndexMaxHeap_p<Item>::putNumberInLine(int num, std::string &line, int index_cur_level, int cur_tree_width,
                                      bool isLeft) {

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
void IndexMaxHeap_p<Item>::putBranchInLine(std::string &line, int index_cur_level, int cur_tree_width) {

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
Item IndexMaxHeap_p<Item>::extractMax() {
    assert(count > 0);
    Item ret = data[indexes[1]];
    std::swap(indexes[1], indexes[count]);
    reverse[indexes[1]] = 1;
    reverse[indexes[count]] = 0;
    --count;
    shiftDown(1);
    return ret;

}

template<typename Item>
void IndexMaxHeap_p<Item>::shiftDown(int k) {
    while (2 * k <= count) {
        int j = 2 * k;//在此纶循环中，data[k]和data[j]交换位置
        if (j + 1 <= count && data[indexes[j] + 1] > data[indexes[j]])
            j += 1;
        if (data[indexes[k]] >= data[indexes[j]]) break;
        std::swap(data[indexes[k]], data[indexes[j]]);
        reverse[indexes[k]] = k;
        reverse[indexes[j]] = j;
        k = j; // 新的父节点
    }

}

template<typename Item>
int IndexMaxHeap_p<Item>::extractMaxIndex() {
    assert(count > 0);
    int ret = indexes[1] - 1;
    std::swap(indexes[1], indexes[count--]);
    shiftDown(1);
    return ret;
}

template<typename Item>
int IndexMaxHeap_p<Item>::getItem(int i) const {
    i += 1;
    assert(contain(i));
    return data[i];
}

template<typename Item>
void IndexMaxHeap_p<Item>::change(int i, Item newItem) {
    i += 1;
    assert(contain(i));
    data[i] = newItem;
    // 找到indexes[j] =i; j表示data[i]在堆中维护的位置；
    // shiftUp(j), 再shiftDown(j)
    //    for (int j = 1; j <= count; ++j) {
    //        if (indexes[j] == i) {
    //            shiftUp(j);
    //            shiftDown(j);
    //            break;
    //        }
    //    }
    int j = reverse[i];
    shiftUp(j);
    shiftDown(j);
}

template<typename Item>
bool IndexMaxHeap_p<Item>::contain(int i) const { // 判断索引是否在堆中
    assert(i + 1 >= 1 && i + 1 <= capacity);
    return reverse[i + 1] != 0;
}


#endif //DAY9_INDEXMAXHEAP_P_H
