#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        if (num.size() == k) {
            return "0";
        }
        vector<int> stk;

        for (auto digit: num) {
            while(k && stk.size() && stk.back() > digit) {
                stk.pop_back();
                k--;
            }
            stk.push_back(digit);
        }

        while (k--) {
            stk.pop_back();
        }

        bool isLeadingZero = true;
        for (auto digit: stk) {
            if (digit == '0' && isLeadingZero) {
                continue;
            }
            isLeadingZero = false;
            ans += digit;
        }

        return ans == "" ? "0" : ans;
    }
};


int main() {
    Solution solution;
    string num = "9";
    int k = 1;

    string ans = solution.removeKdigits(num, k);

    cout << ans << endl;

    return 0;
}