// This contains function definitions.

#include <limits>

#include "KAry.hpp"

#define UINT_MAX numeric_limits<uint>::max()

using namespace std;

// constructor
template <uint n>
KAryTree<n>::KAryTree(uint k) : k(k) {
    // fills all nodes with infinity
    // used for comparison
    nodes.fill(UINT_MAX);
}

template <uint n>
uint KAryTree<n>::getNumberOfChildren(uint input) {
    uint children = 0;
    for (uint i = input; i < input+3; ++i) {
        if (nodes[i] != UINT_MAX) {
            ++children;
        }
    }
    return children;
}

// finds the root of the given node
template <unsigned int n>
uint KAryTree<n>::findRootNode(uint input) {
    while (nodes[input] != UINT_MAX) {
        input = nodes[input];
    }
    return input;
}

// combines two nodes
