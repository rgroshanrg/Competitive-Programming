#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define INT_MAX LONG_LONG_MAX
#define INT_MIN LONG_LONG_MIN
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define endl '\n'

const int MOD = 1'000'000'007;

void swap(int &, int &);
int modpow(int, int);


void solution() {

    int n;
    cin >> n;
    if(n & 1) {
        for(int i = 2; i < n-2; i += 2) {
            cout << i << " " << i-1 << " ";
        }
        cout << n-1 << " " << n << " " << n-2 << " ";
    } else {
        for(int i = 2; i <= n; i += 2) {
            cout << i << " " << i-1 << " ";
        }
    }
    cout << "\n";
    
}

// This Code is written by : https://codeforces.com/profile/rgroshanrg 

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _;
    cin >> _;
    while(_--) {
        solution();
    }

    // solution();

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

