#include <iostream>
#include <vector>

using namespace std;

class myClass{

    public:

        vector<vector<int> > Final;

        void checkCombination(int* intArr, int size){
            vector<int> vecList;
            addingEl(intArr, size, vecList);

            printBoard(size);
            
        }

        void printBoard(int size){
            int board[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 0, 0, 0, 0 } };;

            int count = 1;
            for(int i = 0; i < Final.size(); i++){
                   cout << "Combination " << count << ": ";
                   printVector(Final.at(i));
                   count++;
                   vector<int> current = Final.at(i);
                   for(int i = 0; i < size; i++){
                        int Queen = current[i];
                        for(int j = 1; j <= size; j++){
                            if(Queen == j){
                                board[i][j-1] = 1;
                            }
                        }
                    }
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++){
                            cout << " " << board[i][j] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;

                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++){
                            board[i][j] = 0;
                        }
                    }
            }
        }

        bool checkSafety(int intVal, vector<int>& vecList){
            int currSize = vecList.size();
            int currLocation = currSize;

            for(int i = 0; i < currSize; i++){
                if(intVal == vecList[i]){
                    return false;
                }
            }

            for(int j = currSize - 1; j >= 0; j--){
                int diff = currSize - j;
                if(vecList[j] + diff == intVal || vecList[j] - diff == intVal){
                    return false;
                }
            }

            return true;
        }

        void addingEl(int* intArr, int size, vector<int>& vecList){
            if(vecList.size() == size){
                Final.push_back(vecList);
                return;
            }

            for(int i = 0; i < size; i++){
                if(!checkSafety(intArr[i], vecList)){
                    continue;
                }
                vecList.push_back(intArr[i]);
                addingEl(intArr, size, vecList);
                vecList.pop_back();
                
            }
        }
        void printVector(vector<int> vec){
            for(int i = 0; i < vec.size(); i++){
                cout << vec.at(i);
            }
            cout << endl;
        }
};


int main() {

    myClass myClass1;

    int intArr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *ptr = intArr;

    int size = sizeof(intArr)/sizeof(int);

    myClass1.checkCombination(ptr, size);

}