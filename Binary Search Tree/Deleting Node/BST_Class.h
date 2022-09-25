#ifndef BST_Class_implementation
#define BST_Class_implementation
#include "BST_node.h"
#include <queue>

class BST
{
public:
    BST_node *root;
    int max_height;
    void get_height(int h, BST_node *n);
    BST(void);
    void Insert(int Info);
    void DeleteByCopying(int key);
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
void BST::DeleteByCopying(int key)
{
    BST_node *target = root;
    BST_node *prev;
    BST_node *tmp;
    BST_node *prevTmp;

    if(root == NULL){
        return;
    }

    /*while(target -> info != key){
        prev = target;
        if(target -> info > key && target -> left){
            target = target -> left;
        }
        else if(target -> info < key && target -> right){
            target = target -> right;
        }
    }*/
    while(target != NULL && target -> info != key){
        prev = target;
        if(target -> info > key){
            target = target -> left;
        }
        else if(target -> info < key){
            target = target -> right;
        }
    }
if (target)
{
    if(target -> info == key){

        if(target -> left){
            tmp = target -> left;
        
            while(tmp -> right){
                prevTmp = tmp;
                tmp = tmp -> right;
            }

            if(tmp != target -> left){
                if(tmp -> left){
                    prevTmp -> right = tmp -> left;
                    target -> info = tmp -> info;
                    tmp -> left = NULL;
                    return;
                }
                else{
                    target -> info = tmp -> info;
                    prevTmp -> right = NULL;
                    return;
                }
            }else if(tmp == target -> left){
                if(tmp -> left){
                    target -> left = tmp -> left;
                    target -> info = tmp -> info;
                    tmp -> left = NULL;
                    return;
                }
                else{
                    target -> info = tmp -> info;
                    target -> left = NULL;
                }
            }
        }
        else if(target -> right){
            tmp = target -> right;

            while(tmp -> left){
                prevTmp = tmp;
                tmp = tmp -> left;
            }

            if(tmp != target -> right){
                if(tmp -> right){
                    prevTmp -> left = tmp -> right;
                    target -> info = tmp -> info;
                    tmp -> right = NULL;
                    return;
                }
                else{
                    target -> info = tmp -> info;
                    prevTmp -> left = NULL;
                    return;
                }
            }else if(tmp == target -> right){
                if(tmp -> right){
                    target -> right = tmp -> right;
                    target -> info = tmp -> info;
                    tmp -> right = NULL;
                    return;
                }
                else{
                    target -> info = tmp -> info;
                    target -> right = NULL;
                    return;
                }
            }
        }
        else{
            if(prev -> info > key){
                prev -> left = NULL;
            }
            else if(prev -> info < key){
                prev -> right = NULL;
            }
        }
    }
    else{
        return;
    }
    
}
    
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
    Insert(7);
    Insert(40);
    Insert(1);
    Insert(41);
    Insert(39);
    Insert(11);
    Insert(9);
    Insert(8);
    Insert(22);
    Insert(21);
}
#endif