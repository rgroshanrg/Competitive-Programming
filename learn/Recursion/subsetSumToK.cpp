#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int i, vector<vector<int>> &ans, vector<int> tp, int n) {      
    
    if(i == arr.size()) {
        if(n == 0) {
            if(tp.size() > 0)
                ans.push_back(tp);
        }
        return;
    }
    
    solve(arr, i+1, ans, tp, n);
        tp.push_back(arr[i]);
        solve(arr, i+1, ans, tp, n-arr[i]);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> tp;
    solve(arr, 0, ans, tp , k);
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) 
        cin >> arr[i];
    
    int k; cin >> k;

    vector<vector<int>> ans = findSubsetsThatSumToK(arr, n, k);

    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}