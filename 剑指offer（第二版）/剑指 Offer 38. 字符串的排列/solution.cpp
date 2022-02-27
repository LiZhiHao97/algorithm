class Solution {
private:
    vector<string> ans;
    string cur;
    vector<bool> isVisited;
    string s;
    int n;

    void backtrace(int remain) {
        if (remain == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!isVisited[i] && (i == 0 || s[i] != s[i - 1] || isVisited[i - 1])) {
                isVisited[i] = true;
                cur.push_back(s[i]);
                backtrace(remain - 1);
                cur.pop_back();
                isVisited[i] = false;
            }
        }
    }
public:
    vector<string> permutation(string s) {
        int n = s.size();
        if (!n) {
            return vector<string>{};
        }
        sort(s.begin(), s.end());
        this->n = n;
        this->s = s;
        this->isVisited = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            if (i == 0 || s[i] != s[i - 1]) {
                isVisited[i] = true;
                cur.push_back(s[i]);
                backtrace(n - 1);
                cur.pop_back();
                isVisited[i] = false;
            }
        }

        return ans;
    }
};