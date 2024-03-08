#include "BinaryTree.h"
#include <queue>
#include <iostream>



template <class T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}


template <class T>
BinaryTree<T>::~BinaryTree() {
    destroy(root);
}

template <class T>
void BinaryTree<T>::destroy(BinaryNode<T>* node) {
    if (node) {
        destroy(node->getLeftChild());
        destroy(node->getRightChild());
        delete node;
    }
}


template <class T>
bool BinaryTree<T>::empty() const {
    return root == nullptr;
}


template <class T>
T& BinaryTree<T>::getRoot() const {
    if (empty()) {
        throw std::runtime_error("The tree is empty");
    }
    return root->getData();
}


template <class T>
bool BinaryTree<T>::insert(const T& val) {
    root = insert(root, val);
    return true;
}

template <class T>
BinaryNode<T>* BinaryTree<T>::insert(BinaryNode<T>* node, const T& val) {
if (!node) {
return new BinaryNode<T>(val);
}
if (val < node->getData()) {
node->setLeftChild(insert(node->getLeftChild(), val));
} else {
node->setRightChild(insert(node->getRightChild(), val));
}
return node;
}


template <T>
bool BinaryTree<T>::search(const T& val) const {
    return search(root, val);
}

template <class T>
bool BinaryTree<T>::search(BinaryNode<T>* node, const T& val) const {
if (!node) {
return false;
}
if (val == node->getData()) {
return true;
}
return search(node->getLeftChild(), val) || search(node->getRightChild(), val);
}

void BinaryTree<T>::preOrder() const {
    preOrder(root);
    std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::preOrder(BinaryNode<T>* node) const {
if (node) {
std::cout << node->getData() << " ";
preOrder(node->getLeftChild());
preOrder(node->getRightChild());
}
}

template <class T>
void BinaryTree<T>::inOrder() const {
    inOrder(root);
    std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::inOrder(BinaryNode<T>* node) const {
if (node) {
inOrder(node->getLeftChild());
std::cout << node->getData() << " ";
inOrder(node->getRightChild());
}
}

template <class T>
void BinaryTree<T>::postOrder() const {
    postOrder(root);
    std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::postOrder(BinaryNode<T>* node) const {
if (node) {
postOrder(node->getLeftChild());
postOrder(node->getRightChild());
std::cout << node->getData() << " ";
}
}

template <class T>
void BinaryTree<T>::levelOrder() const {
    if (root == nullptr) return;

    std::queue<BinaryNode<T>*> queue;
    queue.push(root);

    while (!queue.empty()) {
        BinaryNode<T>* node = queue.front();
        queue.pop();

        std::cout << node->getData() << " ";

        if (node->getLeftChild() != nullptr) {
            queue.push(node->getLeftChild());
        }
        if (node->getRightChild() != nullptr) {
            queue.push(node->getRightChild());
        }
    }
    std::cout << std::endl;
}

BinaryTree<int>;
BinaryTree<std::string>;