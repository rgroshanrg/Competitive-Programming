#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

int recursive_lcs(string x, string y, int m, int n) {
    if(m == 0 || n == 0)
        return 0;
    if(dp[m][n] != -1)
        return dp[m][n];
    if(x[m-1] == y[n-1])
        return dp[m][n] = 1 + recursive_lcs(x, y, m-1, n-1);
    return dp[m][n] = max( recursive_lcs(x, y, m, n-1), recursive_lcs(x, y, m-1, n) );
}

int iterative_lcs(string x, string y, int m, int n) {
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

string printLCS(string x, string y, int m, int n) {
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
    string s = "";
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(x[i-1] == y[j-1]) {
            s.push_back(x[i-1]);
            i--, j--;
        } else if(dp[i][j-1] > dp[i-1][j])
            j--;
        else
            i++;
    }
    reverse(s.begin(), s.end());
    // cout << s << "\n";
    return s;
}

int main() {
    string x, y; cin >> x >> y;
    int m = x.length(), n = y.length();
    memset(dp, -1, sizeof(dp));

    cout << printLCS(x, y, m, n) << "\n";

    return 0;
}