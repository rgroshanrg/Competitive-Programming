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

    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(all(arr));
    vector<int> brk;
    for(int i = 1; i < n; ++i) {
        if(arr[i] - arr[i-1] > x) {
            if((arr[i]-arr[i-1]) % x == 0)
                brk.push_back(((arr[i]-arr[i-1])/x)-1);
            else
                brk.push_back((arr[i]-arr[i-1])/x);
        }
    }
    sort(all(brk));
    int count = brk.size() + 1;
    for(int i = 0; i < brk.size(); ++i) {
        if(k-brk[i] >= 0) {
            k -= brk[i];
            count--;
        } else {
            break;
        }
    }
    cout << count;
    
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

