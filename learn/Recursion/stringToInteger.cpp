#include <bits/stdc++.h>
using namespace std;

void strtoi(string s, int &ans, int n) {
    if(n == -1)
        return;
    strtoi(s, ans, n-1);
    ans = (ans*10) + (int)(s[n] - '0');
}

int main() {
    int ans = 0;
    strtoi("765", ans, 2) ;
    cout << ans << "\n";        // 720

    return 0;
}