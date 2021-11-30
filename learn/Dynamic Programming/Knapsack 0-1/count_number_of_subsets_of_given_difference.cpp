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



int cntSubsetsOfDiff(vector<int> &arr, int n, int diff) {
    int sum = 0;
    for(int &i : arr)
        sum += arr[i];
    return subsetCounts(arr, n, (diff+sum) >> 1 );
}

int main () {

    int n, diff; cin >> n >> diff;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    cout << cntSubsetsOfDiff(arr, n, diff) << "\n";

    return 0;
}