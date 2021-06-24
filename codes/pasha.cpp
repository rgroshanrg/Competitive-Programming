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

    int n, a, b;
    cin >> n >> a >> b;
    set<int> ar;
    set<int> al;
    int in;
    for(int i = 0; i < a; ++i) {
        cin >> in;
        ar.insert(in);
    }
    for(int i = 0; i < b; ++i) {
        cin >> in;
        al.insert(in);
    }

    for(int i = 1; i <= n; ++i) {
        if(ar.find(i) != ar.end()) {
            cout << "1 ";
        } else if(al.find(i) != al.end()) {
            cout << "2 ";
        }
    }
    // cout << "\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    solution();

    // int _;
    // cin >> _;
    // while(_--) {
    //     solution();
    // }

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

