#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);

        int count = 0;
        int end = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < end) {
                end = min(end, intervals[i][1]);
                count++;
            } else {
                end = intervals[i][1];
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
//    flowerbed = [1,0,0,0,1], n = 1
    vector<vector<int>> intervals{ {1, 2}, {2, 3}, {3, 4}, {1, 3} };

    int ans = solution.eraseOverlapIntervals(intervals);

    cout << ans << endl;


    return 0;
}