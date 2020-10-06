//
// Created by xcy on 2020/10/6.
//

#ifndef DAY10_SEQUENCEST_H
#define DAY10_SEQUENCEST_H

template<typename Key, typename Value>
class SequenceST {
private:
    struct Node {
        Key key;
        Value value;
        Node *next;

        Node(Key key, Value value) : key(key), value(value), next(nullptr) {};
    };

    Node *root;
    int count;
public:

    SequenceST();

    ~SequenceST();

    int size() const;

    bool isEmpty() const;

    void insert(Key key, Value value);

    bool contain(Key key) const;

    Value *search(Key key) const;

};

template<typename Key, typename Value>
SequenceST<Key, Value>::SequenceST()
        :root(nullptr), count(0) {}

template<typename Key, typename Value>
SequenceST<Key, Value>::~SequenceST() {
    while (root) {
        Node *node = root;
        root = root->next;
        delete node;
    }
}

template<typename Key, typename Value>
int SequenceST<Key, Value>::size() const {
    return count;
}

template<typename Key, typename Value>
bool SequenceST<Key, Value>::isEmpty() const {
    return count == 0;
}

template<typename Key, typename Value>
void SequenceST<Key, Value>::insert(Key key, Value value) {
    Node *node = root;
    while (node) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    Node *newNode = new Node(key, value);
    newNode->next = root;
    root = newNode;
    ++count;
}

template<typename Key, typename Value>
bool SequenceST<Key, Value>::contain(Key key) const {
    Node *node = root;
    while (node) {
        if (node->key == key) return true;
        node = node->next;
    }
    return false;
}

template<typename Key, typename Value>
Value *SequenceST<Key, Value>::search(Key key) const {
    Node *node = root;
    while (node) {
        if (node->key == key) return &node->value;
        node = node->next;
    }
    return nullptr;
}


#endif //DAY10_SEQUENCEST_H
