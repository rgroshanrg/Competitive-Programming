#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;

int dp[N][N];

int eggDropping(int e, int f) {
    if(f == 0 || f == 1 || e == 1)
        return f;
    if(dp[e][f] != -1)
        return dp[f][e];
    
    int mn = INT_MAX;
    for(int k = 1; k <= f; ++k) {
        int down, up;
        if(dp[e-1][k-1] != -1) down = dp[e-1][k-1];
        else down = dp[e-1][k-1] = eggDropping(e-1, k-1);

        if(dp[e][f-k] != -1) up = dp[e][f-k];
        else up = dp[e][f-k] = eggDropping(e, f-k);

        int temp = 1 + max(down, up);

        mn = min(mn, temp);
        
    }

    return dp[e][f] = mn;
}

int main() {
    int f, e; cin >> f >> e;
    memset(dp, -1, sizeof dp);
    cout << eggDropping(e, f) << "\n";
    return 0;
}
