#include <cstddef>
#include <iostream>

using namespace std;

class SLL_Node{
    public:
        int info;
        SLL_Node *next;

        SLL_Node() {
            next = NULL;
        }
        SLL_Node(int data, SLL_Node *n = NULL) {
            info = data;
            next = n;
        }

        void addToHead(SLL_Node **head, int new_key){
            SLL_Node* newNode = new SLL_Node();

            newNode-> info = new_key;

            newNode -> next = *head;

            *head = newNode;
        }

        void addToTail(SLL_Node **head, int new_key){
            SLL_Node* newNode = new SLL_Node;
            SLL_Node *tmpHead = *head;

            newNode -> info = new_key;
            newNode -> next = NULL;

            if(*head == NULL){
                *head = newNode;
                return;
            }
            while(tmpHead -> next != NULL){
                tmpHead = tmpHead-> next;
            }
            tmpHead -> next = newNode;
            return;
        }

        void insertAfter(SLL_Node *prevNode, int new_key){
            if(prevNode == NULL){
                cout << "The given previous node is empty.\n";
                return;
            }

            SLL_Node *newNode = new SLL_Node();
            newNode -> info = new_key;
            newNode -> next = prevNode-> next;
            prevNode -> next = newNode;
        }

        SLL_Node* deleteFromHead(SLL_Node *head){
            if(head == NULL){
                return NULL;
            }
            SLL_Node *tmpHead;

            while(head -> next != NULL){
                tmpHead = head;
                head = head -> next;
                delete tmpHead;
                //free(*tmpHead);
            }

            head = NULL;

            return head;
            
        }

        void deleteNode(SLL_Node **head, int pos){
            if(*head == NULL){
                cout << "The list is empty.\n";
                return;
            }

            SLL_Node *tmpHead = *head;

            if(pos == 0){
                *head = tmpHead -> next;
                free(tmpHead);
                cout << "The head node is deleted.\n";
                return;
            }
            for(int i = 0; tmpHead != NULL && i < pos-1; i++){
                tmpHead = tmpHead -> next;
            }
            if(tmpHead == NULL || tmpHead -> next == NULL){
                cout << "The node doesn't exist.\n";
                return;
            }

            SLL_Node *next = tmpHead -> next -> next;
            free(tmpHead -> next);
            tmpHead -> next = next;

            free(tmpHead);
            //return;
        }

        void isInList(SLL_Node **head, int search){
            
            SLL_Node *tmpHead = *head;

            while(tmpHead-> next != NULL){
                tmpHead = tmpHead -> next;
                if(tmpHead -> info == search){
                    cout << "The element is in the List\n";
                    return;
                }
            }
            free(tmpHead);
        }
        
        void PrintList(SLL_Node **head){

            SLL_Node *tmpHead = *head;

            while(tmpHead != NULL){
                cout << tmpHead -> info << "->";
                tmpHead = tmpHead-> next;
            }

        cout << "|||" << endl;
        }
        
        int getLength(SLL_Node *head){

            if(head == NULL){
                return 0;
            }
            else{
                head = head -> next;
                return 1 + getLength(head);
            }
        }
};
int main() {

    SLL_Node myNode;
    int key;

    SLL_Node *head1 = NULL;

    myNode.addToTail(&head1, 1);
    myNode.addToTail(&head1, 2);
    myNode.addToTail(&head1, 3);
    myNode.addToTail(&head1, 4);
    myNode.addToTail(&head1, 5);

    cout << "The List 1: ";
    myNode.PrintList(&head1);

    int count = myNode.getLength(head1);
    cout << "\nThe length of the list1: " << count << endl;

   exit(0);
  
}

