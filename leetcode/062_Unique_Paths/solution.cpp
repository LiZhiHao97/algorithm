#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
      if (n == 1) {
        return 1;
      }
      if (n == 2) {
        return m;
      }
      int count = 1;
      for (int i = 0; i < m - 1; i++) {
        int newm = m - i;
        int newn = n - 1;
        count += uniquePaths(newm, newn);
      }
      return count;
    }
};

int main() {
  Solution solution;
  cout << solution.uniquePaths(7, 3) << endl;;
  return 0;
}