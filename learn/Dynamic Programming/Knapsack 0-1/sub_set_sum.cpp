#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int dp[N][N];

// Recursive

bool subset(vector<int> &arr, int sum, int n) {
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    if(dp[n][sum] != -1)
        return dp[n][sum];
    if(sum >= arr[n-1])
        return dp[n][sum] = subset(arr, sum-arr[n-1], n-1) || subset(arr, sum, n-1);
    return dp[n][sum] = subset(arr, sum, n-1);
}

// Iterative

bool iterative_subset(vector<int> &arr, int sum, int n) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= sum; ++j) {
            if(j - arr[i-1] >= 0)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, sum; cin >> n >> sum;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    for(int i = 0; i <= sum; ++i)
        dp[0][i] = 0;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 1;

    if(subset(arr, sum, n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}