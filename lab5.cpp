/*
Implement N Queen’s problem using Back Tracking 
*/
#include <iostream>
using namespace std;
int solutionCount = 0;
bool issafe(int **arr, int x, int y, int n) {
    for (int row = 0; row < x; row++) {
        if (arr[row][y] == 1) {
            return false;
        }
    }
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0) {
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }
    row = x;
    col = y;
    while (row >= 0 && col < n) {
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col++;
    }
    return true;
}
void nqueen(int **arr, int x, int n) {
    if (x == n) {
        cout << "Solution " << ++solutionCount << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (issafe(arr, x, col, n)) {
            arr[x][col] = 1;
            nqueen(arr, x + 1, n);
            arr[x][col] = 0;
        }
    }
}

int main() {
    cout << "Enter the size of the board (N for N x N board):\n";
    int n;
    cin >> n;

    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    nqueen(arr, 0, n);

    if (solutionCount == 0) {
        cout << "No solutions exist.\n";
    } else {
        cout << "Total number of solutions: " << solutionCount << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0; 
}
