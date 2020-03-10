#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1000;

int f[maxn][maxn];
int dp[maxn][maxn];

int main() {
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= i; j++) {
                cin >> f[i][j];
            }
        }

        for (int i = 1; i <= m; i++) {
            dp[m][i] = f[m][i];
        }

        for (int i = m - 1; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
            }
        }

        cout << dp[1][1] << endl;
    }
    return 0;
}