#include "tree.hpp"

Node* Tree::initialize() {
    return NULL;
}

void Tree::insertValue(Node **node, Item requestedValue) {    
    if (*node == NULL) {
        *node           = (Node*)malloc(sizeof(Node));
        (*node)->item   = requestedValue;
        (*node)->left   = NULL;
        (*node)->right  = NULL;
        (*node)->weight = 0;
    } else {
        if ((*node)->item.value > requestedValue.value) {
            insertValue(&(*node)->left, requestedValue);
            // unbalanced to the left
            if (getWeight(&(*node)->left) - getWeight(&(*node)->right) == 2) {
                if ((*node)->left->item.value > requestedValue.value) {
                    cout << "Single Right Rotation" << endl;
                    singleRightRotation(node);
                } else {
                    cout << "Double Right Rotation" << endl;
                    doubleRightRotation(node);
                }
            }
        } else if ((*node)->item.value < requestedValue.value) {
            insertValue(&(*node)->right, requestedValue);
            // unbalanced to the right
            if (getWeight(&(*node)->right) - getWeight(&(*node)->left) == 2) {
                if ((*node)->right->item.value < requestedValue.value)  {
                    cout << "Single Left Rotation" << endl;
                    singleLeftRotation(node);
                }
                else {
                    cout << "Double Left Rotation" << endl;
                    doubleLeftRotation(node);
                }
            }
        }
    }
    (*node)->weight = maxHeight(getWeight(&(*node)->left), getWeight(&(*node)->right)) + 1;
}

void Tree::rebalance(Node **node) {
	int balance;
  	int left = 0;
  	int right = 0;

	balance = getWeight(&(*node)->left) - getWeight(&(*node)->right);
	if((*node)->left)
		left = getWeight(&(*node)->left->left) - getWeight(&(*node)->left->right);
	if((*node)->right)
		right = getWeight(&(*node)->right->left) - getWeight(&(*node)->right->right);

	if(balance == 2 && left >= 0)
		singleRightRotation(node);
	else if(balance == 2 && left < 0)
		doubleRightRotation(node);

	else if(balance == -2 && right <= 0)
		singleLeftRotation(node);
	else if(balance == -2 && right > 0)
		doubleLeftRotation(node);
}

void Tree::removeValue(Node **node, Node **f, Item item){
	Node *temp;
  	
  	if (*node == NULL) {
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (item.value < (*node)->item.value){ removeValue(&(*node)->left, node, item); return;}
  	if (item.value > (*node)->item.value){ removeValue(&(*node)->right, node, item); return;}

  	if ((*node)->right == NULL) { 
  		temp = *node;  
  		*node = (*node)->left;
    	free(temp);
    	rebalance(f);
    	rebalance(node);
    	return;
  	}

  	if ((*node)->left != NULL) { 
  		nextChild(&(*node)->left, *node);
  		rebalance(f);
  		rebalance(node);
  		return;
  	}

  	temp = *node;  
  	*node = (*node)->right;
  	free(temp);
  	rebalance(f);
  	rebalance(node);
}

void Tree::nextChild(Node **node, Node *temp) {
    if ((*node)->right != NULL) {
        nextChild(&(*node)->right, temp);
        return;
    }
    temp->item = (*node)->item;
    temp       = (*node);
    *node      = (*node)->left;
    free(temp);
}

void Tree::search(Node **node, Node **temp, Item requestedValue) {
    if (*node == NULL) {
        cout << "[ERROR]: NODE NOT FOUND" << endl;
        return;
    } else if ((*node)->item.value > requestedValue.value) { 
        search(&(*node)->left, temp, requestedValue);
        return;
    } else if ((*node)->item.value < requestedValue.value) {
        search(&(*node)->right, temp, requestedValue);
        return;
    }
    *temp = *node;
}

int Tree::getWeight(Node **node) {
    if (*node == NULL)
        return -1;
    return (*node)->weight;
}

int Tree::maxHeight(int left, int right) {
    if (left > right)
        return left;
    return right;
}

void Tree::singleRightRotation(Node **node) {
    Node *temp;
    temp = (*node)->left;
    (*node)->left = temp->right;
    temp->right = (*node);
    (*node)->weight = maxHeight(getWeight(&(*node)->left), getWeight(&(*node)->right)) + 1;
    temp->weight = maxHeight(getWeight(&temp->left), getWeight(&temp->right)) + 1;
    (*node) = temp;
}

void Tree::singleLeftRotation(Node **node) {
    Node *temp;
    temp = (*node)->right;
    (*node)->right = temp->left;
    temp->left = (*node);
    (*node)->weight = maxHeight(getWeight(&(*node)->left), getWeight(&(*node)->right)) + 1;
    temp->weight = maxHeight(getWeight(&temp->left), getWeight(&temp->right)) + 1;
    (*node) = temp;
}

void Tree::doubleRightRotation(Node **node) {
    singleLeftRotation(&(*node)->left);
    singleRightRotation(node);
}

void Tree::doubleLeftRotation(Node **node) {
    singleRightRotation(&(*node)->right);
    singleLeftRotation(node);
}

void Tree::preOrderPrint(Node *node) {
    if (node != NULL) {
        cout << node->item.value << ":" << node->weight << "\t";
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
}

void Tree::inOrderPrint(Node *node) {
    if (node != NULL) {
        inOrderPrint(node->left);
        cout << node->item.value << " ";
        inOrderPrint(node->right);
    }
}

void Tree::postOrderPrint(Node *node) {
    if (node != NULL) {
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        cout << node->item.value << " ";
    }
}