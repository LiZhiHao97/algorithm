#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace  std;

class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int i = 0;
        int flag = 1;

        while (s[i] == ' ') i++;

        if (s[i] == '-') flag = -1;
        if (s[i] == '-' || s[i] == '+') i++;

        while(i < s.size() && isdigit(s[i])) {
            int temp = s[i] - '0';
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && temp > 7)) {
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + temp;
            i++;
        }

        return flag * ans;
    }
};

int main() {
    Solution solution;
    string str = "-4193 with words";
    int ans =  solution.myAtoi(str);
    cout << ans << endl;
    return 0;
}
