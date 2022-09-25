#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Node{
    
    public:
        string info;
        Node *next;

        Node() {
            next = NULL;
        }
        Node(string data, Node *n = NULL) {
            info = data;
            next = n;
        }
        void addToTail(Node **head, string new_key){
            Node* newNode = new Node;
            Node *tmpHead = *head;

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
        void PrintList(Node **head){
            Node *tmpHead = *head;
            int i = 1;

            cout << endl;

            while(tmpHead != NULL){
                cout << i << ". ";
                cout << tmpHead -> info << endl;
                tmpHead = tmpHead-> next;
                i++;
            }

        cout << endl;
        }

        void insertAfter1(Node **head, string new_key, int pos = 0){

            if(pos == 0){
                addToTail(head, new_key);
                return;
            }

            int new_pos = pos -1;
            Node *tmp = *head;
            Node *prev = *head;

            if(head == NULL){
                cout << "The list is empty. The new node will be added to the head.\n";
                Node *newNode = new Node();
                newNode -> info = new_key;
                newNode -> next = NULL;
                *head = newNode;

                return;
            }
            if(new_pos == 0){
                Node *newNode = new Node();
                newNode -> info = new_key;
                newNode -> next = *head;
                *head = newNode;

                return;
            }
            else{
                for(int i = 0; i < new_pos -1; i++){
                    prev = prev -> next;
                }
                Node *newNode = new Node();
                newNode -> info = new_key;
                newNode -> next = prev-> next;
                prev -> next = newNode;
            }

        }
        void deleteNode(Node **head, int posA = 0, int posB = 0){
            if(*head == NULL){
                cout << "The list is empty.\n";
                return;
            }

            Node *tmp = *head;
            Node *prev = *head;

            if(posA == 0 && posB == 0){
                while(tmp -> next != NULL){
                    prev = tmp;
                    tmp = tmp -> next;
                }
                prev -> next = NULL;
                free(tmp);
                return;
            }

            if(posA == 1 && posB == 0){
                *head = tmp -> next;
                free(tmp);
                return;
            }

            if(posA != 0 && posB == 0){
                for(int i = 0; i < posA -1; i++){
                    prev = tmp;
                    tmp = tmp -> next;
                }
                if(tmp == NULL && tmp -> next == NULL){
                    cout << "The node doesn't exist.\n";
                    return;
                }
                else if(tmp != NULL && tmp -> next == NULL){
                    prev -> next = NULL;
                    free(tmp);
                }
                else if(tmp != NULL && tmp -> next != NULL){
                    prev -> next = tmp -> next;
                    free(tmp);
                }
            }
            if(posA == 1 && posB != 0){
                for(int i = 0; i < posB; i++){
                    tmp = tmp -> next;
                }
                if(tmp != NULL){
                    *head = tmp;
                    return;
                }
                if(tmp == NULL) {
                    *head = tmp;
                    cout << "The list is empty.\n";
                    return;
                }
            }
            else if(posA != 0 && posB != 0){
                for(int i = 0; i < posA - 2; i++){
                    prev = prev -> next;
                }
                for(int i = 0; i < posB; i++){
                    tmp = tmp -> next;
                }
                if(prev != NULL && tmp != NULL){
                    prev -> next = tmp;
                    return;
                }
                else if(prev != NULL && tmp == NULL){
                    prev -> next = NULL;
                    return;
                }
                else if(prev == NULL && tmp == NULL){
                    cout << "The node doesn't exist.\n";
                }
            }    
        }
        void ListNodes(Node **head, int posA = 0, int posB = 0){
            if(posA == 0 && posB == 0 ){
                if(head == NULL){
                    cout << "The list is empty.\n";
                    return;
                }
                else{
                    PrintList(head);
                    return;
                }
            }

            Node *tmp = *head;
            Node *prev = *head;
            Node *tmp2 = *head;
            int count =1;

            if(posA != 0 && posB == 0){
                for(int i = 0; i < posA - 1; i++){
                    tmp = tmp -> next;
                }
                if(tmp == NULL){
                    cout << "Enter a valid node in the list.\n";
                    return;
                }
                else{
                    cout << posA << ". " << tmp -> info << endl;
                    return;
                }
            }

            if(posA != 0 && posB != 0){
                for(int i = 0; i < posA -1; i++){
                    prev = prev -> next;
                }
                for(int j = 0; j < posB -1; j++){
                    tmp = tmp -> next;
                }
                if(prev == NULL){
                    return;
                }
                else if(prev != NULL && tmp == NULL){
                    PrintList(&prev);
                    return;
                }
                else if(prev != NULL && tmp != NULL){
                    while(tmp2 != prev){
                        tmp2 = tmp2 -> next;
                        count++;
                    }
                    while(prev != tmp){
                        cout << count << ". ";
                        cout << prev -> info << endl;
                        prev = prev-> next;
                        count++;
                    }
                    cout << count << ". ";
                    cout << prev -> info << endl;
                    return;
                }
            }
        }
        
        void appendText(Node **head, string text){

            Node *tmp = *head;
            int i = 1;

            while(tmp != NULL){
                string old = tmp -> info;
                tmp -> info = old + text;
                tmp = tmp-> next;
                i++;
            }

        cout << endl;
        }

        void option(){
            cout << "\nMENU" << endl;
            cout << "\n";
            cout << "I - insert line " << endl;
            cout << "D - delete line " << endl;
            cout << "L - list line "<<endl;
            cout << "A - append text "<<endl;
            cout << "E - exit and save the list in a file" << endl;
            cout << endl;
        }





};

int main() {
    Node myNode;
    ifstream file;
    ofstream file2;
    string line;
    vector<string> v;
    Node *head;


    file.open("lab03.txt", ios::in);
    if(!file.is_open()){
        cout << "error!!\n" ;
    }else {
        while(getline(file, line)){
            v.push_back(line);
        }
    }
    file.close();

    int i = v.size();
    string first = v[0];
    head = new Node(first);

    for(int x = 1; x < i; x++){
        myNode.addToTail(&head, v[x]);
    };
    v.clear();

    string start;

    std::cout << "If you want to start the program, type EDIT.\n";
    cin >> start;
    cin.ignore();

    if(start == "EDIT"){
        char option;
        do{
            myNode.option();
            cin >> option;
            cin.ignore();

            if(option == 'I') {
                    cout << "\nType the line number that you want to insert your text before.\n";
                    cout << "Type 0 to insert at the end.\n";
                    char charPos;
                    cin >> charPos;
                    cin.ignore();

                    int posA;
                    if(isdigit(charPos)){
                        posA = (int)charPos -48;
                        string newString;
                        cout << "Type a new text line.\n";
                        getline(cin, newString);
                    
                        myNode.insertAfter1(&head, newString, posA);
                        myNode.PrintList(&head);

                    }else{
                        cout << "\nType a number.\n";
                    }
                    
            }
            else if(option == 'A'){
                cout << "\nType the text you want to append.\n";
                string appText;
                getline(cin, appText);
                myNode.appendText(&head, appText);
                myNode.PrintList(&head);
            }
            else if(option == 'D'){
                cout << "\nType n/m to delete from nth line to mth line.\n";
                cout << "Type n to delete nth line.\n";
                cout << "Type 0 to delete the last line.\n";

                string pos;
                cin >> pos;
                cin.ignore();
                
                char pos1;
                char pos3;
                int intPos1;
                int intPos2;
                if(pos[0] == '0'){
                    myNode.deleteNode(&head);
                    
                }
                else if(pos[0] != '0'){
                    if(pos[1] == '/'){
                        pos1 = pos.at(0);
                        pos3 = pos.at(2);
                        if(isdigit(pos1) && isdigit(pos3)){
                            intPos1 = (int)pos1 -48;
                            intPos2 = (int)pos3 -48;
                            myNode.deleteNode(&head, intPos1, intPos2);
                        }
                        else{
                            cout << "\nType a number.\n";
                        }
                        
                    }
                    else{
                        pos1 = pos.at(0);
                        if(isdigit(pos1)){
                            intPos1 = (int)pos1 -48;
                            myNode.deleteNode(&head, intPos1);
                        }
                        else{
                            cout << "\nType a number.\n";
                        }
                    }
                }
                myNode.PrintList(&head);
            }
            else if(option == 'L'){
                cout << "\nType n/m to list from nth line to mth line.\n";
                cout << "Type n to list nth line.\n";
                cout << "Type 0 to list from the first line.\n";

                string pos;
                cin >> pos;
                cin.ignore();
                char pos1;
                char pos3;
                int intPos1;
                int intPos2;

                if(pos[0] == '0'){
                    myNode.ListNodes(&head);
                    
                }
                else if(pos[0] != '0'){
                    if(pos[1] == '/'){
                        pos1 = pos.at(0);
                        pos3 = pos.at(2);
                        if(isdigit(pos1) && isdigit(pos3)){
                            intPos1 = (int)pos1 -48;
                            intPos2 = (int)pos3 -48;
                            myNode.ListNodes(&head, intPos1, intPos2);
                        }
                        else{
                            cout << "\nType a number.\n";
                        }
                        
                    }
                    else{
                        pos1 = pos.at(0);
                        if(isdigit(pos1)){
                            intPos1 = (int)pos1 -48;
                            myNode.ListNodes(&head, intPos1);
                        }
                        else{
                            cout << "\nType a number.\n";
                        }
                    }
                }
            }
            else if(option == 'E'){
                cout << "Exit Editor!\n";
            }
            else{
                cout << "Choose a valid menu.\n";
            }

        }while(option != 'E');
            
    }
    cout << "Revising...\n";
        
    Node *tmp = head;

        if(tmp == NULL){
            v.push_back(" ");
        }
        else {
            while(tmp != NULL){
                string el = tmp -> info;
                v.push_back(el);
                tmp = tmp -> next;
            }
        }
        int j = v.size();
        

        file2.open("lab03-tmp.txt", ios::out);
        if(!file2.is_open()){
            cout << "error!!\n" ;
            }else {
                for(int y = 0; y < j; y++){
                    file2 << v[y] << "\n";
                }
            }
        file2.close();

        remove("lab03.txt");
        rename("lab03-tmp.txt", "lab03.txt");
        
        cout << "Done!\n";

        cin.ignore();
        return(0);
    
}
