#include <iostream>
#include <queue>

using namespace std;

void showQueue(queue<int> &original){
    queue<int> tmp = original;

    while(!tmp.empty()){
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << endl;
}

void sortWithOne(queue<int> &original){
    queue<int> tmp;

    int size = original.size();

    for(int i = 1; i <= size; i++){
        int min = original.front();
        original.pop();

        for(int j = 0; j < size - i; j++){
            int curr = original.front();
            original.pop();

            if(curr <= min){
                original.push(min);
                min = curr;
            }
            else{
                original.push(curr);
            }
        }
        tmp.push(min);
    }
    while(!original.empty()){
        original.pop();
    }
    while(!tmp.empty()){
        int x = tmp.front();
        original.push(x);
        tmp.pop();
    }
}

void sortWithTwo(queue<int> &original){
    queue<int> tmp;
    queue<int> sorted;

    int size = original.size();
    int min;
    int curr;

    for(int i = 0; i < size; i++){
        tmp = original;
        min = original.front();

        for(int j = 0; j < size - i; j++){
            curr = tmp.front();
            tmp.pop();

            if(curr <= min){
                min = curr;
            }
            else{
            }
        }
        sorted.push(min);

        for(int k = 0; k < size - i; k++){
            int check = original.front();
            original.pop();
            if(min != check){
                original.push(check);
            }else{
            }
        }
        while(!tmp.empty()){
            tmp.pop();
        }
    }
    original = sorted;
}


int main() {
    queue<int> queue1;
    queue<int> queue2;
    
    queue1.push(1);
    queue1.push(5);
    queue1.push(3);
    queue1.push(7);
    queue1.push(2);

    queue2.push(4);
    queue2.push(9);
    queue2.push(1);
    queue2.push(6);
    queue2.push(7);

    cout << "Current elements of queue1: ";
    showQueue(queue1);
    cout << endl;

    cout << "After sorting queue1 with one additional Queue: ";
    sortWithOne(queue1);
    showQueue(queue1);
    cout << endl;

    cout << "Current elements of queue2: ";
    showQueue(queue2);
    cout << endl;

    cout << "After sorting queue2 with two additional Queues: ";
    sortWithTwo(queue2);
    showQueue(queue2);
    cout << endl;


}
