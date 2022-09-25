#include <iostream>

using namespace std;

class Heap_node{
    public:
        Heap_node *left;
        Heap_node *right;
        int info;

        Heap_node(){
            left = 0;
            right = 0;
        }

        Heap_node(int i){
            info = i;
            left = 0;
            right = 0;
        }
};

class maxHeap{
    public:

        void checkChildren(int *arr, int size, int pos){
            int nonleaf = (size / 2) - 1;
            int max = pos;

            if(pos <= nonleaf){
                if(pos * 2 + 1 < size && arr[max] < arr[pos * 2 + 1]){
                    max = pos * 2 + 1;
                }
                if(pos * 2 + 2 < size && arr[max] < arr[pos * 2 + 2]){
                    max = pos * 2 + 2;
                }
                if(max != pos){
                    int curr = arr[max];
                    arr[max] = arr[pos];
                    arr[pos] = curr;

                    checkChildren(arr, size, max);
                }
            }
        }

        void build_Heap(int *arr, int size){
            int nonleaf = (size / 2) - 1;

            for(int i = nonleaf; i >= 0; i--){
                checkChildren(arr, size, i);
            }
        }

        Heap_node* build_tree(int *arr, int size, Heap_node *root, int pos){
            
            if(pos < size){
                int data = arr[pos];
                Heap_node * tmp = new Heap_node(data);
                root = tmp;

                root -> left = build_tree(arr, size, root -> left, 2 * pos + 1);
 
                root->right = build_tree(arr, size, root -> left, 2 * pos + 2);
            }
            
            return root;
        }

        void recur_preorder(Heap_node* root){

            if(root == NULL){
                return;
            }
            cout << root -> info << " ";

            recur_preorder(root -> left);
            recur_preorder(root -> right);
        }

};
int main(){

    maxHeap myHeap;
    int heapArr[] = {2, 8, 6, 1, 10, 15, 3, 12, 11};
    int arrSize = sizeof(heapArr)/sizeof(int);

    cout << "Heap Array: ";
    myHeap.build_Heap(heapArr, arrSize);

    for(int i = 0; i < arrSize; i++){
        cout << heapArr[i] << ", ";
    }
    cout << endl;

    Heap_node* root;
    root = myHeap.build_tree(heapArr, arrSize, root, 0);

    cout << "Preorder of the tree: ";
    myHeap.recur_preorder(root);
    cout << endl;
}