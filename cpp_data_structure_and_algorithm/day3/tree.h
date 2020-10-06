//
// Created by xcy on 2020/9/29.
//

#ifndef DAY3_TREE_H
#define DAY3_TREE_H

#include <deque>
#include <iostream>

struct Node {
    int val;
    Node *left = nullptr;
    Node *right = nullptr;

    explicit Node(int x) : val(x) {};
};

class Tree {
public:
    Tree() : root(nullptr) {};

    explicit Tree(int x) : root(new Node(x)) {};

    ~Tree() { delete root; };

    void add(int x);

    void print() const;

private:
    Node *root;
};

#endif //DAY3_TREE_H
