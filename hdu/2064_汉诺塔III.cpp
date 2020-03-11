#include <iostream>

using namespace std;

long long ans = 0;

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        ans += 2;
        cout << A << "->" << B << endl;
        cout << B << "->" << C << endl;
    } else {
        hanoi(n - 1, A, B, C);
        cout << A << "->" << B << endl;
        hanoi(n - 1, C, B, A);
        cout << B << "->" << C << endl;
        hanoi(n - 1, A, B, C);
        ans += 2;
    }
}

int main() {
    hanoi(12, 'A', 'B', 'C');
    cout << ans << endl;
    return 0;
}