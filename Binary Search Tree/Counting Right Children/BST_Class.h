#ifndef BST_Class_implementation
#define BST_Class_implementation
#include "BST_node.h"

class BST
{
public:
    BST_node *root;
    int max_height;
    void get_height(int h, BST_node *n);
    BST(void);
    void Insert(int Info);
    int count_right_children(void);
    int Height(void);
    void MakeTree(void);
};

//******************************
// Do no touch this method!!
//******************************
BST::BST(void)
{
    root = 0;
}

//******************************
// Do no touch this method!!
//******************************
int BST::Height(void)
{
    BST_node *n;
    int h;

    h = 0;
    if (!root)
        return 0;
    else
    {
        n = root;
        max_height = 0;
        get_height(h, n);
    }
    return max_height;
}

//*******************************************
// Copy this method from previous problems
//*******************************************
void BST::get_height(int h, BST_node *n)
{
}

//*******************************************
// Copy this method from previous problems
//*******************************************
void BST::Insert(int Info)
{
}

//******************************
// Implement this method
//******************************
int BST::count_right_children()
{
}

//*******************************
// To make your tree, insert
// the nodes of the tree in this
// method
//*******************************
void BST::MakeTree(void)
{
    //10 25 5 12 20 2 8 40 1
    // Insert(10);
    // Insert(25);
    // Insert(12);
    // Insert(20);
    // Insert(2);
    // Insert(8);
    // Insert(40);
    // Insert(1);
}
#endif