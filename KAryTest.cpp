#include <cassert>

#include "KAry.cpp"


int main() {
    
    { // test constructor
        KAryTree<int, 3> tree;

        assert(tree.maxNodes() == 3);
    }

    return 0;
}