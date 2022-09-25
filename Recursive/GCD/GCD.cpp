#include <iostream>

using namespace std;

void GCD(int n, int m){

    if((m <= n) && (n % m) == 0){
        cout << m << endl;
    }
    else if(n < m){
        GCD(m, n);
    }
    else{
        GCD(m, n % m);
    }
}

int main(){
    
    cout << "\nThe greatest common divisior of two integer 12, 45 is: ";
    GCD(12, 45);
    cout << endl;

    cout << "\nThe greatest common divisior of two integer 36, 144 is: ";
    GCD(36, 144);
    cout << endl;
}