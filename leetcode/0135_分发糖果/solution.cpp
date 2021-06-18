#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) return  n;

        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] =  candies[i - 1] + 1;
            }
        }
        for (int i = n - 1; i > 0; i--) {
            if (ratings[i] < ratings[i - 1]) {
                candies[i - 1] = max(candies[i - 1], candies[i] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    Solution solution;
    vector<int> ratings{1, 0, 2};

    int ans = solution.candy(ratings);

    cout << ans << endl;


    return 0;
}