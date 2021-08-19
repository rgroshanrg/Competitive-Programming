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
#define vvi     vector<vector<int>>
#define vpi     vector<pair<int, int>>
#define pi      pair<int, int>
#define uset    unordered_set
#define umap    unordered_map
#define pb      push_back
#define endl    '\n'

#define fo(i, n) for(int i = 0; i < n; ++i)

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " -> " << x << "\n";
#else
#define debug(...)
#endif

struct hash_pair { template <class T1, class T2> size_t operator()(const pair<T1, T2>& p) const  { auto h1 = hash<T1>{}(p.first); auto h2 = hash<T2>{}(p.second); return h1 ^ h2; } };

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

const int MOD = 1'000'000'007;
int modpow(int, int);


void solution() {

    // string s = "rckjdshfj";
    // string p = "jds";
    // cout << s.find(p);
    int64_t a = pow(2, 62);
    // cout << std::bitset<64>(a).to_string();
    cout<<a;
}


int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int _ = 1;


    // cin >> _;


    while(_--) {
        solution();
    }

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

