#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX_LEVEL 7

using namespace std;

class Node{

    public:
        int info;
        Node **next;

        Node() {}

        Node(int i){
            info = i;
        }
        Node(int i, int level);
};

typedef Node *nodeptr;

Node::Node(int i, int level){
    this -> info = i;
    this -> next = new nodeptr[level + 1];
};

class SkipList{

    nodeptr header;
    int value;

    public: 
    SkipList() {
        header = new Node(-1, MAX_LEVEL);
    }

    ~SkipList() {
        delete header;
    }

    float frand() {
        return (float) rand() / RAND_MAX;
    }

    int generateLevel() {
        static bool first = true;

        if (first) {
            srand((unsigned)time(NULL));
            first = false;
        }

        int level = (int)(log(frand()) / log(1.0- 0.5));

        if(level < MAX_LEVEL){
            return level;
        }
        else{
            return MAX_LEVEL - 1;
        }
    }

    void display(){
        cout << "-------------------------------------------\n";
        cout << "\nTrace of Each Level: " << endl;

        for (int i = 0; i < MAX_LEVEL; i++){
            nodeptr ptr = header -> next[i];
            cout << "Level " << i << ": ";

            while (ptr != NULL){   
                cout << ptr -> info << " ";
                ptr = ptr -> next[i];
             }
             
        cout << "\n";
        }
    }

    void insert_element(int &key){
        nodeptr tmp = header;
        nodeptr curr[MAX_LEVEL + 1];
        nodeptr prev[MAX_LEVEL + 1];

        int level;
  
        for (int i = MAX_LEVEL-1; i >= 0; i--){
            while (tmp -> next[i] != NULL && tmp -> next[i] -> info < key){
                tmp = tmp -> next[i];
            }
            prev[i] = tmp;

            if(tmp -> next[i] == NULL){
                curr[i] = NULL;
            }
            else{
                curr[i] = tmp -> next[i];
            }
        }

        tmp = tmp -> next[0];

        if(tmp == NULL || tmp -> info != key){
            level = generateLevel();
            cout << "The level is " << level << endl;
            nodeptr newPtr = new Node(key, level);

            for (int i = 0; i <= level; i++){
                newPtr -> next[i] = curr[i];
                prev[i]->next[i] = newPtr;
        }
        cout << "Successfully Inserted key " << key << "\n";
     }

    }
};
int main() {

    SkipList myList;

    srand(time(0));
    vector<int> v;

    for(int i = 0; i < 128;){
        int num = (rand() % 128) + 1;
        if(count(v.begin(), v.end(), num)){
        }
        else{
            v.push_back(num);
            i++;
        }
    }

    for( int i = 0; i < v.size(); i ++){
        cout << i << ": " << v.at(i) << endl;
        myList.insert_element(v.at(i));
    }

    myList.display();
}