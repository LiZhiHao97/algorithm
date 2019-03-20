#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > result;
    vector<int> subresult;
    vector< vector<int> > subsets(vector<int>& nums) {
      result.clear();
      subresult.clear();
      result.push_back(subresult);
      for (int i = 1; i <= nums.size(); i++) {
        subresult.clear();
        subresult.resize(i);
        generateSubsets(i, 0, 0, nums);
      }
      return result;
    }
    void generateSubsets(int len, int index, int start, vector<int> nums) {
      if (len == 0) {
        result.push_back(subresult);
        return;
      }
      for (int i = start; i < nums.size(); i++) {
        subresult[index] = nums[i];
        generateSubsets(len - 1, index + 1, i + 1, nums);
      }
    }
};

int main () {
  Solution sol;
  int a[3] = {1, 2, 3};
  vector<int> v(a, a + sizeof(a) / sizeof(int));
  vector< vector<int> > result = sol.subsets(v);
  int row = result.size();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}