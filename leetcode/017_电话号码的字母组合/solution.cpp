#include <iostream>
#include <vector>
#include <map>

using namespace  std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return {};
        vector<string> ans;
        map<char, string> m{
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };
        string str;
        backtrace(ans, m, digits, 0, str);
        return ans;
    }

    void backtrace(vector<string>& ans, const map<char, string>& m, const string& digits, int index, string& str) {
        if (index == digits.size()) {
            ans.push_back(str);
            return;
        }
        char digit = digits[index];
        const string& letters = m.at(digit);
        for (auto letter: letters) {
            str.push_back(letter);
            backtrace(ans, m, digits, index + 1, str);
            str.pop_back();
        }
    }
};

int main() {
    Solution solution;
    string digits = "23";
    vector<string> ans = solution.letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
