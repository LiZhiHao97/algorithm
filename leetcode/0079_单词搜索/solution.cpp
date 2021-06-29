#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> isVisited;
    vector<vector<char>> board;
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string word;
    int n, m;
public:
    bool isSubString(string subStr, string str) {
        return str.find(subStr) == 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        this->board = board;
        int n = board.size(), m = board[0].size();
        this->n = n;
        this->m = m;
        if (m * n < word.size()) {
            return false;
        }
        string cur = "";
        bool ret = false;
        vector<vector<int>> isVisited(n, vector<int> (m, 0));
        this->isVisited = isVisited;
        // find start position
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    cur.push_back(board[i][j]);
                    isVisited[i][j] = 1;
                    ret = backtrace(cur, i, j);
                    cur.pop_back();
                    isVisited[i][j] = 0;
                    if (ret) return ret;
                }
            }
        }
        return false;
    }

    bool backtrace(string cur, int x, int y) {
        if (cur == word) {
            return true;
        }
        bool ret = false;
        for (auto direction: directions) {
            int nx = x + direction.first, ny = y + direction.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !isVisited[nx][ny]) {
                cur.push_back(board[nx][ny]);
                if (!isSubString(cur, word)) {
                    cur.pop_back();
                    continue;
                }
                isVisited[nx][ny] = 1;
                ret = backtrace(cur, nx, ny);
                isVisited[nx][ny] = 0;
                cur.pop_back();
                if (ret) return ret;
            }
        }
        return false;
    }
};


int main() {
    Solution solution;
    vector<vector<char>> board{{'A','B','C','E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
//    vector<vector<char>> board{{'a', 'a'}};
    string word = "SEE";

    bool ans = solution.exist(board, word);

    cout << ans << endl;
    return 0;
}