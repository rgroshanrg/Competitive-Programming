#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

// Function to count number of possible subsets of a given sum

int subsetCounts(vector<int> &arr, int n, int sum) {
    for(int i = 0; i <= sum; ++i)
        dp[0][i] = 0;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= sum; ++j) {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}



int targetSum(vector<int> &arr, int n, int sum) {       // sum == diff of cnt no. of subset sum of given diffence problem
    int tsum = 0;
    for(int &i : arr)
        tsum += arr[i];
    return subsetCounts(arr, n, (sum+tsum) >> 1 );
}

int main () {

    int n, sum; cin >> n >> sum;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    cout << targetSum(arr, n, sum) << "\n";

    return 0;
}