#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace  std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string> ans;
        int left = 0;
        int right = 0;

        traceback(left, right, str, ans, n);

        return ans;
    }

    void traceback(int left, int right , string& str, vector<string>& ans, const int& n) {
        if (str.size() == 2 * n) {
            ans.push_back(str);
            return;
        }
        if (left < n) {
            str.push_back('(');
            traceback(left+1, right, str, ans, n);
            str.pop_back();
        }
        if (right < left) {
            str.push_back(')');
            traceback(left, right+1, str, ans, n);
            str.pop_back();
        }
    }
};

int main() {
    Solution solution;

    int n = 3;

    vector<string> ans = solution.generateParenthesis(n);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
