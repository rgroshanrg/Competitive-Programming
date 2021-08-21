#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
    if(n < 2)
        return 1;
    return n*fact(n-1);
}

int main() {

    cout << fact(6) << "\n";        // 720

    return 0;
}