#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int dp[N][N][2];

int bool_parenthesize_ways(string &s, int i, int j, bool findTrue) {
    if(i > j) return 0;
    if(i == j) {
        if(findTrue)
            return s[i] == 'T';
        return s[i] == 'F';
    }
    if(dp[i][j][findTrue] != -1)
        return dp[i][j][findTrue];

    int ans = 0;
    for(int k = i+1; k < j; k += 2) {
        int left_true = bool_parenthesize_ways(s, i, k-1, true);
        int right_true = bool_parenthesize_ways(s, k+1, j, true);
        int left_false = bool_parenthesize_ways(s, i, k-1, false);
        int right_false = bool_parenthesize_ways(s, k+1, j, false);
        
        if(s[k] == '&') {
            if(findTrue)
                ans += left_true*right_true;
            else
                ans += (left_false * right_false) + (left_false * right_true) + (left_true * right_false);
        } else if(s[k] == '|') {
            if(findTrue)
                ans += (left_true * right_true) + (left_false * right_true) + (left_true * right_false);
            else
                ans += left_false * right_false;
        } else if(s[k] == '^') {
            if(findTrue)
                ans += (left_true * right_false) + (left_false * right_true);
            else
                ans += (left_true * right_true) + (left_false * right_false);
        }

    }
    return dp[i][j][findTrue] = ans;

}

int main() {
    string s; cin >> s;
    int n = s.length();
    memset(dp, -1, sizeof dp);
    cout<< bool_parenthesize_ways(s, 0, n-1, true);
    return 0;
}