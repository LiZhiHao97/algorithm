class Solution {
    vector<string> combinations;
    string s;
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n > 12) return combinations;
        this->s = s;
        string combination;

        backtrace(0, 0, combination, n);

        return combinations;
    }

    void backtrace(int step, int cur, string combination, int n) {
        if (step == 4) {
            if (combination.size() - 3 == n) {
                combinations.push_back(combination);
            }
            return;
        }

        if (s[cur] - '0' == 0) {
            combination.push_back(s[cur]);
            if (step < 3) {
                combination.push_back('.');
            }
            backtrace(step + 1, cur + 1, combination, n);
            return;
        }

        int remain = n - cur;
        int minLen = max(1, remain - (3 - step) * 3);
        int maxLen = max(min(3, remain - (3 - step)), minLen);
        int tmp = 0;

        for (int i = 0; i < minLen - 1; i++) {
            tmp *= 10;
            tmp += s[cur + i] - '0';
            combination.push_back(s[cur + i]);
        }
        for (int i = 0; i <= maxLen - minLen; i++) {
            tmp *= 10;
            tmp += s[cur + minLen - 1 + i] - '0';
            if (tmp < 256) {
                combination.push_back(s[cur + minLen - 1 + i]);
                if (step < 3) {
                    combination.push_back('.');
                }
                backtrace(step + 1, cur + minLen + i, combination, n);
                combination.pop_back();
            }
        }
    }
};