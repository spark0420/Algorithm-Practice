#include <time.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class numPrime{

    public:

    void genNum(vector<long> &numList){
        int currInt0;
        int currInt1;
        string currStr;

        srand(time(0));

            for(int i = 0; i < 20; i++){
                currInt0 = rand() % 9 + 1;
                currStr = to_string(currInt0);
                for(int j = 0; j < 5; j++){
                currInt1 = rand() % 10;                        
                string tmp = to_string(currInt1);
                currStr = currStr + tmp;
                }   
                long currLong = stol(currStr, nullptr, 10);
                numList.push_back(currLong);
                }
    }
    void checkPrime(int currNum){
            bool check = true;

            float divisor = sqrt(currNum);
            int intDivisor = divisor;
            //cout << "tmp: " << tmp << " divisor: " << intDivisor << endl;
            int cnt = 0;
            for(int i = 2; i <= intDivisor; i++){
                cnt++;
                if(currNum % i == 0){
                    check = false;
                    break;
                }
            }
            if(check){
                cout << "The number " << currNum << " is a prime number!  ";
                cout << "It took " << cnt << " iteration.\n";
            }
            else{
                cout << "The number " << currNum << " is not a prime number!  ";
                cout << "It took " << cnt << " iteration.\n";
            }
    }        
};
int main() {
    numPrime prime;
    vector<long> numList;

    prime.genNum(numList);
    int size = numList.size();

    for (int i = 0; i < size; i++){
        int currNum = numList[i];
        prime.checkPrime(currNum);
    }
    cout << endl;

    //I simply make the given number square root and
    //divided it from 2 to the sqaure root value.
    
}
