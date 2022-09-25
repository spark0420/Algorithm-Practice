#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <chrono>
#include <thread>

using namespace std;

class subsetSum{
    public:
    void genRan(int *intptr) {
        int maxNum = 20;
        int minNum = -20;

        srand(time(0));

        for(int i = 0; i < 10; i++){
            *(intptr + i) = (rand() % (maxNum + 1 - minNum)) + minNum;
        }
    }

    int getTotalSum(int* givenArray, int arraySize) { 
    //returns the sum of values in the givenArray
        int sum = givenArray[0];
        for (int i = 1; i < arraySize; i++) {
         sum = sum + givenArray[i];
        }
        return sum;
}

    int* arrayAdd(int* oldArray, int arraySize, int value) {
    //returns a copy  of oldArray with the new value added at the end.
        int* newArray = new int[arraySize + 1];
        if (arraySize == 0) { 
            newArray[0] = value;
        }
        else {
            for (int i = 0; i < arraySize; i++) {
                newArray[i] = oldArray[i];
            }
            newArray[arraySize] = value;
        }
            return newArray;
    }

    void printSubSet(int* currentSet, int setSize) {
        cout << "Found a Subset that sums up to 0!" << endl;
        for (int i = 0; i < setSize; i++){
            std::cout << currentSet[i] << " ";
        }    
        cout << endl << endl;
    }

    void findSubSet(int* currentSet, int setSize, int* totalSet, int totalSize, int lastIndexNumber) {
        if (setSize == totalSize || lastIndexNumber == totalSize) 
            return;

        if (setSize > 0 && getTotalSum(currentSet, setSize) == 0) 
            printSubSet(currentSet, setSize);

        for (int i = lastIndexNumber + 1; i < totalSize; i++) {
        //expend the subset by adding one more elelemt
            int* nextSet = arrayAdd(currentSet, setSize, totalSet[i]);
            findSubSet(nextSet, setSize + 1, totalSet, totalSize, i);

        }
    }
}; 

int main() {

    subsetSum mySum;
    int intArray[10];
    int *ptr = intArray;
    
    mySum.genRan(ptr);

    cout << "Generating 10 random numbers from -20 to 20!\n\n";
    cout << "Your numbers are: ";

    for(int i = 0; i < 10; i++){
        cout << ptr[i] << " ";
    }
    cout << endl << endl;

    int* currentSet = new int[0]; 

    auto start = chrono::high_resolution_clock::now();

     mySum.findSubSet(currentSet, 0, intArray, 10, -1);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    cout << "It took " << duration.count() << "ms\n";

}