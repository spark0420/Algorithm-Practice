#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ArraySize 10

using namespace std;

void generateArray(int A[]){
    int k, i, curr;
    bool dupCheck;
    
    srand(time(NULL));
    // for(k = 0; k < ArraySize; k++){
    //     A[k] = rand() % 100 + 1;
    // }
    while(k < ArraySize){
        curr = rand() % 100 + 1;
        dupCheck = false;
        for(i = 0; i <= k; i++){
            if(A[i] == curr){
                dupCheck = true;
                break;
            }
        }
        if(!dupCheck){
            A[k] = curr;
            k++;
        }
    }

}
void printArray(int A[], int arrSize){
    int k;

    for(k = 0; k < arrSize; k++){
        cout << "A[" << k << "] = " << A[k] << endl;
    }
}
void Merge(int A[], int p, int q, int r){
    int n1, n2, *left, *right, i, j;

    n1 = q - p +1; //number of elements on the left
    n2 = r - q; // number of elements on the right

    left = new int[n1 + 1];
    right = new int[n2 + 1]; // +1 indicates ..?

    for(i = 0; i < n1; i++){ //copy the left elements in A array 
        left[i] = A[p+i];
    }
    for(i = 0; i < n2; i++){ //copy the right elements in A array 
        right[i] = A[q+1+i];
    }

    left[n1] = INT32_MAX; // assign infinately large number at the end
    right[n2] = INT32_MAX; 

    cout << "Left array: \n";
    printArray(left, n1);
    cout << endl;

    cout << "Right array: \n";
    printArray(right, n2);
    cout << endl;

    i = 0;
    j = 0; 

    for(int k = p; k <= r; k++){
        if((left[i] != INT32_MAX) && left[i] <= right[j]){
            A[k] = left[i];
            i++;
        }else{
            if(right[j]!= INT32_MAX){
                A[k] = right[j];
                j++;
            }
            
        }
    }
}
void MergeSort(int A[], int p, int r){
    // p = initial Index , r = last Index, q = middle Index
    int q;

    if(p < r){
        q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }

}
int main(){

    int A[ArraySize] = {0};//initialize array with all zeros
    generateArray(A);
    cout << "Initial Array: \n";
    printArray(A, ArraySize);

    MergeSort(A, 0, ArraySize-1);

    cout << "Sorted Array: \n";
    printArray(A, ArraySize);
    cout << endl;
}