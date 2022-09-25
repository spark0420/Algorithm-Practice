#include <iostream>
#include <time.h>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void genNum(vector<string> &numList){
        int currInt0;
        int currInt1;
        string currStr;

        srand(time(NULL));

            for(int i = 0; i < 10; i++){
                currInt0 = rand() % 9 + 1;
                currStr = to_string(currInt0);
                for(int j = 0; j < 15; j++){
                    currInt1 = rand() % 10;                        
                    string tmp = to_string(currInt1);
                    currStr = currStr + tmp;
                }   
                string finalNum = currStr;
                numList.push_back(finalNum);
            }
}
void additionStack(stack<int> &left, stack<int> &right){
    stack<int> sum;
    string finalSum;
    long finalNum;

    int currSum = 0;
    int pushingNum = 0;
    int carry = 0;

    if(left.empty() || right.empty()){
        cout << "There is no number to add.\n";
        return;
    }

    while(!left.empty() && !right.empty()){
        currSum = left.top() + right.top() + carry;
        left.pop();
        right.pop();

        pushingNum = currSum % 10;
        carry = currSum / 10;
        sum.push(pushingNum);
    }
    if(!left.empty() || !right.empty()){
        while(!left.empty()){
            currSum = left.top() + carry;
            left.pop();
            pushingNum = currSum % 10;
            carry = currSum/10;
            sum.push(pushingNum);
        }
        while(!right.empty()){
            currSum = right.top() + carry;
            right.pop();
            pushingNum = currSum % 10;
            carry = currSum/10;
            sum.push(pushingNum);
        }
    }
    if(carry > 0){
        sum.push(carry);
    }

    cout << "The sum: ";
    while(!sum.empty()){
        int curr = sum.top();
        cout << curr;
        sum.pop();
    }
    cout << endl << endl;  
}

int main() {
    vector<string> numList1;

    stack<int> leftStack;
    stack<int> rightStack;

    genNum(numList1);

    int size1 = numList1.size();

    cout << "NumList1: \n" << endl;
    for (int i = 0; i < size1; i++){
        cout << i + 1 << ": " << numList1[i] << endl;
    }
    cout << endl;


    for(int k = 0; k < size1; k += 2){
        string leftString = numList1[k];
        string rightString = numList1[k + 1];

        for(int i = 0; i < leftString.length(); i++){
            char curr = leftString[i];
            int currInt = (int)curr - 48;

            leftStack.push(currInt);
        }
        for(int j = 0; j < rightString.length(); j++){
            char curr2 = rightString[j];
            int currInt2 = (int)curr2 - 48;

            rightStack.push(currInt2);
        }
        cout << "Addition start! " << leftString << " + " << rightString << endl;

        additionStack(leftStack, rightStack);

    }
    
}