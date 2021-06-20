#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
const int MOD = 1'000'000'007;
void swap(int &, int &);
int modpow(int, int);


void solution() {
    int n;
    cin >> n;
    int pi;
    int firstMax = LONG_LONG_MIN, secondMax = LONG_LONG_MIN;
    int firstIdx = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> pi;
        if(firstMax < pi) {
            secondMax = firstMax;
            firstMax = pi, firstIdx = i;
        } else if(secondMax < pi && firstMax > pi) {
            secondMax = pi;
        }
    }
    cout << firstIdx << " " << secondMax;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

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

