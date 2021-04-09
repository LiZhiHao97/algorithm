#include <iostream>
#include <stack>
#include <map>

using namespace  std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) return false;
        map<char, char> m = {
                { ')', '(' },
                { ']', '[' },
                { '}', '{' }
        };
        stack<char> stk;
        for (char c: s) {
            if (m.count(c)) {
                if (stk.empty() || stk.top() != m[c]) {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};

int main() {
    Solution solution;
    string s = "{[]}";
    bool ans = solution.isValid(s);
    cout << ans << endl;
    return 0;
}
