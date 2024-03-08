#include "BinaryTree.h"

template <class T>
BinaryNode<T>::BinaryNode() : data(T()), leftChild(nullptr), rightChild(nullptr) {}

template <class T>
BinaryNode<T>::BinaryNode(const T& value) : data(value), leftChild(nullptr), rightChild(nullptr) {}

template <class T>
BinaryNode<T>::BinaryNode() {
    delete leftChild;
    delete rightChild;
}

template <class T>
T& BinaryNode<T>::getData() {
    return data;
}

template <class T>
void BinaryNode<T>::setData(const T& value) {
    data = value;
}

template <class T>
BinaryNode<T>* BinaryNode<T>::getLeftChild() const {
    return leftChild;
}

template <class T>
void BinaryNode<T>::setLeftChild(BinaryNode<T> *left) {
    leftChild = left;
}

template <class T>
BinaryNode<T>* BinaryNode<T>::getRightChild() const {
    return rightChild;
}

template <class T>
void BinaryNode<T>::setRightChild(BinaryNode<T> *right) {
    rightChild = right;
}

BinaryNode<int>;
BinaryNode<std::string>;
