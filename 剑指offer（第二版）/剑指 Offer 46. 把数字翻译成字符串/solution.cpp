class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int a = 1, b = 1, c;
        for (int i = 2; i <= str.size(); i++) {
            int cur = stoi(str.substr(i - 2, 2));
            c = cur <= 25 && cur >= 10 ? a + b : b;
            a = b;
            b = c;
        }
        return b;
    }
};