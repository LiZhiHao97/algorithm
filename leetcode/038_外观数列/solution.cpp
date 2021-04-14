class Solution {
public:
    string transform(const string& str) {
        string res;
        char cur = '0';
        int count = 0;
        for (auto c: str) {
            if (c == cur) {
                count++;
            } else {
                if (count) {
                    res.push_back(count + '0');
                    res.push_back(cur);
                }
                cur = c;
                count = 1;
            }
        }
        res.push_back(count + '0');
        res.push_back(cur);
        return res;
    }

    string countAndSay(int n) {
        string curStr = "1";
        for (int i = 2; i <= n; i++) {
            curStr = transform(curStr);
        }
        return curStr;
    }
};