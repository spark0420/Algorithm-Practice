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

bool evaluateSize(stack<int> &left, stack<int> &right){

    bool leftIsBigger = false;

    if(left.size() > right.size()){
        cout << left.size() << " : " << right.size() << endl;
        return true;
    }
    else if(left.size() < right.size()){
        return false;
    }
    else if(left.size() == right.size()){

        stack<int> reversedLeft;
        stack<int> reversedRight;

        stack<int> tmpLeft = left;
        stack<int> tmpRight = right;
        
        while(!tmpLeft.empty()){
            int curr1 = tmpLeft.top();
            reversedLeft.push(curr1);
            tmpLeft.pop();
        }
    
        while(!tmpRight.empty()){
            int curr2 = tmpRight.top();
            reversedRight.push(curr2);
            tmpRight.pop();
        }

        while(!reversedLeft.empty() || !reversedRight.empty()){
            int leftValue = reversedLeft.top();
            reversedLeft.pop();
            int rightValue = reversedRight.top();
            reversedRight.pop();
        
            if(leftValue > rightValue){
                leftIsBigger = true;
                return leftIsBigger;
            }
            else if(leftValue < rightValue){
                leftIsBigger = false;
                return leftIsBigger;
            }
        }
    }
    return leftIsBigger;
}

void subtractStack(stack<int> &left, stack<int> &right){
    stack<int> result;
    int currResult = 0;
    bool borrow = false;

    int currLeft;
    int currRight;

    if(left.empty() || right.empty()){
        cout << "There is no number to subtract.\n";
        return;
    }
    bool leftIsBigger = evaluateSize(left, right);

    if(leftIsBigger){
        while(!left.empty() && !right.empty()){
            if(borrow == false){
                currLeft = left.top();
                currRight = right.top();
                left.pop();
                right.pop();
            }
            else{
                currLeft = left.top() - 1;
                currRight = right.top();
                left.pop();
                right.pop();
            }
            
            if(currLeft > currRight || currLeft == currRight){
                borrow = false;
                currResult = currLeft - currRight;
                result.push(currResult);
            }
            else{
                borrow = true;
                currResult = (currLeft + 10) - currRight;
                result.push(currResult);
            }
        }
    }
    else{
        while(!right.empty() && !left.empty()){
            if(borrow == false){
                currRight = right.top();
                currLeft = left.top();
                right.pop();
                left.pop();
            }
            else{
                currRight = right.top() -1;
                currLeft = left.top();
                right.pop();
                left.pop();
            }
            
            if(currRight > currLeft || currRight == currLeft){
                borrow = false;
                currResult = currRight - currLeft;
                result.push(currResult);
            }
            else{
                borrow = true;
                currResult = (currRight + 10) - currLeft;
                result.push(currResult);
            }
        }
     }
     if(!left.empty() || !right.empty()){
        while(!left.empty()){
            if(borrow){
                currLeft = left.top() -1;
                left.pop();
                result.push(currLeft);
                borrow = false;
            }else{
                currLeft = left.top();
                left.pop();
                result.push(currLeft);
            }
        }
        while(!right.empty()){
            if(borrow){
                currRight = right.top() -1;
                right.pop();
                result.push(currRight);
                borrow = false;
            }else{
                currRight = right.top();
                right.pop();
                result.push(currRight);
            }
            
        }
    }
     cout << "The result of subtraction: ";
     if(leftIsBigger){
         cout << "+";
         while(!result.empty()){
            int curr = result.top();
            cout << curr;
            result.pop();
        }
    }else{
        cout << "-";
        while(!result.empty()){
            int curr = result.top();
            cout << curr;
            result.pop();
        }
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
        cout << "Subtration start! " << leftString << " - " << rightString << endl;

        subtractStack(leftStack, rightStack);
    }
    
}