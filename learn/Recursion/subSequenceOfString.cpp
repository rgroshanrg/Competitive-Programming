#include<bits/stdc++.h>
using namespace std;

void solve(string str, string tp, vector<string> &ans) {
    if(str == "") {
        if(tp != "")
        	ans.push_back(tp);
        return;
    }
    solve(str.substr(1), tp+str[0], ans);
    solve(str.substr(1), tp, ans);
    
}

// Recursion
vector<string> subsequences(string str){
	
	// Write your code here
    vector<string> ans;
    string tp = "";
    solve(str, tp, ans);
    return ans;
	
}

// Using Bitmasking
vector<string> subsequences1(string str){
	
	// Write your code here
    int n = str.length();
    int lim = pow(2, n);
    vector<string> ans;
    for(int i = 1; i < lim; ++i) {
        string s = "";
        for(int j = 0; j < n; ++j) {
            if(i & (1 << j)) {
                s.push_back(str[j]);
            }
        }
        ans.push_back(s);
    }
    return ans;
	
}


int main () {
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        vector<string> ans = subsequences(str);
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}