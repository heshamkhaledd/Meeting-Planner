#include "../inc/bst.hpp"

using namespace std;

int main()
{
    BST myBST;

    myBST.Insert("Cinema", 5, 10);
    myBST.Insert("Food", 4, 10);
    myBST.Insert("Friends", 100, 11);
    myBST.Insert("Bathroom", 6, 10);

    string str = myBST.Search(5,10);
    string str2= myBST.Modify("Test",5,100);
    str = myBST.Search(5,10);
    cout<<str<<endl<<str2<<endl;

    return 0;
}