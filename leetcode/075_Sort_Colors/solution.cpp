#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int barrel[3] = {0, 0, 0};
      for (int i = 0; i < nums.size(); i++) {
        barrel[nums[i]] += 1;
      }
      int i = 0;
      for (; i < barrel[0]; i++) {
        nums[i] = 0;
      }
      for (; i < barrel[0] + barrel[1]; i++) {
        nums[i] = 1;
      }
      for (; i < barrel[0] + barrel[1] + barrel[2]; i++) {
        nums[i] = 2;
      }
    }
};

int main () {
  Solution sol;
  int a[6] = { 2, 0, 2, 1, 1, 0 };
  vector<int> v(a, a + sizeof(a) / sizeof(int));
  sol.sortColors(v);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}