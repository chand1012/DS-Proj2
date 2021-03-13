// This contains function definitions.

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using std::cout;
using std::endl;

#include "KAry.hpp"

// struct constructor
template <class T, uint K>
Node<T, K>::Node() {
    children.fill(nullptr);
}

// class constructor
template <class T, uint K>
KAryTree<T, K>::KAryTree() {}

// gets the number of children that the node has
// template <class T, uint K>
// uint KAryTree<T, K>::getNumberOfChildren(T input) {
//     uint count = 0;
//     for (uint i = 0; i < root.children.size(); ++i) {
//         std::unique_ptr<T> item = root.children.at(i);
//         if (item != nullptr) {
//             ++count;
//         }
//     }
//     return count;
// }

template <class T, uint K>
std::unique_ptr<Node<T, K>> findRootNode(T input) {
    
}

template <class T, uint K>
void insertNewNode(NODE_PTR node, NODE_PTR newNode) {
    // get the input value back from
    // the new node
    T input = newNode->value;
    cout << "Input " << input << endl;
    // if the input is greater than the node
    if (input > node->value) {
        cout << "Input greater than value " << node->value << endl;
        // loops starting from the right child
        for (uint i = K-1; i >= 0; --i) {
            // initialzes child node for comparisons
            NODE_PTR child = (node->children)[i];
            if (child == nullptr) {
                cout << "Child " << i << " is nullptr\n";
                // set child to new node and 
                // end recursion
                (node->children)[i] = newNode;
                cout << (node->children)[i]->value << endl;
                return;
            }
            else if (input > child->value) {
                // continue recursion into child
                cout << "Child is less than input\n"; 
                insertNewNode(child, newNode);
                break;
            }
            // edge case: If all values are greater than the input
            else if (input < child->value && i == 0){
                cout << "Input is less than all children\n";
                // copy the left-most child value into a new node
                NODE_PTR newChildNode(new Node<T, K>);
                newChildNode->value = child->value;
                
                // set the child's value to the new node's value
                child->value = newNode->value;

                // continue recursion with the new child node
                // as if it is an input
                insertNewNode(child, newChildNode);
                break;
            }
        }
    // if the input is less than or equal to node's value
    } else {
        cout << "Input is less than or equal to node" << endl;
        for (uint i = 0; i < K; ++i) {
            // initialzes child node for comparisons
            NODE_PTR child = (node->children)[i];
            if (child == nullptr) {
                cout << "Child " << i << " is nullptr\n";
                // set child to new node and 
                // end recursion
                (node->children)[i] = newNode;
                return;
            }
            else if (input < child->value) {
                cout << "Child is greater than input\n";
                // continue recursion
                insertNewNode(child, newNode);
                break;
            }
            // edge case: If all values are less than the input
            else if (input > child->value && i == K-1) {
                cout << "Input is greater than all children\n";
                // copy the right-most child value into a new node
                NODE_PTR newChildNode(new Node<T, K>);
                newChildNode->value = child->value;
                
                // set the child's value to the new node's value
                child->value = newNode->value;

                // continue recursion with the new child node
                // as if it is an input
                insertNewNode(child, newChildNode);
                break;
            }
        }
    }
}

// insert a node into the tree
template <class T, uint K>
void KAryTree<T, K>::insertNode(T input) {
    NODE_PTR newNode(new Node<T, K>);
    newNode->value = input;
    if (root == nullptr) {
        root = newNode;
        return;
    }

    insertNewNode<T, K>(root, newNode);
}
// finds the root of the given node

// combines two nodes

// get the max number of nodes
template <class T, uint K>
const uint KAryTree<T, K>::maxNodes() {
    return K;
}

template <class T, uint K>
void printNode(NODE_PTR node) {
    
    if (node == nullptr) {
        return;
    }
    
    for (uint i = 0; i < K; ++i) {
        printNode(node->children[i]);
    }
    cout << node->value << endl;
}

template <class T, uint K>
void KAryTree<T, K>::printTree() {
    printNode(root);
}