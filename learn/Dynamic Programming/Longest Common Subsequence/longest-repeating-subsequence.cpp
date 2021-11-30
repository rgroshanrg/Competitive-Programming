#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

int LRS(string x, string y, int m, int n) {
    for(int i = 0; i <= m; ++i)
        dp[i][0] = 0;
    for(int i = 0; i <= n; ++i)
        dp[0][i] = 0;

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(x[i-1] == y[j-1] && i != j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m][n];
}

int main() {
    string x; cin >> x;
    int n = x.length();
    cout << LRS(x, x, n, n) << "\n";
    return 0;
}
