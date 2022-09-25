#ifndef BST_Class_implementation
#define BST_Class_implementation
#include "BST_node.h"
#include <queue>
#include <stack>

class BST
{
public:
    BST_node *root;
    int max_height;
    void get_height(int h, BST_node *n);
    BST(void);
    void Insert(int Info);
    int count_node(void);
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
    h = 0;
    std::queue<BST_node *> nodeQueue;

    nodeQueue.push(n);
    nodeQueue.push(NULL);

    while(!nodeQueue.empty()){
        BST_node *tmp = nodeQueue.front();
        nodeQueue.pop();

        if(tmp == NULL){
            h = h + 1;
        }

        if(tmp != NULL){
            if(tmp -> left != NULL){
                nodeQueue.push(tmp -> left);
            }
            if(tmp -> right != NULL){
                nodeQueue.push(tmp -> right);
            }
        }
        else if(!nodeQueue.empty()){
            nodeQueue.push(NULL);
        }
    }
    max_height = h;
}

//*******************************************
// Copy this method from previous problems
//*******************************************
void BST::Insert(int Info)
{
    if(root == NULL){
        root = new BST_node(Info);
        return;
    }

    BST_node *tmp = root;
    BST_node *curr;
    while(tmp != NULL){
        curr = tmp;
        if(tmp -> info > Info){
            tmp = tmp -> left;
        }
        else{
            tmp = tmp -> right;
        }
    }

    if(curr -> info > Info){
        curr -> left = new BST_node(Info);
    }
    else{
        curr -> right = new BST_node(Info);
    }
}

//******************************
// Implement this method
//******************************
int BST::count_node()
{
    int count = 0;
    BST_node *tmpRoot = root;

    if(tmpRoot == 0){
        return 0;
    }
    else{
        std::stack<BST_node *> nodeStack;
        BST_node *tmp;
        nodeStack.push(tmpRoot);

        while(!nodeStack.empty()){
            tmp = nodeStack.top();
            count ++;
            nodeStack.pop();

            if(tmp -> left){
                nodeStack.push(tmp -> left);
            }
            if(tmp -> right){
                nodeStack.push(tmp -> right);
            }
        }
    }
    return count;
}

//*******************************
// To make your tree, insert
// the nodes of the tree in this
// method
//*******************************
void BST::MakeTree(void)
{
    //10 25 5 12 20 2 8 40 1
    Insert(10);
    Insert(25);
    Insert(12);
    Insert(20);
    Insert(2);
    Insert(8);
    Insert(40);
    Insert(1);
}
#endif