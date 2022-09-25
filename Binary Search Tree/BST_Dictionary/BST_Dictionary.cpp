#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BST_node{
    public:
        string info;
        string description;
        BST_node *left;
        BST_node *right;

        BST_node(){
            left = NULL;
            right = NULL;
        }
        
        BST_node(string Info){
            info = Info;
            description = "";
            left = NULL;
            right = NULL;
        }

        BST_node(string Info, string des){
            info = Info;
            description = des;
            left = NULL;
            right = NULL;
        }  
};

class BST{
    public:
        BST_node *root;
        
        BST(void){
            root = NULL;
        }

        void insert_Node(string Info, string des){
            if(root == NULL){
                root = new BST_node(Info, des);
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
                curr -> left = new BST_node(Info, des);
            }
            else{
                curr -> right = new BST_node(Info, des);
            }

            cout << "\n\"" << Info << "\" is successfully inserted.\n";
        }

        void search_Node(string Info){
            bool found = false;

            if(root == NULL){
                cout << "\nThe dictionary is empty."<< endl;
                return;
            }

            BST_node *tmp = root;

            while(tmp != NULL){
                if(tmp -> info > Info){
                    tmp = tmp -> left;
                }
                else if(tmp -> info < Info){
                    tmp = tmp -> right;
                }
                else if(tmp -> info == Info){
                    found = true;
                    break;
                }
            }

            if(found){
                cout << "\nFound the searching value \"" << Info << "\"!\n";
                cout << Info << ": " << tmp -> description << endl << endl;
            }
            else{
                cout << "\nCouldn't find the searching value!\n\n";
            }
        }

        void makeDictionary(){
            
            insert_Node("DANCE", "to move one's feet or body, or both, rhythmically in a pattern of steps, especially to the accompaniment of music");
            insert_Node("BUFFALO", "any of several large wild oxen of the family Bovidae");
            insert_Node("FRIEND", "a person attached to another by feelings of affection or personal regard. ");
            insert_Node("APPLE", "the usually round, red or yellow, edible fruit of a small tree, Malus sylvestris, of the rose family.");
            insert_Node("COMPUTER", "a programmable electronic device designed to accept data, perform prescribed mathematical and logical operations at high speed, and display the results of these operations. ");
            insert_Node("ELEPHANT", "a very large herbivorous mammal of the family Elephantidae, the only extant family of proboscideans and comprising the genera Loxodonta (African elephants) and Elephus (Asian elephants)");
            insert_Node("GOAT", "any of numerous agile, hollow-horned ruminants of the genus Capra, of the family Bovidae, closely related to the sheep, found native in rocky and mountainous regions of the Old World, and widely distributed in domesticated varieties. ");
            
        }

        void preorder(){
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
                    cout << tmp -> info << endl;

                    if(tmp -> right != NULL){
                        preorder_st.push(tmp -> right);
                    }

                    if(tmp -> left != NULL){
                        preorder_st.push(tmp -> left);
                    }
                }
            }
        }

};

int main(){
    string usrStr;
    string searchStr = "";
    BST myDictionary;

    myDictionary.makeDictionary();
    cout << "---------------------------------------\n\n";

    cout << "If you want to quit the program, enter \"q\"\n";
    cout << "Enter a word to find the definition!\n";
    cin >> usrStr;

    while(usrStr != "q"){
        int strSize = usrStr.length();
        for(int i = 0; i < strSize; i++){
            char curr = usrStr[i];
            curr = toupper(curr);
            searchStr += curr;
        }

        myDictionary.search_Node(searchStr);

        searchStr = "";
        cout << "Enter a word to find the definition!\n";
        cin >> usrStr;
    }

    //myDictionary.preorder();


}

