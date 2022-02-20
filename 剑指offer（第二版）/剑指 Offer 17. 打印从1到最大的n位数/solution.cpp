class Solution {
public:
    vector<char> loop = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<int> ans;
    int n;
    int start;
    int nine = 0;
    string num;

    vector<int> printNumbers(int n) {
        this->n = n;
        this->num = string(n, '0');
        start = n - 1;

        dfs(0);

        ans.erase(ans.begin());
        return ans;
    }

    void dfs(int x) {
        if (x == n) {
            ans.push_back(stoi(num.substr(start)));
            if (n - start == nine) {
                start--;
            }
            return;
        }

        for(auto i: loop) {
            if (i == '9') {
                nine++;
            }
            num[x] = i;
            dfs(x + 1);
        }
        nine--;
    }
};