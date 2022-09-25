#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void transferWithStack(stack<int> &from, stack<int> &to){
    stack<int> stack1;

    if(from.empty()){
        cout << "The original stack is empty!.\n";
        return;
    }
    else{
        while(!from.empty()){
            int el = from.top();
            stack1.push(el);
            from.pop();
        }
        while(!stack1.empty()){
            int el2 = stack1.top();
            to.push(el2);
            stack1.pop();
        }
    }
}

void transferWithVariable(stack<int> &from, stack<int> &to){
    int size = from.size();

    if(from.empty()){
        cout << "The stack is empty!.\n";
        return;
    }
    else{
        for(int x = 1; x <= size; x++){
            for(int j = 0; j < size - x; j++){
                int remainder = from.top();
                to.push(remainder);
                from.pop();
            }
            int last = from.top();
            from.pop();
            for(int i = 0; i < size - x; i++){
                int el = to.top();
                from.push(el);
                to.pop();
            }
            to.push(last);
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
    stack<int> myStack1;
    stack<int> myStack2;
    stack<int> myStack3;
    stack<int> myStack4;

    myStack1.push(1);
    myStack1.push(2);
    myStack1.push(3);
    myStack1.push(4);
    myStack1.push(5);
    
    myStack3.push(6);
    myStack3.push(7);
    myStack3.push(8);
    myStack3.push(9);
    myStack3.push(10);

    cout << "Current elements of stack1: ";
    showstack(myStack1);
    cout << "Current elements of stack2: ";
    showstack(myStack2);

    cout<< "\nMoving elements in stack1 to stack2....\n";
    transferWithStack(myStack1, myStack2);
    cout << "Current elements of stack1: ";
    showstack(myStack1);
    cout << "Current elements of stack2: ";
    showstack(myStack2);

    cout << "\n-------------------------------------------------\n";
    cout << "Current elements of stack3: ";
    showstack(myStack3);
    cout << "Current elements of stack4: ";
    showstack(myStack4);

    cout<< "\nMoving elements in stack3 to stack4....\n";
    transferWithVariable(myStack3, myStack4);
    cout << "Current elements of stack3: ";
    showstack(myStack3);
    cout << "Current elements of stack4: ";
    showstack(myStack4);



}