#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

int recursive_mcm(vector<int> &arr, int i, int j) {
    if(i >= j) 
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int min_total_cost = INT_MAX;

    for(int k = i; k < j; ++k) {
        int left_matrix_cost = recursive_mcm(arr, i, k);
        int right_matrix_cost = recursive_mcm(arr, k+1, j);
        int left_into_right_matrix_cost = arr[i-1] * arr[k] * arr[j];
        int total_cost = left_matrix_cost + right_matrix_cost + left_into_right_matrix_cost;
        min_total_cost = min(min_total_cost, total_cost);
    }

    return dp[i][j] = min_total_cost;
}

int iterative_mcm(vector<int> &arr, int n) {
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            if(i >= j)
                dp[i][j] = 0;
    for(int l = 2; l < n; ++l) {
        for(int i = 1; i < n-l+1; ++i) {
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; ++k) {
                int temp = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
                if(temp < dp[i][j])
                    dp[i][j] = temp;
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << iterative_mcm(arr, n) << "\n";
    return 0;
}