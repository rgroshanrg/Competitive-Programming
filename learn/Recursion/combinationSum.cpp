#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int i, vector<vector<int>> &ans, vector<int> tp, int n) {
    
    if(n == 0) {
        if(tp.size()) {
            ans.push_back(tp);
        }
        return;
    }
    if(n < 0) {
        return;
    }
    if(i >= arr.size())
        return;
    
    solve(arr, i+1, ans, tp, n);
    tp.push_back(arr[i]);
    solve(arr, i, ans, tp, n-arr[i]);
}

vector<vector<int>> combSum(vector<int>& ARR, int B)
{
	// Write your code here
	// Return a vector of sorted vectors/combinations
    vector<vector<int>> ans;
    vector<int> tp;
    solve(ARR, 0, ans, tp, B);
    return ans;
}


int main () {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, b; cin >> n >> b;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        
        vector<vector<int>> ans = combSum(arr, b);
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i) {
            for(int j = 0; j < ans[i].size(); ++j) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

    }

    return 0;
}