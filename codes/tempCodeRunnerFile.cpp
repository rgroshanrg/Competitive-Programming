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
    vector<int> arr(n);
    vector<int> brr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    for(int i = 0; i < n; ++i)
        cin >> brr[i];
    int found = 0;
    for(int i = 0; i < n; ++i) {
        if(found > 1) {
            cout << "NO\n";
            return;
        }
        if(arr[i] > brr[i]) {
            cout << "NO\n";
            return;
        }
        if(arr[i] < brr[i]) {
            found++;
            int k = brr[i]-arr[i];
            for(; i < n && brr[i]-arr[i] == k; ++i);
            
            i--;                    
        }
    }
    if(found > 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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

