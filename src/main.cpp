#include "../inc/bst.hpp"

using namespace std;

int main()
{
    BST myBST;

    myBST.Insert("Cinema", 5, 10);
    myBST.Insert("Food", 4, 10);
    myBST.Insert("Friends", 100, 11);
    myBST.Insert("Bathroom", 6, 10);
    bool flag = myBST.Delete(100,10);
    if (flag)
        cout<<"Done\n";
    else
        cout<<"Didn't find it\n";
    return 0;
}