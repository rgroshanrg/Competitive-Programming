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
int n , m;
	cin >> n >> m;
 
	string s;
	cin >> s;
 
	while (m--) {
		vector<int> v;
		for (int i = 1 ; i < n - 1 ; i++) {
			if (s[i] == '0') {
				if (s[i - 1] - '0' + s[i + 1] - '0' == 1) {
					v.push_back(i);
				}
			}
		}
 
 
 
		if (s[1] == '1' && s[0] == '0') {
			v.push_back(0);
		}
 
		if (s[n - 2] == '1' && s[n - 1] == '0') {
			v.push_back(n - 1);
		}
 
		for (auto i : v) {
			s[i] = '1';
		}
 
		if (count(all(s) , '1') == n) {
			cout << s << endl;
			return;
		}
 
		if (v.size() == 0) {
			cout << s << endl;
			return;
		}
	}
 
	cout << s << "\n";

    
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

