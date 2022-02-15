#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

class Solution {
private:
    int m, n, k;
    int ans = 1;
    vector<pair<int,int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> isVisited;
public:
    int movingCount(int m, int n, int k) {
        if (m * n == 0) {
            return 0;
        }

        this->m = m;
        this->n = n;
        this->k = k;
        this->isVisited = vector<vector<bool>>(n, vector<bool>(m, false));

        this->isVisited[0][0] = true;
        backtrace(0, 0);

        return ans;
    }

    void backtrace(int x, int y) {
        for (auto& direction: directions) {
            int nx = x + direction.first, ny = y + direction.second;

            if (canMove(nx, ny)) {
                isVisited[nx][ny] = true;
                ans += 1;
                backtrace(nx, ny);
            }
        }
    }

    bool canMove(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m) {
            return false;
        }
        int sum = 0;
        int nx = x, ny = y;
        while (nx != 0) {
            sum += nx % 10;
            nx /= 10;
        }
        while (ny != 0) {
            sum += ny % 10;
            ny /= 10;
        }
        return sum <= k && !isVisited[x][y];
    }
};

int main() {
    Solution solution;
    int m = 3, n = 1, k = 0;
    int ans = solution.movingCount(m, n, k);

    cout << ans << endl;
}