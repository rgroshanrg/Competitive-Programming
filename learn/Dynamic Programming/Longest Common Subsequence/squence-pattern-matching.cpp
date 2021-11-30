#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

int LCS(string x, string y, int m, int n) {
    for(int i = 0; i <= m; ++i)
        dp[i][0] = 0;
    for(int i = 0; i <= n; ++i)
        dp[0][i] = 0;
    
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m][n];
}

bool sequence_patter_matching(string x, string y, int m, int n) {
    return (m == LCS(x, y, m, n)) ? true : false;
}

int main() {
    string x, y; cin >> x >> y;
    int m = x.length();
    int n = y.length();
    cout << sequence_patter_matching(x, y, m, n) << "\n";
    return 0;
}