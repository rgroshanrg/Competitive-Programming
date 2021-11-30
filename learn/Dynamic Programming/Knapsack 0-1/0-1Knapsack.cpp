#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;

int dp[N][N];

// Recursive

int knapsack(vector<int> &wt, vector<int> &val, int W, int n) {
    if(W == 0 || n == 0)
        return 0;
    if(dp[n][W] != -1)
        return dp[n][W];
    if(wt[n-1] <= W)
        return dp[n][W] = max(val[n-1] + knapsack(wt, val, W - wt[n-1], n-1), knapsack(wt, val, W, n-1));
    
    return dp[n][W] = knapsack(wt, val, W, n-1);
}

// Iterative (Top - Down)

int knapsack_iterative(vector<int> &wt, vector<int> &val, int W, int n) {
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for(int i = 0; i <= W; ++i)
        dp[0][i] = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= W; ++j) {
            if(wt[i-1] <= j) 
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}

int main() {
    
    memset(dp, -1, sizeof(dp));
    int W; cin >> W;
    int n; cin >> n;
    vector<int> weight(n);
    vector<int> value(n);

    for(int i = 0; i < n; ++i)
        cin >> weight[i];
    for(int i = 0; i < n ; ++i)
        cin >> value[i];

    int ans = knapsack(weight, value, W, n);

    cout << ans << "\n";

    return 0;
}