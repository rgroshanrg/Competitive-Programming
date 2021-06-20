#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define INF LONG_LONG_MAX
#define NEG_INF LONG_LONG_MIN
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define endl '/n'

const int MOD = 1'000'000'007;

void swap(int &, int &);
int modpow(int, int);


void solution() {
    int n;
    cin >> n;
    vector<int> H(n);
    for(int i = 0; i < n; ++i) {
        cin >> H[i];
    }
    sort(all(H));
    int minDiff = INF;
    int minIdx;
    for(int i = 0; i < n-1; ++i) {
        if(H[i+1]-H[i] < minDiff) {
            minDiff = H[i+1]-H[i];
            minIdx = i;
        }
        if(minDiff == 0)
            break;
    }
    cout << H[minIdx] << " ";
    for(int i = minIdx+2; i < n; ++i){
        cout << H[i] << " ";
    }
    for(int i = 0; i < minIdx; ++i)
        cout << H[i] << " ";
    cout << H[minIdx+1];
    cout << "\n";   

}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _;
    cin >> _;
    while(_--) {
        solution();
    }

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

