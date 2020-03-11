#include <iostream>

using namespace std;

long long dp[36][36];

int main() {
    int n, c = 0;

    for (int i = 0; i <= 35; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= 35; i++) {
        for (int j = i; j <= 35; j++) {
            if (i == j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    while (cin >> n, n + 1) {
        cout << ++c << ' ' << n << ' ' << dp[n][n] * 2 << endl;
    }
    return 0;
}