#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

int longest_common_sustring(string x, string y, int m, int n) {
    for(int i = 0; i <= m; ++i)
        dp[i][0] = 0;
    for(int i = 0; i <= n; ++i)
        dp[0][i] = 0;
    
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 0;
        }
    }
    return dp[m][n];
}

int main() {
    string x, y; cin >> x >> y;
    int m = x.length(), n = y.length();
    cout << longest_common_sustring(x, y, m, n) << "\n";
    return 0;
}