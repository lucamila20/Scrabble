#ifndef BINARYNODE_H
#define BINARYNODE_H

template <class T>
class BinaryNode {
protected:
    T data;
    BinaryNode<T> *leftChild;
    BinaryNode<T> *rightChild;

public:
    BinaryNode();
    BinaryNode(const T& value);
    ~BinaryNode();

    T& getData();
    void setData(const T& value);

    BinaryNode<T>* getLeftChild() const;
    void setLeftChild(BinaryNode<T> *left);

    BinaryNode<T>* getRightChild() const;
    void setRightChild(BinaryNode<T> *right);
};

#include "BinaryNode.cpp"

#endif
