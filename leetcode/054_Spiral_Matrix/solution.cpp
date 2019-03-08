#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int m = matrix.size(); // rows
        if (m == 0) return v;
        int n = matrix[0] .size(); // cols
        int i(0), j(0), step(0), remain(m*n);
        while (remain > 0) {
            if (remain == 1) { v.push_back(matrix[m/2][n/2]); break; }
            for (int k = 0; remain > 0 && k < n - 2 * step - 1; ++k, remain--) v.push_back(matrix[i][j++]); // right
            for (int k = 0; remain > 0 && k < m - 2 * step - 1; ++k, remain--) v.push_back(matrix[i++][j]); // down
            for (int k = 0; remain > 0 && k < n - 2 * step - 1; ++k, remain--) v.push_back(matrix[i][j--]); // left
            for (int k = 0; remain > 0 && k < m - 2 * step - 1; ++k, remain--) v.push_back(matrix[i--][j]); // up
            i++; j++; step++;
        }
        return v;
    }
};