#include <bits/stdc++.h>
using namespace std;

#define int     long long int
#define LL_MAX  LONG_LONG_MAX
#define LL_MIN  LONG_LONG_MIN
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x)  memset(x, 0, sizeof(x))
#define PI      3.1415926535897932384626
#define vi      vector<int>
#define vii     vector<vector<int>>
#define pii     pair<int, int>
#define uset    unordered_set
#define umap    unordered_map
#define pb      emplace_back
#define endl    '\n'
#define debug(x) cout << #x << " -> " << x << "\n";


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

const int MOD = 1'000'000'007;
int modpow(int, int);


void solution() {



}


int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int _;
    cin >> _;
    while(_--) {
        solution();
    }

    // solution();

    return 0;
}

int modpow(int base, int exp) {
    base %= MOD;
    int result = 1;
        while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

