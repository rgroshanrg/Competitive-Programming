#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

int iterative_countSubsets(vector<int> &arr, int n, int sum) {
    for(int i = 0; i <= sum; ++i)
        dp[0][i] = 0;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= sum; ++j) {
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    memset(dp, -1, sizeof(dp));

    int n, sum; cin >> n >> sum;
    vector<int> arr(n);
    for(int i = 0 ;i < n; ++i)
        cin >> arr[i];
        
    cout << iterative_countSubsets(arr, n, sum) << "\n";

    return 0;
}