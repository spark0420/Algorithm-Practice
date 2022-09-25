#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class BST_node{
    public:
        BST_node *left;
        BST_node *right;
        int info;

        BST_node(){
            left = 0;
            right = 0;
        }

        BST_node(int i){
            info = i;
            left = 0;
            right = 0;
        }
};

class BST_Tree{
    public: 
        BST_node *root;
        vector<int> preorder_output;
        vector<int> inorder_output;
        vector<int> postorder_output;

        BST_Tree(){
            root = 0;
        }

        void recur_preorder(BST_node* node){

            if(node == NULL){
                return;
            }
            preorder_output.push_back(node -> info);

            recur_preorder(node -> left);
            recur_preorder(node -> right);

        }

        void recur_inorder(BST_node* node){

            if(node == NULL){
                return;
            }
            recur_inorder(node -> left);
            inorder_output.push_back(node -> info);
            recur_inorder(node -> right);

        }

        void recur_postorder(BST_node* node){

            if(node == NULL){
                return;
            }
            recur_postorder(node -> left);
            recur_postorder(node -> right);
            postorder_output.push_back(node -> info);

        }

        void iter_preorder(){
            BST_node *tmp = root;
            stack<BST_node * > preorder_st;

            if(tmp == NULL){
                return;
            }
            else{
                preorder_st.push(tmp);

                while(!preorder_st.empty()){
                    tmp = preorder_st.top();
                    preorder_st.pop();
                    preorder_output.push_back(tmp -> info);

                    if(tmp -> right != NULL){
                        preorder_st.push(tmp -> right);
                    }

                    if(tmp -> left != NULL){
                        preorder_st.push(tmp -> left);
                    }
                }
            }
        }

        void iter_inorder(){
            BST_node *tmp = root;
            stack<BST_node * > inorder_st;

            if(tmp == NULL){
                return;
            }else{
                while(tmp != NULL || !inorder_st.empty()){
                    while(tmp != NULL){
                        inorder_st.push(tmp);
                        tmp = tmp -> left;
                    }

                    tmp = inorder_st.top();
                    inorder_st.pop();

                    inorder_output.push_back(tmp -> info);
                    
                    tmp = tmp -> right;
                }
            }
        }

        void iter_postorder(){
            BST_node *tmp = root;
            stack<BST_node * > postorder_st1;
            stack<BST_node * > postorder_st2;

            if(tmp == NULL){
                return;
            }
            else{
                postorder_st1.push(tmp);

                while(!postorder_st1.empty()){
                    tmp = postorder_st1.top();
                    postorder_st1.pop();
                    postorder_st2.push(tmp);

                    if(tmp -> left != NULL){
                        postorder_st1.push(tmp -> left);
                    }

                    if(tmp -> right != NULL){
                        postorder_st1.push(tmp -> right);
                    }
                }

                while(!postorder_st2.empty()){
                    tmp = postorder_st2.top();
                    postorder_output.push_back(tmp -> info);
                    postorder_st2.pop();
                }
            }
        }

        void preorder_print(){
            int size = preorder_output.size();

            cout << "Preorder Traversal: ";
            for(int i = 0; i < size; i++){
                cout << preorder_output.at(i) << " -> ";
            }
            cout << "||" << endl;
        }

        void inorder_print(){
            int size = inorder_output.size();

            cout << "Inorder Traversal: ";
            for(int i = 0; i < size; i++){
                cout << inorder_output.at(i) << " -> ";
            }
            cout << "||" << endl;
        }

        void postorder_print(){
            int size = postorder_output.size();

            cout << "Postorder Traversal: ";
            for(int i = 0; i < size; i++){
                cout << postorder_output.at(i) << " -> ";
            }
            cout << "||" << endl;
        }

        int count_Right_Child(){
            BST_node *tmp = root;
            stack<BST_node * > rightChild_st;
            int count = 0;

            if(tmp == NULL){
                return 0;
            }
            else{
                rightChild_st.push(tmp);

                while(!rightChild_st.empty()){
                    tmp = rightChild_st.top();
                    rightChild_st.pop();

                    if(tmp -> right != NULL){
                        rightChild_st.push(tmp -> right);
                        count ++;
                    }

                    if(tmp -> left != NULL){
                        rightChild_st.push(tmp -> left);
                    }
                }
            }
            return count;
        }
        int get_height(){

            if(root == NULL){
                return 0;
            }

            int height = 0;
            std::queue<BST_node *> nodeQueue;
            nodeQueue.push(root);
            nodeQueue.push(NULL);

            while(!nodeQueue.empty()){
                BST_node *tmp = nodeQueue.front();
                nodeQueue.pop();

                if(tmp == NULL){
                    height++;
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
            return height;
}

//******************************
// Implement this method
//******************************
        int count_node(){
            int count = 0;
            BST_node *tmpRoot = root;

            if(tmpRoot == 0){
                return 0;
            }
            else{
                stack<BST_node *> nodeStack;
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

        int count_leaves(){
            int count = 0;
            BST_node *tmpRoot = root;

            if(tmpRoot == 0){
                return 0;
            }
            else{
                queue<BST_node *> nodeQueue;
                BST_node *tmp;
                nodeQueue.push(tmpRoot);

                while(!nodeQueue.empty()){
                    tmp = nodeQueue.front();
                    nodeQueue.pop();

                    if(tmp -> left){
                        nodeQueue.push(tmp -> left);
                    }
                    if(tmp -> right){
                        nodeQueue.push(tmp -> right);
                    }
                    if(tmp -> left == 0 && tmp -> right == 0){
                        count ++;
                    }
                }
            }
            return count;
        }

        void Insert(int Info){
            if(root == NULL){
                root = new BST_node(Info);
                cout << "Completed inserting(root) " << Info << endl;
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
            cout << "Completed inserting " << Info << endl;
        }
        
};

int main()
{
    BST_Tree Tree1;
    BST_Tree Tree2;

    Tree1.Insert(7);
    Tree1.Insert(9);
    Tree1.Insert(8);
    Tree1.Insert(4);
    Tree1.Insert(3);
    Tree1.Insert(6);
    Tree1.Insert(10);
    Tree1.Insert(15);

    Tree2.Insert(7);
    Tree2.Insert(9);
    Tree2.Insert(8);
    Tree2.Insert(4);
    Tree2.Insert(3);
    Tree2.Insert(6);
    Tree2.Insert(10);
    Tree2.Insert(15);

    cout << "\n-----------Iterative Traversal-----------\n\n";
    Tree1.iter_preorder();
    Tree1.preorder_print();

    cout << "\n";
    Tree1.iter_inorder();
    Tree1.inorder_print();

    cout << "\n";
    Tree1.iter_postorder();
    Tree1.postorder_print();

    cout << "\n-----------Recursive Traversal-----------\n\n";
    Tree2.recur_preorder(Tree2.root);
    Tree2.preorder_print();

    cout << "\n";
    Tree2.recur_inorder(Tree2.root);
    Tree2.inorder_print();
    
    cout << "\n";
    Tree2.recur_postorder(Tree2.root);
    Tree2.postorder_print();


    cout << "\n-----------Information about the BST-----------\n";
    int numRightChild = Tree1.count_Right_Child();
    cout << "The number of right child: " << numRightChild << endl;

    int numNodes = Tree1.count_node();
    cout << "The number of nodes: " << numNodes << endl;

    int numLeaves = Tree1.count_leaves();
    cout << "The number of leaves: " << numLeaves << endl;
    
    exit(0);
}