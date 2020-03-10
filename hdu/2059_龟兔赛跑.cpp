#include <iostream>

using namespace std;

int main() {
    int L;
    int N, C, T;
    int VR, VT1, VT2;
    int dis[102];
    double dp[102], min, e;

    while(cin >> L) {

        cin >> N >> C >> T >> VR >> VT1 >> VT2;

        dp[0] = dis[0] = 0;

        for (int i = 1; i <= N; i++) {
            cin >> dis[i];
        }

        dis[N + 1] = L;

        for (int i = 1; i < N + 2; i++) {
            min = 0xffffff;

            for (int j = 0; j < i; j++) {
                int len = dis[i] - dis[j];
                e = len > C ? C * 1.0 / VT1 + (len - C + 0.0) / VT2 : 1.0 * len / VT1;
                e += dp[j];
                if (j) e += T;
                if (min > e) min = e;
            }

            dp [i] = min;
        }

        if (1.0 * L / VR > dp[N + 1]) {
            cout << "What a pity rabbit!" << endl;
        } else {
            cout << "Good job,rabbit!" << endl;
        }
    }
    return 0;
}