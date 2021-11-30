#include <bits/stdc++.h>
using namespace std;

// No. of ways to make Sum.

const int N = 1e3;
int dp[N][N];

int iterative_coin_change(vector<int> &coins, int &n, int &sum) {
    for(int i = 1; i <= sum; ++i)
        dp[0][i] = 0;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= sum; ++j) {
            if(coins[i-1] <= j) 
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main() {
    int n; cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i)
        cin >> coins[i];
    int sum; cin >> sum;
    cout << iterative_coin_change(coins, n, sum);
    return 0;
}