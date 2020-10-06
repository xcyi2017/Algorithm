//
// Created by xcy on 2020/9/29.
//

#include "tree.h"
#include <queue>

void Tree::add(int x) {
    Node *node = new Node(x);
    if (!root) root = node;
    else {
        std::queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            else {
                cur->left = node;
                break;
            }
            if (cur->right)
                q.push(cur->right);
            else {
                cur->right = node;
                break;
            }
        }
    }


}

void Tree::print() const {

    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        std::cout << node->val << " ";
        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    std::cout << std::endl;
}



