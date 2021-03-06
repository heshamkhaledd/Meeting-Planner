#ifndef _BST_HPP
#define _BST_HPP

#include <iostream>
#include <string>
#include <assert.h>
#include <fstream>
#include <sstream>

using namespace std;

class TreeNode {
public:
    TreeNode();
    int     compareNodes(int Day, int Hour);
    string   meetingTitle;
    int      meetingDay;
    int      meetingHour;
    TreeNode* leftChild;
    TreeNode* rightChild;

};

class BST {
private:
    TreeNode* Root;
    TreeNode* recursiveInsert(TreeNode* node, const string Title, const int Day, const int Hour, bool &flag);
    TreeNode* privateSearch (const int Day, const int Hour);
    TreeNode* privateDelete (TreeNode* node, const int Day, const int Hour, bool &flag);
    void recursivePrint (TreeNode* node);
    void recursiveDestroy(TreeNode* node);
public:
    BST();
    ~BST();
    bool    isEmpty()  const;
    string  Insert(string Title, int Day, int Hour);
    string  Delete(const int  Day, const int Hour);
    string  Search(const int Day, const int Hour);
    string  Modify(const string Title, const int Day, const int Hour);
    void    Print();

};

#endif