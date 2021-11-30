#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int dp[N][N];

bool isPalindrome(string &s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}

int msp(string &s, int i, int j) {
    if(i >= j) return 0;
    if(isPalindrome(s, i, j)) return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;

    for(int k = i; k < j; ++k) {
        mn = min(mn, 1 + msp(s, i, k) + msp(s, k+1, j));
    }
    return dp[i][j] = mn;
}

int optimised_msp(string &s, int i, int j) {
    if(i >= j) return 0;
    if(isPalindrome(s, i, j)) return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;

    for(int k = i; k < j; ++k) {
        int left, right;
        if(dp[i][k] != -1)
            left = dp[i][k];
        else 
            left = dp[i][k] = optimised_msp(s, i, k);
        if(dp[k+1][j] != -1)
            right = dp[k+1][j];
        else
            right = dp[k+1][j] = optimised_msp(s, k+1, j);
        mn = min(mn, 1 + left + right);
    }
    return dp[i][j] = mn;
}

int main() {
    string s; cin >> s;
    int n = s.length();
    memset(dp, -1, sizeof dp);
    cout << optimised_msp(s, 0, n-1) << "\n";
    return 0;
}