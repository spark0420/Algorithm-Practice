#include <iostream>
#include <time.h>

using namespace std;

int main(){
    int arr[10];
    int key, i;

    srand(time(NULL));

    for(i = 0; i < 10; i++){
        arr[i] = rand() % 100 + 1;
    }

    cout << "Original Array ";

    for(i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int j = 1; j < 10; j++){
        key = arr[j];
        i = j-1;

        while(i >= 0 && arr[i] > key){
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }

    cout << "Sorted Array ";

    for(i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}