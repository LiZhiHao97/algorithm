class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto& num: nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), [](string& x, string& y) { return x + y  < y + x; });
        string ans;
        for (auto& str: strs) {
            ans.append(str);
        }
        return ans;
    }
};