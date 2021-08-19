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



    // if(s[sr] != p[pr]) {
    //     sr = slen, pr = plen;
    // }

    // if(sr == slen-1) {
    //     while(s[sr] == p[pr] && sr > sl && pr > pl) {
    //         sr--; pr--;
    //     }
    //     sr++; pr++;
    // }

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

const int MOD = 1'000'000'007;
int modpow(int, int);

int help(int no, int pow) {
    if(no == pow)
        return 0;
    string s = to_string(no);
    string p = to_string(pow);
    int slen = s.length();
    int plen = p.length();
    int sl = 0, sr = slen-1, pl = 0, pr = plen-1;
    if(s[sl] != p[pl]) {
        sl = -1; pl = -1;
    }
    if(sl == 0) {
        while(s[sl] == p[pl] && sl < slen && pl < plen) {
            sl++; pl++;
        }
        sl--; pl--;
        if(pl == plen-1) {
            return (slen-sl-1);
        }
        if(sl == slen-1) {
            return (plen-sl-1);
        }

        s = s.substr(sl+1);
        p = p.substr(sl+1);
    }
    int n = p.length();
    for(int i = n; i > 0; --i) {
        string subp = p.substr(0, i);
        if(s.find(subp) != string::npos) {
            int idx = s.find(subp);
            int cnt = idx;
            cnt += s.length() - (idx + subp.length());
            cnt += ( p.length() - (i) );
            return cnt;
        }
    }

    return (s.length() + p.length());

}

void solution() {

    int n; cin >> n;
    vector<int64_t> dp(62);
    for(int64_t i = 0; i < 62; ++i) {
        dp[i] = pow(2, i);
    }
    for(int i = 0; i < 62; ++i) {
        cout << dp[i] << " ";
    }
    int cnt = LL_MAX;
    int tp;
    for(int i = 0; i < 62; ++i) {
        // cnt = min(cnt, help(n, dp[i]) );

        if(cnt >= help(n, dp[i])) {
            cnt = help(n, dp[i]);
            tp = dp[i];
        }
    }
    debug(tp);
    // cout << help(n, 1);
    cout << cnt << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int _ = 1;


    cin >> _;


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

