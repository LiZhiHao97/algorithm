#include <stdio.h>

long long arr[21];

int main() {
    int m;
    scanf("%d", &m);
    arr[1] = 0;
    arr[2] = 1;
    for (int i = 3; i <= 20; i++) {
        arr[i] = (i - 1) * (arr[i - 2] + arr[i - 1]);
    }
    for (int i = 0; i < m; i++) {
        int n;
        scanf("%d", &n);
        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans *= i;
        }
        printf("%.2lf%%\n", 100.0 * arr[n] / ans);
    }
    return 0;
}