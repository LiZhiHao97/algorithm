
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 100;

struct Node {
    int x, y, step;
}node, S, T;

int X[] = { 0, 0, 1, -1 };
int Y[] = { 1, -1, 0, 0 };

int n, m;
char matrix[maxn][maxn];
bool inq[maxn][maxn] = { false };

bool test(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (matrix[x][y] == '*' || inq[x][y]) return false;
    return true;
}

int BFS() {
    queue<Node> Q;
    Q.push(S);

    while(!Q.empty()) {
        Node top = Q.front();
        Q.pop();
        if (top.x == T.x && top.y == T.y) {
            return top.step;
        }
        for (int i = 0; i < 4; i++) {
            int NewX = top.x + X[i];
            int NewY = top.y + Y[i];

            if (test(NewX, NewY)) {
                node.x = NewX;
                node.y = NewY;
                node.step = top.step + 1;
                inq[NewX][NewY] = true;
                Q.push(node);
            }
        }
    }
    return -1;
}

/*
5 5
.....
.*.*.
.*S*.
.***.
...T*
2 2 4 3
*/
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            matrix[i][j] = getchar();
        }
    }
    cin >> S.x >> S.y >> T.x >> T.y;
    S.step = 0;
    cout << BFS() << endl;
    return 0;
}