#include <cassert>
#include <cstdlib>

#include "KAry.cpp"


int main() {
    
    { // test constructor
        KAryTree<int, 3> tree;

        assert(tree.maxNodes() == 3);
    }

    { // test insert
        KAryTree<int, 3> tree;

        tree.insertNode(5);
        tree.insertNode(4);
        tree.insertNode(34);

        cout << "Now printing.\n";
        tree.printTree();

        assert(true);
    }

    { // test a lot of inserts

        KAryTree<int, 3> othertree;

        cout << "Starting the new loop!\n";

        for (uint i = 0; i < 100; ++i) {
            cout << "just inserted " << i << endl << endl;
            othertree.insertNode(i);
        }

        cout << "Now printing.\n";
        othertree.printTree();

    }

    { // test a lot of inserts

        KAryTree<int, 3> othertree;

        cout << "Starting the new loop!\n";

        for (uint i = 100; i > 0; --i) {
            cout << "just inserted " << i << endl << endl;
            othertree.insertNode(i);
        }

        cout << "Now printing.\n";
        othertree.printTree();

    }

    { // test a lot of inserts

        KAryTree<int, 10> othertree;

        cout << "Starting the new loop!\n";

        for (uint i = 0; i < 100; ++i) {
            cout << "just inserted " << i << endl << endl;
            othertree.insertNode(i);
        }

        cout << "Now printing.\n";
        othertree.printTree();

    }

    { // random test
    
        KAryTree<int, 10> othertree;

        cout << "Starting the new loop!\n";

        for (uint i = 0; i < 100; ++i) {
            int r = std::rand() % 100;
            othertree.insertNode(r);
        }

        cout << "Now printing.\n";
        othertree.printTree();

    }

    return 0;
}