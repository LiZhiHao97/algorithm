#include <iostream>
#include <cmath>

using namespace std;

double a[26];

double perm (int num) {
    double ans = 1;
    for (int i = 2; i <= num; i++) {
        ans *= i;
    }
    return ans;
}

int main() {

    a[1] = 0;
    a[2] = 1;

    for (int i = 3; i <= 25; i++) {
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    }

    double t;

    while (cin >> t, t) {
        double ans = 0;
        int min;
        int m = (int)t;
        min = ceil(t / 2);

        a[0] = 1;
        for (int i = min; i <= m; i++) {
            ans += a[m- i] * (perm(m) / (perm(m - i) * perm(i)));
        }

        printf("%.lf\n", ans);
    }

    return 0;
}