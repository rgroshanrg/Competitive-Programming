#include <bits/stdc++.h>
using namespace std; 

void solve(string s, string ts, vector<string> &ans) {
    if(s.length() == 0) {
        ans.push_back(ts);
        return;
    }
    int len = s.length();
    
    for(int i = 0; i < len; ++i) {
        string f = "";
        for(int j = 0; j < i; ++j)
            f.push_back(s[j]);
        string se = "";
        for(int j = i+1; j < len; ++j)
            se.push_back(s[j]);
        solve(f+se, ts+s[i], ans);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    string ts = "";
    solve(s, ts, ans);
    return ans;
}

int main () {
    string s; cin >> s;
    vector<string> ans = findPermutations(s);
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";
}