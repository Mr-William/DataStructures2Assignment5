#ifndef NODE_H
#define NODE_H

//***********************************************************
//
//     File:          Node.h
//
//     Description:   Definition of Node class.
//
//***********************************************************

template <typename T>
struct Node {
    T value;
    double frequency;
    Node<T>* left;
    Node<T>* right;
};

#endif
