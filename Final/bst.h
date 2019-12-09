#include <iostream>
#include <string>
#include <algorithm>

template<class T>

struct Node {
    T data;
    Node<T>* lTree;
    Node<T>* rTree;
};
class BST
{
  private:
    Node<T> *root;
    int nodeCount;
    
    Node<T>* find(Node<T> *p, const T& K) const {
        if (p == nullptr) return nullptr;
        if (K == p->data)
            return p;
        else if (K < p->data)
            return find(p->lTree, K);
        else 
            return find(p->rTree, K);
    }
    
    void insert(Node<T>* &p, Node<T> *newNode) {
        if (p == nullptr) {
            p = newNode;
            this->nodeCount++;
        }
        else {
            if (newNode->data <= p->data)
                insert(p->lTree, newNode);
            else
                insert(p->rTree, newNode);
        }
    }
    
  public:
    BST() {
        this->root = nullptr;
        this->nodeCount = 0;
    }

    Node<T>* find(const T& key) {
        return find(this->root, key);
    }
    void insert(const T& key) {
        Node<T> *node = new Node<T>;
        node->data = key;
        node->lTree = nullptr;
        node->rTree = nullptr;
        insert(this->root, node);
    }
};