#include <iostream>

using namespace std;

long long ans = 0;

// f(n) = 3^(n-1) + 1
void hanoi(int n, int max, char A, char B, char C) {
    if (n == 1) {
        cout << A << "->" << B << endl;
        cout << B << "->" << C << endl;
        ans += 2;
    }  else if (n == max) {
        hanoi(n - 1, max, A, C, B);
        cout << A << "->" << B << endl;
        cout << B << "->" << C << endl;
        ans += 2;
    } else {
        hanoi(n - 1, max, A, B, C);
        cout << A << "->" << B << endl;
        hanoi(n - 1, max, C, B, A);
        cout << B << "->" << C << endl;
        hanoi(n - 1, max, A, B, C);
        ans += 2;
    }
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        hanoi(10, 10, 'A', 'B', 'C');
    }
    cout << ans << endl;
    return 0;
}