#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
using namespace std;

class Item {
public:
    int value;        
};

class Node {
public:
    Node *left;
    Node *right;
    Item item;
    int  weight;
};

class Tree {
public:
    Node *initialize();                                           // root of the tree          obs: to return a Null Ptr from a function, it must be a Ptr function too
    void insertValue(Node **node, Item requestedValue);           // insert some requested int value on tree
    void removeValue(Node **node, Node **f, Item requestedValue); // remove ....  .......  ...  ...  from tree
    void nextChild(Node **node, Node *temp);                      // chose left child to verification and point to the most deeper right branch on the sequence to swap (it could do the opposite)
    void search(Node **node, Node **temp, Item requestedValue);   // search for an exclusive value on the tree
    int  getWeight(Node **node);                                  // return the current weight of each child or -1 if the children are NULL
    int  maxHeight(int left, int right);                          // get the most deep node -> the max height of tree
    void rebalance(Node **node);
    void singleRightRotation(Node **node);
    void singleLeftRotation(Node **node);
    void doubleRightRotation(Node **node);
    void doubleLeftRotation(Node **node);


    void preOrderPrint(Node *node);                               // print the PreOrder tree
    void inOrderPrint(Node *node);                                //  ...  ... InOrder   ..
    void postOrderPrint(Node *node);                              //  ...  ... PostOrder ..
};

#endif