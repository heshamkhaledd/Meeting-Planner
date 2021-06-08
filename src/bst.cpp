#include "../inc/bst.hpp"
using namespace std;

TreeNode::TreeNode() {

    this->leftChild = NULL;
    this->rightChild = NULL;
}

BST::BST() {
        this->Root = NULL;
}

bool BST::isEmpty() const {
    return (this-> Root == NULL ? true : false);
}

int TreeNode::compareNodes(int Day, int Hour) {
    if (Day <= this->meetingDay) {
        if (Day < this->meetingDay)
            return -1;
        else {
            if (Hour <= this->meetingHour) {
                if (Hour < this->meetingHour)
                    return -1;
                else
                    return 0;
            }
            else
                return 1;
        }
    }
    else
        return 1;

}

TreeNode* BST::recursiveInsert(TreeNode* node, const string Title, const int Day, const int Hour, bool &flag) {
    if (node == NULL) {
        node = new TreeNode;
        assert(node != NULL);
        node->meetingTitle = Title;
        node->meetingDay = Day;
        node->meetingHour = Hour;
        flag = true;
    }
    else {
        int temp = node->compareNodes(Day, Hour);
        if (temp == -1) 
            node->leftChild = recursiveInsert(node->leftChild, Title, Day, Hour, flag);
            
        else if (temp == 1)
            node->rightChild = recursiveInsert(node->rightChild, Title, Day, Hour, flag);

        else flag = false;
    }
    return node;
}

bool BST::Insert(const string Title, const int Day, const int Hour) {

    bool flag = false;
    if (Root == NULL)
        Root = recursiveInsert(Root, Title, Day, Hour,flag);
    else
        recursiveInsert(Root, Title, Day, Hour, flag);

    return flag;
}

TreeNode* BST::privateSearch (const int Day, const int Hour) {

        TreeNode * searchPtr = Root;
        while (searchPtr != NULL) {
            if (searchPtr->compareNodes(Day,Hour) == -1)
                searchPtr = searchPtr->leftChild;
            else if(searchPtr->compareNodes(Day,Hour) == 1)
                searchPtr = searchPtr->rightChild;
            else
                return (searchPtr);
        }
        return(searchPtr);

}

string BST::Search(const int Day, const int Hour) {

    if (this->isEmpty())
        return ("Empty " + to_string(Day) + " " + to_string(Hour));
    else{ 
        TreeNode * searchPtr = this-> privateSearch(Day,Hour);
        if (searchPtr == NULL)
            return ("Empty " + to_string(Day) + " " + to_string(Hour));
        else
            return searchPtr->meetingTitle;
    }
}

string BST::Modify(const string Title, const int Day, const int Hour) {

    TreeNode * searchPtr = this-> privateSearch(Day,Hour);
    if (searchPtr != NULL){
            searchPtr->meetingTitle = Title;
            return(to_string(searchPtr->meetingDay)+ " " + to_string(searchPtr->meetingHour));
    }
    else
        return ("Empty " + to_string(Day) + " " + to_string(Hour));
}


TreeNode* BST::privateDelete (TreeNode* node, const int Day, const int Hour, bool &flag) {

    if (node == NULL)
        return node;

    else if (node->compareNodes(Day,Hour) == -1)
        node->leftChild = this-> privateDelete(node->leftChild, Day, Hour, flag);

    else if (node->compareNodes(Day,Hour) == 1)
       node->rightChild  = this->privateDelete(node->rightChild, Day, Hour, flag);

    else{
        if (node->leftChild == NULL && node->rightChild == NULL) {
            delete node;
            node = NULL;
            flag = true;
            return node;
        }

        else if (node->leftChild == NULL || node->rightChild == NULL) {
                if (node->leftChild == NULL) {
                    TreeNode* tempPtr= node;
                    node = node->rightChild;
                    delete tempPtr;
                    flag = true;
                    return node; 
                }

                else {
                    TreeNode* tempPtr = node;
                    node = node->leftChild;
                    delete tempPtr;
                    flag = true;
                    return node;
                }
        }
        else{
            TreeNode* tempPtr = node->rightChild;

            while (tempPtr->leftChild != NULL && tempPtr->leftChild->leftChild != NULL)
                tempPtr = tempPtr->leftChild;

            
            TreeNode* tempPtrParent = tempPtr;
            tempPtr = tempPtr->leftChild;

            node-> meetingTitle = tempPtr-> meetingTitle;
            node-> meetingDay = tempPtr-> meetingDay;
            node-> meetingHour = tempPtr-> meetingHour;
            
            tempPtrParent->leftChild = privateDelete(tempPtr, tempPtr-> meetingDay, tempPtr-> meetingHour, flag);
        }
    }
    return node;
}

bool BST::Delete(const int Day, const int Hour) {

    bool flag = false;

    this-> privateDelete(Root,Day, Hour, flag);
    return flag;
}

void BST::Print() {
    recursivePrint(Root);
}