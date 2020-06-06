//
// Created by xcy on 2020/9/28.
//

#ifndef DAY2_LINKLIST_H
#define DAY2_LINKLIST_H

#include <iostream>
#include <cassert>

struct Node {
    int val;
    Node *next = nullptr;

    explicit Node(int x) : val(x) {};
};

class LinkList {
public:
    explicit LinkList();

    ~LinkList() { delete root; };

    void append(int x);

    void print() const;

    void insert(int pos, int x);

    void remove(int pos);

    bool find(int x) const;

private:
    Node *root;
    int count;
};

inline
LinkList::LinkList() : count(0) {
    root = new Node(0);
}


#endif //DAY2_LINKLIST_H
