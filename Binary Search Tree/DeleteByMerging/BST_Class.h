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
    void DeleteByMerging(int key);
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
void BST::DeleteByMerging(int key)
{
    BST_node *target = root;
    BST_node *prev = target;
    BST_node *tmp;

    if(root == NULL){
        return;
    }

    while(target != NULL && target -> info != key){
        prev = target;
        if(target -> info > key){
            target = target -> left;
        }
        else if(target -> info < key){
            target = target -> right;
        }
    }

    if(target -> info == key){
            if(target -> right){
                tmp = target -> right;

                while(tmp -> left){
                    tmp = tmp -> left;
                }

                if(target -> left){
                    if(prev-> info < key){
                        prev -> right = target -> right;
                    } 
                    else if(prev -> info > key){
                        prev -> left = target -> right;
                    }
                    else if(prev -> info == key){
                        root = target -> right;
                    }
                    tmp -> left = target -> left;
                    target -> right = NULL;
                    target -> left = NULL;
                }
                else{
                    if(prev -> info < key){
                        prev -> right = target -> right;
                    }
                    else if(prev -> info > key){
                        prev -> left = target -> right;
                    }
                    else if(prev -> info == key){
                        root = target -> right;
                    }
                    target -> right = NULL;
                }
            }
            else if(target -> left){
                if(prev -> info < key){
                    prev -> right = target -> left;
                }     
                else if(prev -> info > key){
                    prev -> left = target -> left;
                }
                else if(prev -> info == key){
                    root = target -> left;
                }
                target -> left = NULL;
            }
            else{
                if(prev -> info < key){
                    prev -> right = NULL;
                }     
                else if(prev -> info > key){
                    prev -> left = NULL;
                }
                else if(prev -> info == key){
                    root = NULL;
                }
            }
        }
        else{
            return;
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
}
#endif