#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define LL_MAX LONG_LONG_MAX
#define LL_MIN LONG_LONG_MIN
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define endl '/n'

const int MOD = 1'000'000'007;

void swap(int &, int &);
int modpow(int, int);


void solution() {

    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    int min = LL_MAX;
    int max = LL_MIN;
    int leftMinidx, leftMaxidx;
    int rightMinidx, rightMaxidx;
    int cost = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] > max) {
            max = arr[i];
            leftMaxidx = i;
        } 
        if(arr[i] < min) {
            min = arr[i];
            leftMinidx = i;
        } 
        if(arr[i] == max)
            rightMaxidx = i;
        if(arr[i] == min)
            rightMinidx = i;
    }
    int leftCost = std::max(leftMinidx, leftMaxidx);
    int rightCost = n - std::min(rightMinidx, rightMaxidx);
    int biCost = std::min(leftMinidx, leftMaxidx) + n - std::max(rightMaxidx, rightMinidx);
    min = std::min(std::min(leftCost, rightCost), biCost);
    // cout << leftCost << " " << rightCost << " " << biCost << "\n";

    if(min == rightCost) {
        cost = rightCost;
    } else if(min == leftCost) {
        cost = leftCost + 1;
    } else {
        cost = biCost + 1;
    }
    cout << cost << "\n";
    
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

