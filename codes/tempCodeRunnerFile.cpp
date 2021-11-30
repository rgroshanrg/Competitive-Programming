#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dp[1001][1001][2];
    bool solve(int n, bool alice, vector<set<int>> &div)  {
        
        if(n <= 0) {
            if(alice) return false;
            return true;
        }
        
        for(int i : div[n]) {
            bool ans;
            if(dp[n][i][alice] != -1)
                ans = dp[n][i][alice];
            else {
                ans = dp[n][i][alice] = solve(n-i, !alice, div);
            }
            if(alice) {
                if(ans) {
                    return ans;
                }
            } else {
                if(!ans) {
                    return ans;
                }
            }
        }
        if(dp[n][*div[n].rbegin()][alice] != -1)
            return dp[n][*div[n].rbegin()][alice] ;
        return dp[n][*div[n].rbegin()][alice] = solve(n - ( *div[n].rbegin() ), !alice,  div);
    }
    bool divisorGame(int n) {
        // vector<vector<vector<int>>> dp(1001, vector<vector<int>> (1001, vector<int> (2, -1)));
        
        memset(dp, -1, sizeof dp);
        vector<set<int>> div(n+1);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j*j <= n; ++j) {
                if(i % j == 0) {
                    int d = i/j;
                    if(j >= 1 && j < i)
                        div[i].insert(j);
                    if(d >= 1 && d < i)
                        div[i].insert(d);
                }
            }
        }
        
        return solve(n, true, div);
    }
};


int main() {

    int n; cin >> n;

    Solution s;
    cout << s.divisorGame(n) << "\n";

    return 0;
}