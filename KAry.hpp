// Initial structure for the K-Ary Tree
// Will be using an array as the base data structure.

#include <array>

using namespace std;

template <uint n>
class KAryTree {
    private:
        // stores the max number of children
        const uint k;
        // stores the current height of the tree
        uint h;
        
        array<uint, n> nodes;
            
    public: 
        // constructor and destructor
        KAryTree(uint k);
        ~KAryTree() {};
        // inserts a node to the tree
        void insertNode(uint input);
        // finds the root of the input
        uint findRootNode(uint input);
        // gets the number o
        uint getNumberOfChildren(uint input);
        // combines two nodes
        void unionNodes(uint x, uint y);
        // removes the lowest node and returns the value
        uint popNode();
        // removes the given node and returns if it was found
        bool removeNode(uint input);

};