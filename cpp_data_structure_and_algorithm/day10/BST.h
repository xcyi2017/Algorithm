//
// Created by xcy on 2020/10/6.
//

#ifndef DAY10_BST_H
#define DAY10_BST_H

#include <iostream>

template<typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) : key(key), value(value), left(nullptr), right(nullptr) {};
    };

    Node *root;
    int count;

public:
    BST() : root(nullptr), count(0) {};

    ~BST() {
        //todo
    };

    int size() const;

    bool isEmpty() const;

    void insert(Key key, Value value);

    bool contain(Key key) const;
    // 若返回Node，得在private中实现
    // 返回Value 不能为空
    Value* search(Key key) const;

private:
    // 向以node为根的二叉搜索树添加（key，value）
    // 返回二叉搜索树的根节点
    Node *insert(Node *node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }
        if (node->key == key) node->value = value;
        else if (key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);
        return node;
    }
    bool contain(Node* node, Key key) const;
    Value* search(Node* node, Key key) const;
};


template<typename Key, typename Value>
int BST<Key, Value>::size() const {
    return count;
}

template<typename Key, typename Value>
bool BST<Key, Value>::isEmpty() const {
    return count == 0;
}

template<typename Key, typename Value>
void BST<Key, Value>::insert(Key key, Value value) {
    root = insert(root, key, value);
}

template<typename Key, typename Value>
bool BST<Key, Value>::contain(BST::Node *node, Key key) const {
    // 以node为根的树是否存在键值key
    if (node == nullptr) return false;
    if (node->key == key) return true;
    else if (node->key > key)
        return contain(node->left, key);
    else
        return contain(node->right, key);
}

template<typename Key, typename Value>
bool BST<Key, Value>::contain(Key key) const {
    return contain(root, key);
}

template<typename Key, typename Value>
Value *BST<Key, Value>::search(Key key) const {
    return search(root, key);
}

template<typename Key, typename Value>
Value *BST<Key, Value>::search(BST::Node *node, Key key) const {
    if (node == nullptr) return nullptr;
    if (node->key == key) return &node->value;
    else if (node->key > key)
        return search(node->left, key);
    else
        return search(node->right, key);
}


#endif //DAY10_BST_H