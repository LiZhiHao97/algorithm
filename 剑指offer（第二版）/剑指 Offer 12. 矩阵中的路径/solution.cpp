class Solution {
    vector<vector<bool>> isVisited;
    vector<vector<char>> board;
    vector<pair<int,int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string cur;
    string word;
    int n, m;
public:

    bool exist(vector<vector<char>>& board, string word) {
        if ((board.size() == 0 && board[0].size() == 0)) {
            return false;
        }

        this->n = board.size();
        this->m = board[0].size();

        if (m * n < word.size()) {
            return false;
        }

        this->board = board;
        this->word = word;
        vector<vector<bool>> isVisited(n, vector<bool> (m, false));
        this->isVisited = isVisited;

        bool ans = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    cur.push_back(board[i][j]);
                    this->isVisited[i][j] = true;
                    ans = backtrace(1, i, j);
                    this->isVisited[i][j] = false;
                    cur.pop_back();

                    if (ans) return true;
                }
            }
        }
        return false;
    }

    bool backtrace(int size, int x, int y) {
        if (size == word.size()) {
            return cur == word;
        }

        bool ans = false;
        for (auto direction: directions) {
            int nx = x + direction.first, ny = y + direction.second;
            if (canMove(nx, ny) && board[nx][ny] == word[size]) {
                cur.push_back(board[nx][ny]);
                isVisited[nx][ny] = true;
                ans = backtrace(size + 1, nx, ny);
                isVisited[nx][ny] = false;
                cur.pop_back();

                if (ans) return true;
            } else {
                continue;
            }
        }

        return false;
    }

    bool canMove(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && !isVisited[x][y];
    }
};