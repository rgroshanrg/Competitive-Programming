#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

int iterative_unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W) {
    for(int i = 0; i <= W; ++i)
        dp[0][i] = 0;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 0;

    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= W; ++j) {
            if(wt[i-1] <= j)
                dp[i][j] = max( dp[i-1][j], val[i] + dp[i][j - wt[i]] );
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main() {

    int n, W; cin >> n >> W;
    vector<int> weight(n);
    vector<int> values(n);
    for(int i = 0; i < n ; ++i)
        cin >> weight[i];
    for(int i = 0; i < n ; ++i)
        cin >> values[i];
    
    cout << iterative_unboundedKnapsack(weight, values, n, W) << "\n";

    return 0;
}