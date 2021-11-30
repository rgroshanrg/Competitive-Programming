#include<bits/stdc++.h>
using namespace std;

int dp[1500][1500];

bool subSetSum(vector<int> &arr, int n, int sum) {
    for(int i = 0; i <= sum; ++i) 
        dp[0][i] = 0;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= sum; ++j) {
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

bool iterative_equalSumPart(vector<int> &arr, int n) {
    long long int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += arr[i];
    if(sum & 1)
        return false;
    
    return subSetSum(arr, n, (sum >> 1));
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    if( iterative_equalSumPart(arr, n) ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}