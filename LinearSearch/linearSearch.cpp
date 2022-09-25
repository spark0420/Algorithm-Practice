#include <iostream>

using namespace std;

void linearSearch(int arr[], int target, int size, int index){
    if(index >= size){
        cout << "Not found!" << endl;
    }
    else if(arr[index] == target){
        cout << arr[index] << " found!" << endl;
        cout << "It was in index " << index << endl;
    }
    else{
        return linearSearch(arr, target, size, index+1);
    }
}

int main(){
    int arr[10] = {2, 4, 5, 1, 7, 23, 51, 11, 13, 25};
    int target = 23;
    int size = sizeof(arr) / sizeof(arr[0]);

    linearSearch(arr, target, size, 0);
}