#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
bool dp[N][N];

vector<bool> subsetsSums(vector<int> &arr, int n, int sum) {
    for(int i = 0; i <= sum; ++i)
        dp[0][i] = false;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = true;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= sum; ++j) {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    vector<bool> ans((sum >> 1)+1);
    for(int i = 0; i <= (sum>>1); ++i)
        ans[i] = dp[n][i];
    return ans;
}

int iterative_minSubsetSumDiff(vector<int> &arr, int n) {
    int sum = 0;
    for(int i : arr)
        sum += i;
    vector<bool> validSums = subsetsSums(arr, n, sum);
    int size = validSums.size();
    for(int i = size-1; i >= 0; --i) {
        if(validSums[i])
            return abs(sum - (i << 1));
    }
    return 0;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    cout << iterative_minSubsetSumDiff(arr, n) << "\n";
    
    return 0;
}