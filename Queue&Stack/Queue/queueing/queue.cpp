#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class myQueue{
    private:
        stack<int> stack1;
        stack<int> stack2;

    public:
        void Clear(){
            while(!stack1.empty()){
                stack1.pop();
            }
        }

        bool isEmpty() {
            bool answer;

            if(stack1.empty()){
                answer = true;
            }
            else{
                answer = false;
            }
            return answer;
        }

        void EnQueue(int n){
            stack1.push(n);
        }

        void DeQueue(){
            int popVal;

            if(stack1.empty()){
                cout << "The Queue is empty.\n";
                return;
            }
            else{
                while(!stack1.empty()){
                int tmp = stack1.top();
                stack2.push(tmp);
                stack1.pop();
                }
                popVal = stack2.top();
                stack2.pop();

                while(!stack2.empty()){
                    int tmp2 = stack2.top();
                    stack1.push(tmp2);
                    stack2.pop();
                }
                cout << "The first element in the queue " << popVal << " is popped!" << endl;
            }
        }
        int FirstEl(){
            int firstElement = -1;

            if(stack1.empty()){
                cout << "The Queue is empty.\n";
            }
            else{
                while(!stack1.empty()){
                int tmp = stack1.top();
                stack2.push(tmp);
                stack1.pop();
                }
                firstElement = stack2.top();

                while(!stack2.empty()){
                    int tmp2 = stack2.top();
                    stack1.push(tmp2);
                    stack2.pop();
                }
            }
            return firstElement;
        }
};

int main() {
    myQueue myqueue1;

    myqueue1.EnQueue(1);
    myqueue1.EnQueue(2);
    myqueue1.EnQueue(3);
    myqueue1.EnQueue(4);
    myqueue1.EnQueue(5);

    cout << "The first element in the queue: " << myqueue1.FirstEl() << endl;

    cout << "Is the queue empty? ";
    bool anwer = myqueue1.isEmpty();
    if(anwer){
        cout << "True";
    }else{
        cout << "False";
    }
    cout << endl;

    cout << "Dequeue elements...\n" << endl;
    myqueue1.DeQueue();
    myqueue1.DeQueue();
    myqueue1.DeQueue();
    myqueue1.DeQueue();
    myqueue1.DeQueue();


}