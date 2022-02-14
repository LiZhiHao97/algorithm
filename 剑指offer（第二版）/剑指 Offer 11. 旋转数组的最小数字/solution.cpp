#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();

        if (numbers[0] < numbers[n - 1]) {
            return numbers[0];
        }

        int low = 0, high = n - 1, mid = (low + high) / 2;

        while (low < high) {
            if (numbers[mid] > numbers[high]) {
                low = mid + 1;
            } else if (numbers[mid] < numbers[high]) {
                high = mid;
            } else {
                high -= 1;
            }
            mid = (low + high) / 2;
        }

        return numbers[low];
    }
};

int main() {
    Solution solution;
    vector<int> numbers{10,1,10,10,10};

    int ans = solution.minArray(numbers);

    cout << ans << endl;
}