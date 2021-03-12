// Initial structure for the K-Ary Tree
// Will be using an array as the base data structure.

#include <array>
#include <memory>

template <class T, uint K>
struct Node {
    T value;
    std::array<std::unique_ptr<Node>, K> children;
    // struct constructor
    Node();
};

template <class T, uint K>
class KAryTree {
    private:
        std::unique_ptr<Node<T, K>> root = nullptr;
    public: 
        // constructor and destructor
        KAryTree();
        ~KAryTree() {};
        // inserts a node to the tree
        void insertNode(T input);
        // finds the root of the input
        T findRootNode(T input);
        // gets the number o
        uint getNumberOfChildren(T input);
        // combines two nodes
        void unionNodes(T x, T y);
        // removes the lowest node and returns the value
        T popNode();
        // removes the given node and returns if it was found
        bool removeNode(T input);
        // get the max number of nodes
        const uint maxNodes();
};