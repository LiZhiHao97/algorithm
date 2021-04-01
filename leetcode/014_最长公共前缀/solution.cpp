#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()) {
                break;
            }
        }
        return prefix;
    }
    string longestCommonPrefix(const string& str1, const string& str2) {
        int maxLen = min(str1.size(), str2.size());
        int index = 0;
        while(index < maxLen && str1[index] == str2[index]) index++;
        return str1.substr(0, index);
    }
};

int main() {
    Solution solution;
    string a[3] = {"flower","flow","flight"};
    vector<string> strs(a, a + 3);
    string ans =  solution.longestCommonPrefix(strs);
    cout << ans << endl;
    return 0;
}
