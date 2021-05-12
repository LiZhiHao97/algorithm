#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int remain = m * n;
        vector<int> ans;
        int i = 0, j = 0, step = 0;
        while (remain) {
            if (remain == 1) {
                ans.push_back(matrix[n/2][m/2]);
                break;
            }
            for (; j < m - step - 1 && remain > 0; j++, remain--) ans.push_back(matrix[i][j]);
            for (; i < n - step - 1 && remain > 0; i++, remain--) ans.push_back(matrix[i][j]);
            for (; j > step && remain > 0; j--, remain--) ans.push_back(matrix[i][j]);
            for (; i > step && remain > 0; i--, remain--) ans.push_back(matrix[i][j]);
            i++;
            j++;
            step++;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
    vector<int> ans = solution.spiralOrder(matrix2);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}