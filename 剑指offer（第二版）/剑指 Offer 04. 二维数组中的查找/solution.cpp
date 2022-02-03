#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0, j = m - 1;
        while(i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<int>> matrix{
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;
    Solution solution;
    bool ans = solution.findNumberIn2DArray(matrix, target);

    cout << ans << endl;

}