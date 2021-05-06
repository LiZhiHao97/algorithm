#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 通过异或的结合律推导 encode = decode[i]^decode[i+1]
//                   => encode^decode[i] = decode[i]^decode[i]^decode[i+1]
//                   => encode^decode[i] = 0^decode[i+1]
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        int cur = first;
        ans.push_back(first);

        for (auto num: encoded) {
            cur = num ^ cur;
            ans.push_back(cur);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> encoded{6};
    int first = 1;

    vector<int> ans = solution.decode(encoded, first);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}