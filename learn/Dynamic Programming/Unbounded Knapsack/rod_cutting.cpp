#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dp[N][N];

int iterative_rod_cut(vector<int> &lengths, vector<int> &prices, int &n) {
    int maxlen = *max_element(lengths.begin(), lengths.end());
    for(int i = 0; i <= maxlen; ++i)
        dp[0][i] = 0;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= maxlen; ++j) {
            if(lengths[i-1] <= j) 
                dp[i][j] = max(prices[i-1] + dp[i][j - lengths[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][maxlen];
}

int main() {
    int n; cin >> n;
    vector<int> lengths(n);
    for(int i = 0; i < n; ++i)
        cin >> lengths[i];
    vector<int> prices(n);
    for(int i = 0; i < n; ++i)
        cin >> prices[i];
    cout << iterative_rod_cut(lengths, prices, n);
    return 0;
}