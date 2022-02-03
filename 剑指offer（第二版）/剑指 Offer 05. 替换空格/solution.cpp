#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int spaceNum = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                spaceNum++;
            }
        }

        s.resize(n + 2 * spaceNum);

        for (int i = n - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] != ' ') {
                s[j] = s[i];
            } else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }

        return s;

    }
};

int main() {
    string s = "We are happy.";
    Solution solution;
    string ans = solution.replaceSpace(s);

    cout << ans << endl;

}