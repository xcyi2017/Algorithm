//
// Created by xcy on 2020/9/28.
//
#include "linklist.h"

void LinkList::append(int x) {
    Node *node = new Node(x);
    if (!root->next)
        root->next = node;
    else {
        Node *cur = root;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = node;
    }
    ++count;
}

void LinkList::print() const {
    Node *cur = root->next;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void LinkList::insert(int pos, int x) {
    Node *node = new Node(x);
    if (pos <= 0) {
        node->next = root->next;
        root->next = node;
    } else {
        int i;
        Node *cur = root->next;
        for (i = 0; i < pos - 1; ++i) {
            cur = cur->next;
            if (i == count - 1) break;
        }
        if (i != count - 1)
            node->next = cur->next;
        cur->next = node;
    }
    ++count;
}

void LinkList::remove(int pos) {
    assert(pos >= 0 && pos < count);
    int i;
    Node *cur = root, *pre = nullptr;

    for (i = 0; i <= pos; ++i) {
        pre = cur;
        cur = cur->next;
    }
    if (i == count - 1) {
        pre->next = nullptr;
    } else {
        pre->next = cur->next;
    }
    --count;
}

bool LinkList::find(int x) const {
    Node *cur = root;
    while (cur)
    {
        if (cur->val==x) return true;
        cur = cur->next;
    }
    return false;
}