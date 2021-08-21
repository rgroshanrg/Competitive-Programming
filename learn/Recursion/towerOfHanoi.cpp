#include <bits/stdc++.h>
using namespace std;

void printSteps(int n, char a, char b, char c) {
    if(n == 1) {
        cout << "Move plate " << n << " from " << a << " to " << c << ".\n"; return;
    }
    printSteps(n-1, a, c, b);
    cout << "Move plate " << n << " from " << a << " to " << c << ".\n";
    printSteps(n-1, b, a, c);
}

int main() {

    printSteps(4 ,'A', 'B', 'C');
    
    return 0;
}