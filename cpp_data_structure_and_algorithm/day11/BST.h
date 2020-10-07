//
// Created by xcy on 2020/10/7.
//

#ifndef DAY10_BST_H
#define DAY10_BST_H

#include <iostream>
#include <queue>
#include <cassert>

template<typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) : key(key), value(value), left(nullptr), right(nullptr) {};

        explicit Node(const Node *node) : key(node->key), value(node->value), left(node->left), right(node->right) {};
    };

    Node *root;
    int count;

public:
    BST() : root(nullptr), count(0) {};

    ~BST();

    int size() const;

    bool isEmpty() const;

    void insert(Key key, Value value);

    bool contain(Key key) const;

    // 若返回Node，得在private中实现
    // 返回Value 不能为空
    Value *search(Key key) const;

    /*
     * 深度优先遍历
     **/
    void preorder() const;

    void inorder() const;

    void postorder() const;

    /*
     * 广度优先遍历（层序遍历）
     * */
    void levelOrder() const;

    Key minimum() const;

    Key maximum() const;
    // 删除最小节点

    void removeMin();

    // 删除最大节点

    void removeMax();

    // 删除任意节点
    void remove(Key key);

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

    bool contain(Node *node, Key key) const;

    Value *search(Node *node, Key key) const;

    void preorder(Node *node) const;

    void inorder(Node *node) const;

    void postorder(Node *node) const;

    void destroy(Node *node);

    void levelOrder(Node *node) const;

    //寻找最小数
    Node *minimum(Node *node) const {
        while (node->left) {
            node = node->left;
        }
        return node;
    };

    //寻找最大值
    Node *maximum(Node *node) const {
        if (!node->right) return node;
        return maximum(node->right);
    };

    // 删除最小值
    Node *removeMin(Node *node) {
//        Node *pre = nullptr;
//        Node *cur = node;
//        while (node->left) {
//            pre = cur;
//            cur = cur->left;
//        }
//        pre->right = cur->right;
//        delete cur;
//        --count;
//        return pre->right;
        if (node->left == nullptr) {
            Node *rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    };

    // 删除最大节点
    Node *removeMax(Node *node) {
        if (node->right == nullptr) {
            Node *leftNode = node->left;
            delete node;
            --count;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    };

    // 删除任意节点
    // 下面以右子树最小值为例
    // 还可以以左子树最大节点来构造
    Node *remove(Node *node, Key key) {
        if (node == nullptr) return nullptr;
        if (key < node->key) {
            node->left = removeMin(node->left, key);
            return node;
        } else if (key > node->key) {
            node->right = remove(node->right, key);
            return node;
        } else {
            if (node->left == nullptr) {
                Node *rightNode = node->right;
                delete node;
                --count;
                return rightNode;
            }
            if (node->right == nullptr) {
                Node *leftNode = node->left;
                delete node;
                --count;
                return leftNode;
            }
            Node *nodeMin = new Node(minimum(node->right));
            ++count;
            nodeMin->right = removeMin(node->right); // 里面对count--，相当于没减
            // minimum返回最小值的指针，而removeMin又把最小值的给删除了，
            // 导致nodeMin指向失败，成为野指针，为此需要重新构造一个（new）
            nodeMin->left = node->left;
            delete node;
            --count;
            return nodeMin;
        }
    };
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

template<typename Key, typename Value>
void BST<Key, Value>::preorder() const {
    preorder(root);
}

template<typename Key, typename Value>
void BST<Key, Value>::preorder(BST::Node *node) const {
    if (node == nullptr) {
        std::cout << std::endl;
        return;
    }
    std::cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
}

template<typename Key, typename Value>
void BST<Key, Value>::inorder() const {
    inorder(root);
}

template<typename Key, typename Value>
void BST<Key, Value>::inorder(BST::Node *node) const {
    if (node) {
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }
    std::cout << std::endl;
}

template<typename Key, typename Value>
void BST<Key, Value>::postorder() const {
    postorder(root);
}

template<typename Key, typename Value>
void BST<Key, Value>::postorder(BST::Node *node) const {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->key << " ";
    }
    std::cout << std::endl;
}

template<typename Key, typename Value>
BST<Key, Value>::~BST() {
    destroy(root);
}

template<typename Key, typename Value>
void BST<Key, Value>::destroy(BST::Node *node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
        count--;
    }
}

template<typename Key, typename Value>
void BST<Key, Value>::levelOrder() const {
    levelOrder(root);
}

template<typename Key, typename Value>
void BST<Key, Value>::levelOrder(BST::Node *node) const {
    if (node) {
        std::queue<BST::Node *> q;
        q.push(node);
        while (!q.empty()) {
            Node *cur = q.front();
            std::cout << cur->key << " ";
            q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    std::cout << std::endl;
}

template<typename Key, typename Value>
Key BST<Key, Value>::minimum() const {
    assert(count);
    Node *node = minimum(root);
    return node->left;
}

template<typename Key, typename Value>
Key BST<Key, Value>::maximum() const {
    assert(count);
    Node *node = maximum(root);
    return node->key;
}

template<typename Key, typename Value>
void BST<Key, Value>::removeMin() {
    if (root)
        root = removeMin(root);
}

template<typename Key, typename Value>
void BST<Key, Value>::removeMax() {
    if (root)
        root = removeMax(root);
}

template<typename Key, typename Value>
void BST<Key, Value>::remove(Key key) {
    root = remove(root, key);
}


#endif //DAY10_BST_H