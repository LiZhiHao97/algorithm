#include <iostream>
#include <set>

using namespace  std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> m;
        int rk = -1, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                m.erase(s[i - 1]);
            }
            while (rk + 1 < n && !m.count(s[rk + 1])) {
                m.insert(s[++rk]);
            }
            ans = max(ans, rk - i  + 1);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string str = "abba";
    int result =  solution.lengthOfLongestSubstring(str);
    cout << result << endl;
    return 0;
}
