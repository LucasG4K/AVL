#include "tree.hpp"

void TreeOperations(int *toInsert, int toInsertSize, int *toDelete, int toDeleteSize) {
    Tree tree;
    Node *node = tree.initialize();
    Item item;

    cout << "Showing insertion process: " << endl;
    for (int i = 0; i < toInsertSize; i++) {
        item.value = toInsert[i];
        cout << "Inserting the " << i + 1 << "º -> " << item.value << endl;
        tree.insertValue(&node, item);
        tree.preOrderPrint(node);
        cout << endl << "=================" << endl;
    }

    cout << endl << "Final Tree:" << endl << "PreOrder: ";
    tree.preOrderPrint(node);

    for (int i = 0; i < toDeleteSize; i++) {
        item.value = toDelete[i];
        tree.removeValue(&node, &node, item);
        cout << endl << "By removing " << item.value << ", the tree remains like: ";
        tree.preOrderPrint(node);
    }
}

int main() {
    // 1st tree
    cout << "1st tree" << endl;
    int vector1[] = {10,2,7,5,3,9,16,4,11,1,6,23,14};
    int toBeDeleted1[] = {10,5,4,11,6};
    int vectorSize = sizeof(vector1) / sizeof(int);
    int toBeDeletedSize = sizeof(toBeDeleted1) / sizeof(int);

    TreeOperations(vector1, vectorSize, toBeDeleted1, toBeDeletedSize);
    
    // 2nd tree
    cout << endl << endl << "=================" << endl;
    cout << "2nd tree" << endl;
    int vector2[] = {78,44,67,92,22,110,16,54,23,32,37};
    int toBeDeleted2[] = {};
    vectorSize = sizeof(vector2) / sizeof(int);
    toBeDeletedSize = sizeof(toBeDeleted2) / sizeof(int);
    
    TreeOperations(vector2, vectorSize, toBeDeleted2, toBeDeletedSize);

    return 0;
}

