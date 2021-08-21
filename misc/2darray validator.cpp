#include <bits/stdc++.h>
using namespace std;

bool isvalid(pair<int, int> point, int rows, int cols) {    // coordinate validation checker
    if(point.first < 0 || point.second < 0)
        return false;
    if(point.first >= rows || point.second >= cols)
        return false;
    return true;
}

main () {
    vector<int> dr = {-1, 1, 0, 0, -1, 1, -1, 1 };      // rows validators
    vector<int> dc = { 0, 0, 1,-1, -1, 1, 1, -1 };      // cols validators
    

    // for all neighbours
    int i, j;
    int n, m;
    for(int id = 0; id < 8; ++id) {
        int r = i + dr[id];         // i is current row number
        int c = j + dr[id];         // j is current column number
        // access : arr[r][c]
        if(isvalid({r, c}, n, m)) {     // n is total number of rows, m is total number of columns

        }
    }

    //for only up, down, right, left
    int i, j;
    int n, m;
    for(int id = 0; id < 4; ++id) {
        int r = i + dr[id];         // i is current row number
        int c = j + dr[id];         // j is current column number
        // access : arr[r][c]
        if(isvalid({r, c}, n, m)) {     // n is total number of rows, m is total number of columns

        }
    }
}