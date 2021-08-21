#include <bits/stdc++.h>
using namespace std;

int gp(int a, int r, int n) {
    if(n <= 1)
        return a;
    return r * gp(a, r, n-1);
}

int main() {

    cout << gp(3, 2, 4) << "\n";        // 24

    return 0;
}