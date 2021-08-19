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

void dfs(vector<int> G[], vi &dp, uset<int> &set, int i) {
    if(dp[i] == 1)
        return;
    set.insert(i);
    dp[i] = 1;
    for(int j = 0; j < G[i].size(); ++j) {
        if(dp[G[i][j]] == 0) {
            set.insert(j);
            dp[G[i][j]] = 1;
            dfs(G, dp, set, G[i][j]);
        }
    }
}

void solution() {

    int n; cin >> n;
    int m1, m2; cin >> m1 >> m2;
    int u, v;
    vector<int> G1[n];
    vector<int> G2[n];
    fo(i, m1) {
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    fo(i, m2) {
        cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
    }
    vector<uset<int>> dset1;
    vector<uset<int>> dset2;
    vi dp(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        if(dp[i] == 0) {
            uset<int> set;
            dfs(G1, dp, set, i);
            dset1.push_back(set);
        }
    }
    vi dp1(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        if(dp[i] == 0) {
            uset<int> set;
            dfs(G1, dp1, set, i);
            dset2.push_back(set);
        }
    }

    vpi ans;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            bool fl = false;
            for(int k = 0; k < dset1.size(); ++k) {
                if(dset1[k].find(i) != dset1[k].end() && dset1[k].find(j) != dset1[k].end()) {
                    fl = true; break;
                }
            }
            if(!fl) {
                for(int k = 0; k < dset2.size(); ++k) {
                    if(dset2[k].find(i) != dset2[k].end() && dset2[k].find(j) != dset2[k].end()) {
                        fl = true; break;
                    }
                }
            }
            if(!fl) {
                ans.push_back({i, j});
                int posi = 0;
                int posj = 0;
                for(int k = 0; k < dset1.size(); ++k) {
                    if(dset1[k].find(i) != dset1[k].end()) {
                        posi = k; break;
                    }
                }
                for(int k = 0; k < dset1.size(); ++k) {
                    if(dset1[k].find(j) != dset1[k].end()) {
                        posj = k; break;
                    }
                }
                dset1[posi].insert(all(dset1[posj]));
                dset1.erase(dset1.begin()+posj);
                 posi = 0;
                 posj = 0;
                for(int k = 0; k < dset2.size(); ++k) {
                    if(dset2[k].find(i) != dset2[k].end()) {
                        posi = k; break;
                    }
                }
                for(int k = 0; k < dset2.size(); ++k) {
                    if(dset2[k].find(j) != dset2[k].end()) {
                        posj = k; break;
                    }
                }
                dset2[posi].insert(all(dset2[posj]));
                dset2.erase(dset2.begin()+posj);

            }
        }
    }
    cout << ans.size() << "\n";
    for(auto i : ans) {
        cout << i.first << " " << i.second << "\n";
    }

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

