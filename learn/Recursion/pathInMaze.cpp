#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<bool>> &arr, string &s, int i, int j, int bi, int bj, vector<string> &ans, vector<vector<bool>> &temp) {
    int n = arr.size();
    int m = arr[0].size();
    if(i >= n || j >= m || i < 0 || j < 0)
        return;
    if(!arr[i][j] || temp[i][j]) {
        return;
    }
    if(i == n-1 && j == m-1) {
        if(s != "")
            ans.push_back(s);
        return;
    }
    int ni = i+1, nj = j;
    if(ni != bi || nj != bj) {
        s.push_back('D');
        temp[i][j] = true;
        solve(arr, s, ni, nj, i, j, ans, temp);
        s.pop_back();
        temp[i][j] = false;
    }
    ni = i; nj = j + 1;
    if(ni != bi || nj != bj) {
        s.push_back('R');temp[i][j] = true;
        solve(arr, s, ni, nj, i, j, ans, temp);
        s.pop_back();temp[i][j] = false;
    }
    ni = i-1; nj = j;
    if(ni != bi || nj != bj) {
        s.push_back('U');temp[i][j] = true;
        solve(arr, s, ni, nj, i, j, ans, temp);
        s.pop_back();temp[i][j] = false;
    }
    ni = i; nj = j - 1;
    if(ni != bi || nj != bj) {
        s.push_back('L');temp[i][j] = true;
        solve(arr, s, ni, nj, i, j, ans, temp);
        s.pop_back();temp[i][j] = false;
    }
}

vector<string> findAllPaths( vector<vector<bool>> &arr)
{
    //    Write your code here.
    string s = "";
    vector<string> ans;
    int n = arr.size();
    vector<vector<bool>> temp(n, vector<bool>(n, false));
    solve(arr, s, 0, 0, -1, -1, ans, temp);
    return ans;
}

int main () {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t; // test cases
    while(t--) {
        int n; cin >> n; // size
        vector<vector<bool>> arr(n, vector<bool>(n));
        int in;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> in;
                arr[i][j] = (bool)in;
            }
        }
        vector<string> ans = findAllPaths(arr);
        for(int i = 0 ; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}