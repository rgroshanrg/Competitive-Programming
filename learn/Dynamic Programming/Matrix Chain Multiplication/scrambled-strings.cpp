#include<bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mp;


bool isScrambled(string a, string b) {
    if(a.length() != b.length())
        return false;
    if(a == b)
        return true;
    

    string check1 = a, check2 = b;
    sort(check1.begin(), check1.end());
    sort(check2.begin(), check2.end());
    if(check1 != check2)
        return false;
    

    string check = a + " " + b;
    if(mp.find(check) != mp.end())
        return mp[check];

    int n = a.length();
    bool flag = false;
    for(int i = 1; i < n; ++i) {
        bool cond1 = isScrambled(a.substr(0, i), b.substr(n-i, i)) && isScrambled(a.substr(i, n-i), b.substr(0, n-i));
        bool cond2 = isScrambled(a.substr(0, i), b.substr(0, i)) && isScrambled(a.substr(i, n-i), b.substr(i, n-i));
        if(cond1 || cond2) {
            flag = true;
            break;
        }
    }
    
    return mp[check] = flag;
}

int main() {
    string a, b; cin >> a >> b;
    int m = a.length();
    int n = b.length();
    if(isScrambled(a, b)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}