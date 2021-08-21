#include <bits/stdc++.h>
using namespace std;

bool isvalid(int matrix[9][9], int x, int y, int id) {
    for(int j = 0; j < 9; ++j) {
        if(matrix[x][j] == id)
            return false;
    }
    for(int i = 0; i < 9; ++i) {
        if(matrix[i][y] == id)
            return false;
    }
    int r = (x/3)*3;
    int c = (y/3)*3;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0;j < 3; ++j) {
            if(matrix[r+i][c+j] == id)
                return false;
        }
    }
    return true;
}

void sudo(int matrix[9][9], int i, int j, int &vv) {
    if(i == 9) {
        vv = 1;
        return;
    }
    int ni = 0, nj = 0;
    if(j == 8) {
        ni = i+1; nj = 0;
    } else {
        ni = i;
        nj = j+1;
    }
    if(!matrix[i][j]) {
        for(int id = 1; id < 10; id++) {
            if(isvalid(matrix, i, j, id)) {
                matrix[i][j] = id;
                sudo(matrix, ni, nj, vv);
                matrix[i][j] = 0;
            }
        }
    } else {
        sudo(matrix, ni, nj, vv);
    }
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    int vv = 0;
    sudo(matrix, 0, 0, vv);
    return vv == 1;
}

int main() {
    int matrix[9][9] = {
        {9, 0, 0, 0, 2, 0, 7, 5, 0 },
        {6, 0, 0, 0, 5, 0, 0, 4, 0},
        {0, 2, 0, 4, 0, 0, 0, 1, 0 },
        {2, 0, 8, 0, 0, 0, 0, 0, 0},
        {0, 7, 0, 5, 0, 9, 0, 6, 0 },
        {0, 0, 0, 0, 0, 0, 4, 0, 1 },
        {0, 1, 0, 0, 0, 5, 0, 8, 0 },
        {0, 9, 0, 0, 7, 0, 0, 0, 4 },
        {0, 8, 2, 0, 4, 0, 0, 0, 6}
    };
    cout << isItSudoku(matrix) << "\n";
    return 0;
}