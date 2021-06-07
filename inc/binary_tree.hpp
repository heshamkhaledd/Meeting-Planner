#ifndef _BINARY_TREE_HPP
#define _BINARY_TREE_HPP

#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Node{
    public:
        string   meetingTitle;
        int      meetingDay;
        int      meetingHour;
        Node *   leftChild;
        Node *   rightChild;
        int     compareNodes(const Node * const node);
        Node();
};


class BST {
    private:
        Node * Root;
        void Recursive_Insert(Node * node, const string Title, const int Day, const int Hour);
    public:
        bool    isEmpty()  const;
        void    Insert     (string Title, int Day, int Hour);
        void    makeLeft   (Node * Tree);
        void    makeRight  (Node * Tree);
        void    Delete     (const Node data);
        string  Search     (int Day, int Hour);
        void    Modify     (const string Title, const int Day, const int Hour);
        void    Print      (); 

};

#endif