#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void reverseWithQueue(stack<int> &target){
    queue<int> myQueue;

    if(target.empty()){
        cout << "The stack is empty!.\n";
    }
    else{
        while (!target.empty()) {
        int el = target.top();
        myQueue.push(el);
        target.pop();
        }
    
        while (!myQueue.empty()) {
        int newEl = myQueue.front();
        target.push(newEl);
        myQueue.pop();
        }
    }
}

void reverseWithStack(stack<int> &target){
    stack<int> stack1;
    stack<int> stack2;

    if(target.empty()){
        cout << "The stack is empty!.\n";
        return;
    }
    else{
        while(!target.empty()){
            int el = target.top();
            stack1.push(el);
            target.pop();
        }
        while(!stack1.empty()){
            int el2 = stack1.top();
            stack2.push(el2);
            stack1.pop();
        }
        while(!stack2.empty()){
            int el3 = stack2.top();
            target.push(el3);
            stack2.pop();
        }
    }
}

void reverseWithVariable(stack<int> &target){
    stack<int> tmp;
    int size = target.size();

    if(target.empty()){
        cout << "The stack is empty!.\n";
        return;
    }
    else{
        for(int j = 1; j <= size; j++){
            int currTop = target.top();
            target.pop();
            for(int i = 0; i < size -j; i++){
                int remainder = target.top();
                tmp.push(remainder);
                target.pop();
            }
            target.push(currTop);
            while(!tmp.empty()){
                int el = tmp.top();
                target.push(el);
                tmp.pop();
            }
        }
    }
}

void showstack(stack<int> &target){
    stack<int> tmp = target;

    while(!tmp.empty()){
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << endl;
}

int main(){
    stack<int> myStack;
    stack<int> myStack2;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    myStack2.push(6);
    myStack2.push(7);
    myStack2.push(8);
    myStack2.push(9);
    myStack2.push(10);
    

    cout << "Current elements of stack1: ";
    showstack(myStack);
    cout << "Current elements of stack2: ";
    showstack(myStack2);

    cout<< "\nReversing stack1 using queue....\n";
    reverseWithQueue(myStack);
    cout << "After reversing stack1: ";
    showstack(myStack);
    

    cout<< "\nReversing stack2 using stacks....\n";
    reverseWithStack(myStack2);
    cout << "After reversing stack2: ";
    showstack(myStack2);

    cout<< "\nReversing stack1 and stack2 using 1 stack & variable....\n";
    reverseWithVariable(myStack);
    reverseWithVariable(myStack2);
    cout << "After reversing stack1: ";
    showstack(myStack);
    cout << "After reversing stack2: ";
    showstack(myStack2);






}