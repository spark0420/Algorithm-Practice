#include <iostream>

using namespace std;

void oddNumRecur(int n){
    
    if(n == 0){
        return;
    }else{
        if(n % 2 == 1){
            oddNumRecur(n - 1);
            cout << n << " ";
        }else{
            oddNumRecur(n - 1);
        }
    }
}

void oddNumRecur2(int n){

    if(n > 0){
        if(n % 2 == 1){
            cout << n << " ";
            oddNumRecur2(n - 1);
        }
        else{
            oddNumRecur2(n - 1);
        }
    }
    else{
        return;
    }
}
int main() {
   
    cout << "\nOdd numbers between 1 and 10: ";
    oddNumRecur(10);
    cout << endl;

    cout << "Odd numbers between 10 and 1: ";
    oddNumRecur2(10);
    cout << endl << endl;

}