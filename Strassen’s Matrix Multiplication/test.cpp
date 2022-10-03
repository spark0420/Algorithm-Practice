#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void printMatrix(vector< vector<int> > matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j != 0) {
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void add(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassenR(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else {
        int newSize = size/2;
        vector<int> inner (newSize);
        vector< vector<int> > a11(newSize,inner),
                            a12(newSize,inner),
                            a21(newSize,inner),
                            a22(newSize,inner),
                            b11(newSize,inner),
                            b12(newSize,inner),
                            b21(newSize,inner),
                            b22(newSize,inner),
                            c11(newSize,inner),
                            c12(newSize,inner),
                            c21(newSize,inner),
                            c22(newSize,inner),
                            s1(newSize,inner),
                            s2(newSize,inner),
                            s3(newSize,inner),
                            s4(newSize,inner),
                            s5(newSize,inner),
                            s6(newSize,inner),
                            s7(newSize,inner),
                            s8(newSize,inner),
                            s9(newSize,inner),
                            s10(newSize,inner),
                            p1(newSize,inner),
                            p2(newSize,inner),
                            p3(newSize,inner),
                            p4(newSize,inner),
                            p5(newSize,inner),
                            p6(newSize,inner),
                            p7(newSize,inner),
                            tempA(newSize,inner),
                            tempB(newSize,inner);

        int i, j;

        for (i = 0; i < newSize; i++) {
            for (j = 0; j < newSize; j++) {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + newSize];
                a21[i][j] = A[i + newSize][j];
                a22[i][j] = A[i + newSize][j + newSize];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + newSize];
                b21[i][j] = B[i + newSize][j];
                b22[i][j] = B[i + newSize][j + newSize];
            }
        }

        subtract(b12, b22, s1, newSize); //s1 = b12-b22
        strassenR(a11, s1, p1, newSize); //p1 = a11 * s1

        add(a11, a12, s2, newSize); // s2 = a11 + a12
        strassenR(s2, b22, p2, newSize); //p2 = s2 * b22

        add(a21, a22, s3, newSize); // s3 = a21 + a22
        strassenR(s3, b11, p3, newSize); // p3 = s3 * b11

        subtract(b21, b11, s4, newSize); //s4 = b21 - b11
        strassenR(a22, s4, p4, newSize); //p4 = a22 * s4

        add(a11, a22, s5, newSize); //s5 = a11 + a22
        add(b11, b22, s6, newSize); //s6 = b11 + b22
        strassenR(s5, s6, p5, newSize); // p5 = s5 * s6

        subtract(a12, a22, s7, newSize); //s7 = a12 - a22
        add(b21, b22, s8, newSize); //s8 = b21 + b22
        strassenR(s7, s8, p6, newSize);// p6 = s7 * s8

        subtract(a11, a21, s9, newSize);//s9 = a11 - a21
        add(b11, b12, s10, newSize); //s10 = b11 + b12
        strassenR(s9, s10, p7, newSize); //p7 = s9 * s10

        // c11 = p5 + p4 - p2 + p6
        add(p5, p4, tempA, newSize); // p5 + p4
        add(tempA, p6, tempB, newSize); // (p5 + p4) + p6
        subtract(tempB, p2, c11, newSize); // (p5 + p4 + p6) - p2

        // c12 = p1 + p2
        add(p1, p2, c12, newSize);

        // c21 = p3 + p4
        add(p3, p4, c21, newSize);

        // c22 = p5 + p1 - p3 + p7
        add(p5, p1, tempA, newSize); // p5 + p1
        subtract(tempA, p3, tempB, newSize); // (p5 + p1) - p3
        subtract(tempB, p7, c22, newSize); // (p5 + p1 - p3) - p7

        for (i = 0; i < newSize ; i++) {
            for (j = 0 ; j < newSize ; j++) {
                C[i][j] = c11[i][j];
                C[i][j + newSize] = c12[i][j];
                C[i + newSize][j] = c21[i][j];
                C[i + newSize][j + newSize] = c22[i][j];
            }
        }
    }
}

bool checkPowerOfTwo(int n) {
    if (n == 0){
        return false;
    }

    return (ceil(log2(n)) == floor(log2(n)));
}

void strassen(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int n) {
    bool powerofTwo = false;

    if(!checkPowerOfTwo(n)){
        cout << "Both matrix have to be n x n, and n has to be power of 2!" << endl;
        return;
    }else{
        strassenR(A, B, C, n);
    }  
}


int main () {
    // int n = 4;
    // vector<vector<int> > A { { 1, 1, 1, 1 },
    //                             { 2, 2, 2, 2 },
    //                             { 3, 3, 3, 3 },
    //                             { 2, 2, 2, 2 } };
    
    // vector<vector<int> > B { { 1, 1, 1, 1 },
    //                             { 2, 2, 2, 2 },
    //                             { 3, 3, 3, 3 },
    //                             { 2, 2, 2, 2 } };
    int n = 8;
    vector<vector<int> > A { { 1, 1, 1, 1, 1, 1, 1, 1},
                                { 2, 2, 2, 2, 2, 2, 2, 2 },
                                { 3, 3, 3, 3, 3, 3, 3, 3 },
                                { 4, 4, 4, 4, 4, 4, 4, 4 },
                                { 5, 5, 5, 5, 5, 5, 5, 5 },
                                { 4, 4, 4, 4, 4, 4, 4, 4 },
                                { 3, 3, 3, 3, 3, 3, 3, 3 },
                                { 2, 2, 2, 2, 2, 2, 2, 2 } };
    
    vector<vector<int> > B { { 1, 1, 1, 1, 1, 1, 1, 1},
                                { 2, 2, 2, 2, 2, 2, 2, 2 },
                                { 3, 3, 3, 3, 3, 3, 3, 3 },
                                { 4, 4, 4, 4, 4, 4, 4, 4 },
                                { 5, 5, 5, 5, 5, 5, 5, 5 },
                                { 4, 4, 4, 4, 4, 4, 4, 4 },
                                { 3, 3, 3, 3, 3, 3, 3, 3 },
                                { 2, 2, 2, 2, 2, 2, 2, 2 } };

    vector<int> inner(n, 0);
    vector<vector<int> > C(n, inner);

    strassen(A, B, C, n);
    printMatrix(C, n);
    return 0;
}