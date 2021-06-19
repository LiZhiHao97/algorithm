#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, sum = 0, index;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];

            if (sum > 0) {
                sum += gas[i] - cost[i];
            } else {
                sum = gas[i] - cost[i];
                index = i;
            }
        }

        return totalCost > totalGas ? -1 : index;
    }
};

int main() {
    Solution solution;
    vector<int> gas{5,8,2,8};
    vector<int> cost{6,5,6,6};

    int ans = solution.canCompleteCircuit(gas, cost);

    cout << ans << endl;


    return 0;
}