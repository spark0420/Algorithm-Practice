#include <iostream>
#include <stack>
#include <chrono>

using namespace std;

void additionStack(stack<int> &left, stack<int> &right, stack<int> &result){
    stack<int> tmpLeft = left;
    stack<int> tmpRight = right;
    stack<int> sum;

    string finalSum;
    long finalNum;

    int currSum = 0;
    int pushingNum = 0;
    int carry = 0;

    if(tmpLeft.empty() || tmpRight.empty()){
        cout << "There is no number to add.\n";
        return;
    }

    while(!tmpLeft.empty() && !tmpRight.empty()){
        currSum = tmpLeft.top() + tmpRight.top() + carry;
        tmpLeft.pop();
        tmpRight.pop();

        pushingNum = currSum % 10;
        carry = currSum / 10;
        sum.push(pushingNum);
    }
    if(!tmpLeft.empty() || !tmpRight.empty()){
        while(!tmpLeft.empty()){
            currSum = tmpLeft.top() + carry;
            tmpLeft.pop();
            pushingNum = currSum % 10;
            carry = currSum/10;
            sum.push(pushingNum);
        }
        while(!tmpRight.empty()){
            currSum = tmpRight.top() + carry;
            tmpRight.pop();
            pushingNum = currSum % 10;
            carry = currSum/10;
            sum.push(pushingNum);
        }
    }
    if(carry > 0){
        sum.push(carry);
    }

    while(!result.empty()){
        result.pop();
    }
    while(!sum.empty()){
        int curr = sum.top();
        result.push(curr);
        sum.pop();
    }
}

void fib(int n){

        stack<int> x;
        stack<int> y;
        stack<int> z;
        stack<int> result;

        x.push(0);
        y.push(1);

        if(n > 2){
            for(int i = 2; i <= n; i++){
                additionStack(x, y, z);
                while(!x.empty()){
                    x.pop();
                }
                x = y;
                while(!y.empty()){
                    y.pop();
                }
                y = z;
            }
            
            while(!z.empty()){
                int curr = z.top();
                result.push(curr);
                z.pop();
            }
            cout << n <<"th Fibonnaci is: ";
            while(!result.empty()){
                int res = result.top();
                cout << res;
                result.pop();
            }
        }
        else{
            cout << n <<"th Fibonnaci is: ";
            while(!y.empty()){
                int curr = y.top();
                cout << curr;
                y.pop();
            };
        }
}

int main() {
    int x;
    long value;
    cout << "Type a number: " << endl;
    cin >> x;

    //auto start = chrono::high_resolution_clock::now();

    fib(x);

    //auto end = chrono::high_resolution_clock::now();

    //chrono::duration<double, milli> duration = end - start;

    //cout << "It took " << duration.count() << "microseconds\n";

}