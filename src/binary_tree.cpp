#include "../inc/binary_tree.hpp"
using namespace std;

Node::Node() {

    this->leftChild = NULL;
    this->rightChild = NULL;
}

bool BST::isEmpty() const {
    return (this->Root == NULL? true:false);
}

int Node::compareNodes(const Node * const node) {
    
}

void BST::Recursive_Insert (Node * node, const string Title, const int Day, const int Hour) {

        if (node == NULL) {              // Check if the node is already empty  
            node-> leftChild = new Node;
            node-> rightChild = new Node;

            assert((node-> leftChild != NULL) && (node-> rightChild != NULL));
            
            node-> meetingTitle = Title;
            node-> meetingDay = Day;
            node-> meetingHour = Hour;
    }
    else if (node->compareNodes(node->leftChild) == 1) Recursive_Insert(node->leftChild, Title, Day, Hour);
        
    else Recursive_Insert(node->rightChild,Title,Day,Hour);

}

void BST::Insert(const string Title,const int Day, const int Hour) {

    Recursive_Insert(Root,Title,Day,Hour);
    return;
}