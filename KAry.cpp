// This contains function definitions.

#include <limits>

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

// insert a node into the tree
template <class T, uint K>
void KAryTree<T, K>::insertNode(T input) {
    std::unique_ptr<Node<T, K>> item = root;
    std::unique_ptr<Node<T, K>> temp;
    while (item != nullptr) {
        
    }

    
}

// finds the root of the given node

// combines two nodes

// get the max number of nodes
template <class T, uint K>
const uint KAryTree<T, K>::maxNodes() {
    return K;
}