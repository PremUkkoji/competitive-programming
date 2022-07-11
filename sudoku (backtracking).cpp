#include<bits/stdc++.h>
using namespace std;

#define N 9
#define unassigned 0

bool existsInRowCol(int grid[N][N], int row, int col, int num) {
    for (int itr = 0; itr < N; itr++) {
        if (grid[row][itr] == num)
            return true;
        if (grid[itr][col] == num)
            return true;
    }
    return false;
}

bool existsIn3X3(int grid[N][N], int row, int col, int num) {
    int rs = row - (row % 3);
    int cs = col - (col % 3);
    for (int i = rs; i < rs + 3; i++) {
        for (int j = cs; j < cs + 3; j++) {
            if (grid[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    return !existsInRowCol(grid, row, col, num) && !existsIn3X3(grid, row, col, num);
}

bool isUnassignedLocationExists(int grid[N][N], int &row, int &col) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == unassigned) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool sudoku(int grid[N][N]) {
    int row, col;

    if (!isUnassignedLocationExists(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (sudoku(grid))
                return true;

            grid[row][col] = unassigned;
        }
    }
    return false;
}

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 0 means unassigned cells
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (sudoku(grid))
        printGrid(grid);
    else
        cout << "Solution doesn't exists";

    return 0;
}
