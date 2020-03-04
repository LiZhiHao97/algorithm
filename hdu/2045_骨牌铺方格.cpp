#include <iostream>

using namespace std;

long long arr[51];

long long fib(int n) {
    if (n <= 1) return 1;
    if (arr[n]) return arr[n];
    return arr[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    while(cin >> n) {
        cout << fib(n) << endl;
    }

    return 0;
}