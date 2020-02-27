#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

int row[1001], col[1001];
int b1[1001], b2[1001];

int M, N, K, L, D;

// 本题主要使用贪心算法的思想，找出能够隔开最多同学的通道
int main() {
    cin >> M >> N >> K >> L >> D;
    for (int i = 1; i <= D; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c) {
            col[(b + d) / 2]++;
        }
        if (b == d) {
            row[(a + c) / 2]++;
        }
    }
    for (int i = 1; i <= K; i++) {
        int max = 0;
        for (int j = 1; j < M; j++) {
            if (row[j] > row[max]) {
                max = j;
            }
        }
        row[max] = 0;
        b1[max]++;
    }
    for (int i = 1; i <= L; i++) {
        int max = 0;
        for (int j = 1; j < N; j++) {
            if (col[j] > col[max]) {
                max = j;
            }
        }
        col[max] = 0;
        b2[max]++;
    }
    for(int i = 1; i <= 1000; i++) {
        if (b1[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    for(int i = 1; i <= 1000; i++) {
        if (b2[i]) {
            cout << i << " ";
        }
    }
    return 0;
}