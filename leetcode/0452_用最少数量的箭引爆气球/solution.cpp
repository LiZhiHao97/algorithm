bool compare(vector<int> v1, vector<int> v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), compare);

        int count = n;
        int end = points[0][1];

        for (int i = 1; i < n; i++) {
            if (points[i][0] <= end) {
                end = min(end, points[i][1]);
                count--;
            } else {
                end = points[i][1];
            }
        }

        return count;
    }
};