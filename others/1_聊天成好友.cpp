#include <iostream>
#include <algorithm>

using namespace std;

int father[1001];

struct PrivateChat {
    int a;
    int b;
    int time;
}pc[100000];

bool cmp (PrivateChat a, PrivateChat b) {
    return a.time < b.time;
}

int findFather(int x) {
    int a = x;

    while (x != father[x]) {
        x = father[x];
    }

    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int fatherA = findFather(a);
    int fatherB = findFather(b);

    if (fatherA != fatherB) {
        father[fatherB] = fatherA;
    }
}

void init(int n) {
    for (int i = 1; i <= n;i ++) {
        father[i] = i;
    }
}

int main() {
    int n, m, count;
    cin >> n >> m;
    if (m < n - 1) {
        cout << -1 << endl;
        return 0;
    }
    init(n);
    for (int i = 1; i <= m; i++) {
        cin >> pc[i].a >> pc[i].b >> pc[i].time;
    }
    sort(pc + 1, pc + 1 + m, cmp);

    for (int i = 1; i < n - 1; i++) {
        Union(pc[i].a, pc[i].b);
    }

    for (int i = n - 1; i <= m; i++) {
        Union(pc[i].a, pc[i].b);

        int isroot[1001] = { 0 };
        count = 0;
        for (int i = 1; i <= n; i++) {
            isroot[findFather(i)] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (isroot[i]) count++;
        }
        if (count == 1) {
            cout << pc[i].time << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
