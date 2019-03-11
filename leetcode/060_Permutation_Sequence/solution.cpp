#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
      string a[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
      vector<string> v(a, a + sizeof(a) / sizeof(string));
      vector<string>::iterator it = v.begin();

      int remain = n;
      int group = fac(n);
      string result = "";
      k = k - 1;

      while(remain) {
        group /= remain;
        int i;
        i = k / group;
        cout << i << endl;
        result += v[i];
        v.erase(it + i);
        k -= group * (i);
        remain--;
      }
      return result;
    }
    int fac(int n) {
      int sum = 1;
      while(n > 1) {
        sum *= n--;
      }
      return sum;
    }
};

int main() {
  Solution solution;
  cout << solution.getPermutation(4, 9) << endl;
  return 0;
}