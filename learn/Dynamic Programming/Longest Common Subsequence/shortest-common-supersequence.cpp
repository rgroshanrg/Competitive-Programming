#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];


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

// First Approach

int SCS(string x, string y, int m, int n) {
    return m + n - iterative_lcs(x, y, m, n);
}

// Second Approach

int iterative_SCS(string x, string y, int m, int n) {
    for(int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for(int i = 0; i <= n; ++i)
        dp[0][i] = i;
    
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = min(dp[i-1][j-1] + 2, min(dp[i][j-1] + 1, dp[i-1][j] + 1));
        }
    }
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return dp[m][n];
}

// Print FCS

string printSCS(string x, string y, int m, int n) {
    for(int i = 0; i <= m; ++i)
        dp[i][0] = 0;
    for(int i = 0; i <= n; ++i)
        dp[0][i] = 0;
    // LCS code
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    int i = m, j = n;
    string s = "";
    while(i > 0 && j > 0) {
        if(x[i-1] == y[j-1]) {
            s.push_back(x[i-1]);
            i--, j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            s.push_back(x[i-1]);
            i--;
        } else {
            s.push_back(y[j-1]);
            j--;
        }
    }
    while(i > 0) s.push_back(x[i-1]), i--;
    while(j > 0) s.push_back(y[j-1]), j--;
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string x, y; cin >> x >> y;
    int m = x.length(), n = y.length();
    memset(dp, -1, sizeof(dp));

    cout << printSCS(x, y, m, n) << "\n";

    return 0;
}