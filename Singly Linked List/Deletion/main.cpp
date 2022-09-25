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

        bool areSame(SLL_Node **head1, SLL_Node **head2) {

            bool answer = true;
            SLL_Node *tmp1 = *head1;
            SLL_Node *tmp2 = *head2;

            if(tmp1 == NULL && tmp2 == NULL){
                cout << "The lists are empty.\n";
                answer = false;
                return answer;
            }
            if(tmp1 == NULL || tmp2 == NULL){
                cout << "One of the list is empty.\n";
                answer = false;
                return answer;
            }

            while(tmp1 != NULL && tmp2 != NULL){
                if(tmp1 -> info != tmp2 -> info){
                    answer = false;
                    return answer;
                }
                tmp1 = tmp1 -> next;
                tmp2 = tmp2 -> next;
            }
            if(tmp1 != NULL || tmp2 != NULL){
                answer = false;
                return answer;
            }

            return answer;
        }

        void reverse(SLL_Node **head){
            SLL_Node *tmp = *head;
            SLL_Node *prev = NULL;
            SLL_Node *future = NULL;
            

            if(tmp == NULL){
                cout << "The list is empty.\n";
                return;
            }
            if(tmp -> next == NULL){
                return;
            }
            
            while(tmp != NULL){
                future = tmp -> next;
                tmp -> next = prev;
                prev = tmp;
                tmp = future;
            }
            *head = prev;

        }
        void attachList(SLL_Node **head1, SLL_Node **head2){
            SLL_Node *tmp = *head1;
            SLL_Node *tmp2 = *head2;
            
            if(tmp == NULL && tmp2 == NULL){
                return;
            }
            if(tmp == NULL){
                tmp = *head2;
                *head1 = tmp;
                return;
            }else if(tmp2 == NULL){
                return;
            }
            
            while(tmp -> next != NULL){
                tmp = tmp -> next;
            }
            tmp -> next = tmp2;
        }

};
int main() {

    SLL_Node myNode;
    int key;
    bool answer;
    SLL_Node *head1 = NULL;
    SLL_Node *head2 = NULL;

    myNode.addToTail(&head1, 1);
    myNode.addToTail(&head1, 2);
    myNode.addToTail(&head1, 3);
    myNode.addToTail(&head1, 4);
    myNode.addToTail(&head1, 5);

    cout << "The List 1: ";
    myNode.PrintList(&head1);

    myNode.addToTail(&head2, 1);
    myNode.addToTail(&head2, 2);
    myNode.addToTail(&head2, 3);
    myNode.addToTail(&head2, 4);
    myNode.addToTail(&head2, 5);

    cout << "The List 2: ";
    myNode.PrintList(&head2);
    cout << endl;

    cout << "Are the two lists are the same?\n: ";
    answer = myNode.areSame(&head1, &head2);
    if(answer){
        cout << "Yes, the lists are the same.\n";
    }
    else{
        cout << "No, the lists are not the same.\n";
    }

    cout << "\nAfter reversing: \n";
    myNode.reverse(&head1);
    cout << "The List 1: ";
    myNode.PrintList(&head1);

    myNode.reverse(&head2);
    cout << "The List 2: ";
    myNode.PrintList(&head2);

    cout << "\nAppending the two list: " << endl;
    myNode.attachList(&head1, &head2);
    myNode.PrintList(&head1);


   exit(0);




    /*do{
        cout << "Please eneter a key: ";
        cin >> key;
        if(key != -1){
            p = new SLL_Node(key);
            if(head == NULL){
                head = tail = p;
            }
            else{
                tail -> next = p;
                tail = p;
            }
        }
    }while(key!= -1);
    p = head;

    while(p!= NULL){
        cout << p->info << "->";
        p = p -> next;
    }
    cout << "|||" << endl;
    return 0;*/
}

