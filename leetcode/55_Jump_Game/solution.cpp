#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int len = nums.size() - 1;
    if (len == 0) return true;
    int from = len - 1, to = len;
    while (from) {
      if (nums[from] >= to - from) {
        to = from;
      }
      from--;
    }
    if (nums[from] >= to - from) {
      return true;
    }
    return false;
  }
};

int main() {
  Solution solution;
  int a[] = {3,2,1,0,4};
  vector<int> v(a, a + sizeof(a) / sizeof(int));
  
  cout << solution.canJump(v) << endl;;

  return 0;
}