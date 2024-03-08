#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdexcept>
#include "BinaryNode.h"

template <class T>
class BinaryTree {
protected:
    BinaryNode<T> *root;


    int heightAux(BinaryNode<T>* node) const;
    int sizeAux(BinaryNode<T>* node) const;
    void destroyTree(BinaryNode<T>* node);
    void preOrderAux(BinaryNode<T>* node) const;
    void inOrderAux(BinaryNode<T>* node) const;
    void postOrderAux(BinaryNode<T>* node) const;
    void levelOrderAux(BinaryNode<T>* node) const;
    BinaryNode<T>* insertAux(BinaryNode<T>* node, const T& val);
    BinaryNode<T>* searchAux(BinaryNode<T>* node, const T& val) const;
    BinaryNode<T>* removeAux(BinaryNode<T>* node, const T& val, bool &found);

public:
    BinaryTree() : root(nullptr) {BinaryTree();}


    bool empty() const;
    T& getRoot() const;
    int height() const;
    int size() const;
    bool insert(const T& val);
    bool remove(const T& val);
    bool search(const T& val) const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    void levelOrder() const;
};

#include "BinaryTree.cpp"

#endif
