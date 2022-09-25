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
void toBinary(long long n, stack<int>& binStack){
    int binaryNum[64];
    
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--){
        binStack.push(binaryNum[j]);
    }
}

void showstack(stack<int> &target){
    stack<int> tmp = target;
    stack<int> tmp2;

    while(!tmp.empty()){
        tmp2.push(tmp.top());
        tmp.pop();
    }
    while(!tmp2.empty()){
        int curr = tmp2.top();
        tmp2.pop();
        cout << curr;
    }
    cout << endl;
}

void addBinary(stack<int> &stack1, stack<int> &stack2){
    stack<int> sum;
    stack<int> tmp = stack1;
    int currSum = 0;
    int carry = 0;
    int pushingNum;
    int size = stack2.size();

    while(!tmp.empty() && !stack2.empty()){
        currSum = tmp.top() + stack2.top() + carry;
        tmp.pop();
        stack2.pop();

        if(currSum == 2){
            carry = 1;
            pushingNum = 0;
        }
        else if(currSum == 3){
            carry = 1;
            pushingNum = 1;
        }
        else{
            carry = 0;
            pushingNum = currSum;
        }
        sum.push(pushingNum);
    }
    while(!sum.empty()){
        stack2.push(sum.top());
        sum.pop();
    }
}
void binaryToHex(string &binStr){
    int binSize = binStr.length();
    string finalHex = "";

    int remainder = binSize % 4;
    for(int i = 0; i < 4 - remainder; i++){
        binStr = '0' + binStr;
    }
    binSize = binStr.length();

    for(int i = 0; i <= binSize - 4; i += 4){
        char currHex;
        string currNum = binStr.substr(i, 4);

        if(currNum == "0000"){
            currHex = '0';
        }
        else if(currNum == "0001"){
            currHex = '1';
        }
        else if(currNum == "0010"){
            currHex = '2';
        }
        else if(currNum == "0011"){
            currHex = '3';
        }
        else if(currNum == "0100"){
            currHex = '4';
        }
        else if(currNum == "0101"){
            currHex = '5';
        }
        else if(currNum == "0110"){
            currHex = '6';
        }
        else if(currNum == "0111"){
            currHex = '7';
        }
        else if(currNum == "1000"){
            currHex = '8';
        }
        else if(currNum == "1001"){
            currHex = '9';
        }
        else if(currNum == "1010"){
            currHex = 'A';
        }
        else if(currNum == "1011"){
            currHex = 'B';
        }
        else if(currNum == "1100"){
            currHex = 'C';
        }
        else if(currNum == "1101"){
            currHex = 'D';
        }
        else if(currNum == "1110"){
            currHex = 'E';
        }
        else if(currNum == "1111"){
            currHex = 'F';
        }
        finalHex = finalHex + currHex;
    }
     binStr = finalHex;
}

void multiplyStack(stack<int> &left, stack<int> &right){
    int sizeLeft = left.size();
    int sizeRight = right.size();
    int resultSize = sizeLeft + sizeRight;

    stack<int> product;

    stack<int> tmpLeft;
    stack<int> tmpRight;

    stack<int> tmpLeft2;
    stack<int> tmpRight2;

    stack<int> tmpProduct;

    while(!left.empty()){
        tmpLeft.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        tmpRight.push(right.top());
        right.pop();
    }

    for(int i = resultSize; i > 0; i--){
        product.push(0);
        if(i > sizeLeft){
            tmpLeft2.push(0);
        }
        else if(i <= sizeLeft){
            tmpLeft2.push(tmpLeft.top());
            tmpLeft.pop();
        }
    }

    for(int i = resultSize; i > 0; i--){
        if(i > sizeRight){
            tmpRight2.push(0);
        }
        else if(i <= sizeRight){
            tmpRight2.push(tmpRight.top());
            tmpRight.pop();
        }
    }

    for(int j = 0; j < sizeLeft; j++){
        int curr = tmpLeft2.top();
        tmpLeft2.pop();

        if(curr == 0){
            while(!tmpLeft2.empty()){
                tmpLeft.push(tmpLeft2.top());
                tmpLeft2.pop();
            }
            tmpLeft.push(0);
            while(!tmpLeft.empty()){
                tmpLeft2.push(tmpLeft.top());
                tmpLeft.pop();
            }

            tmpRight.push(0);
            while(!tmpRight2.empty()){
                tmpRight.push(tmpRight2.top());
                tmpRight2.pop();
            }
            tmpRight.pop();
            while(!tmpRight.empty()){
                tmpRight2.push(tmpRight.top());
                tmpRight.pop();
            }

        }
        else if(curr == 1){
            while(!tmpLeft2.empty()){
                tmpLeft.push(tmpLeft2.top());
                tmpLeft2.pop();
            }
            tmpLeft.push(0);
            while(!tmpLeft.empty()){
                tmpLeft2.push(tmpLeft.top());
                tmpLeft.pop();
            }

            addBinary(tmpRight2, product);

            tmpRight.push(0);
            while(!tmpRight2.empty()){
                tmpRight.push(tmpRight2.top());
                tmpRight2.pop();
            }
            tmpRight.pop();
            while(!tmpRight.empty()){
                tmpRight2.push(tmpRight.top());
                tmpRight.pop();
            }
        }
    }
    //cout << "Finished Calc\n";

    while(!product.empty()){
        tmpProduct.push(product.top());
        product.pop();
    }
    string finalValue;

    while(!tmpProduct.empty()){
        int value = tmpProduct.top();
        string str = to_string(value);
        finalValue = finalValue + str;
        tmpProduct.pop();
    }
    cout << "The product in Binary is: " << finalValue << endl;
    binaryToHex(finalValue);
    cout << "The product in Hex is: " << finalValue << endl;

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

        long long leftLongNum = stoll(leftString, nullptr, 10);
        long long rightLongNum = stoll(rightString, nullptr, 10);

        toBinary(leftLongNum, leftStack);
        toBinary(rightLongNum, rightStack);

        cout << "Multiplication start! " << leftLongNum << " * " << rightLongNum << endl;
        multiplyStack(leftStack, rightStack);
        cout << endl;

    }
    
}