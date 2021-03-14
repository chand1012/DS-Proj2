// Initial structure for the K-Ary Tree
// Will be using an array as the base data structure.

#include <array>
#include <memory>

#define NODE_PTR std::shared_ptr<Node<T, K>>

template <class T, uint K>
struct Node {
    T value;
    std::array<NODE_PTR, K> children;
    // struct constructor
    Node();
};

template <class T, uint K>
class KAryTree {
    private:
        NODE_PTR root;
    public: 
        // constructor and destructor
        KAryTree();
        ~KAryTree() {};
        // inserts a node to the tree
        void insertNode(T input);
        // get the max number of nodes
        const uint maxNodes();
        // print tree
        void printTree();
};