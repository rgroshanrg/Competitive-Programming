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
    vector<int> roots(n);
    set<int> set;
    for(int i = 0; i < n; ++i) {
        cin >> roots[i];
        set.insert(roots[i]);
    }
    sort(all(roots));
    for(;q;q--) {
        int x;
        cin >> x;
        if(set.find(x) != set.end()) {
            cout << 0 << "\n"; continue;
        }
        if(x < roots[0]) {
            if(n&1) {
                cout << "NEGATIVE\n";continue;
            }
            else {
                cout << "POSITIVE\n";
                continue;
            }
        } else if(x > roots[n-1]) {
            cout << "POSITIVE\n";
            continue;
        }

        int i = 0, j = n-1;
        int mid;
        while(i < j-1) {
            mid = (j+i) >> 1;
            if(x < roots[mid]) {
                j = mid;
            } else {
                i = mid;
            }
        }
        // cout << i;
        int count = n - j;
        if(count&1) {
            cout << "NEGATIVE\n";            
        } else {
            cout << "POSITIVE\n";
        }


        // if(roots.find(x) != roots.end())
        //     cout << 0 << "\n"; continue;
        // int count = 0;
        // for(auto i : roots){
        //     if(i < x)
        //         count++;
        //     else
        //         break;
        // }
        // int res = n-count;
        // if(count & 1) {
        //     cout << "NEGATIVE\n";
        // } else {
        //     cout << "POSITIVE\n";
        // }

    }    
    
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

