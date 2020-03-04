#include <stdio.h>

long long arr[21];

long long perm (int n, int m) {
    long long a, b, c;
    a = b = c = 1;
    for(int i = 2; i <= n; i++)
        a *= i;
    for(int i = 2; i <= m; i++)
        b *= i;
    for(int i = 2; i <= n - m; i++)
        c *= i;
    return a / b / c;
}

int main() {
    int t;
    scanf("%d", &t);
    arr[1] = 0;
    arr[2] = 1;
    for (int i = 3; i <= 20; i++) {
        arr[i] = (i - 1) * (arr[i - 2] + arr[i - 1]);
    }
    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%lld\n", perm(n, m) * arr[m]);
    }
    return 0;
}