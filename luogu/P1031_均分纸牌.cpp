#include <bits/stdc++.h>

using namespace std;

int card[101];
int N, sum, avg, c;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> card[i];
        sum += card[i];
    }
    avg = sum / N;
    for (int i = 1; i <= N; i++) {
        if (card[i] - avg) {
            int d = card[i] - avg;
            card[i + 1] += d;
            c++;
        }
    }
    cout << c << endl;
    return 0;
}