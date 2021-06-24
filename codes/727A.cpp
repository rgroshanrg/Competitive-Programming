#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define INT_MAX LONG_LONG_MAX
#define INT_MIN LONG_LONG_MIN
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define endl '/n'

const int MOD = 1'000'000'007;

void swap(int &, int &);
int modpow(int, int);



void solution() {

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    unordered_set<char> set;
    vector<int> A(n+1);
    A[1] = (int)s[1] - 96;
    set.insert(s[1]);
    for(int i = 2; i <= n; ++i) {
        if(set.find(s[i]) == set.end()) {
            A[i] = (int)s[i] - 96 + A[i-1];
            set.insert(s[i]);
        } else {
            A[i] = A[i-1];
        }
    }
    
    while(q--) {
        int l, r;
        cin >> l >> r;
        // unordered_map<pair<int, int>, int, hash_pair> M;
        int sum = A[r] + A[l];
        cout << sum << "\n";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // unordered_map<char, int> M;
    // for(int i = 97; i <= 122; ++i) {
    //     M[(char)i] = i-96;
    // }
    solution();

    return 0;
}

void swap(int &x, int &y) { 
    (x ^= y), (y ^= x), (x ^= y); 
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

