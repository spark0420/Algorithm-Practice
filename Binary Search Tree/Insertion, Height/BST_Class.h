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
    int Height(void);
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
// It calls get_height only
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

//******************************
// Implement this method
//******************************
/*void BST::get_height(int h, BST_node *n)
{
    std::queue<BST_node *> currNodes;
    int height = -1;
    int nodeNums;

    currNodes.push(n);
    //currNodes.push(NULL);

    while(!currNodes.empty()){
        nodeNums = currNodes.size();

            height = height + 1;

            while(nodeNums > 0){
                BST_node *tmp = currNodes.front();
                currNodes.pop();

                if(tmp -> left != 0){
                    currNodes.push(tmp -> left);
                }
                if(tmp -> right != 0){
                    currNodes.push(tmp -> right);
                }
                nodeNums = nodeNums - 1;
            }
        }
}*/
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
//******************************
// Implement this method
//******************************
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

#endif