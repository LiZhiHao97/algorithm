#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> per;
  vector< vector<int> > ans;
  vector< vector<int> > combine(int n, int k) {
      ans.clear();
      per.resize(k);
      generateCombine(n,k,1,0);
      return ans;
  }
  void generateCombine(int n, int k, int start , int index) {
      if (k==0)
      {
          ans.push_back(per);
          return ;
      }
      for(int i=start;i<=n;i++)
      {
          per[index] = i;
          generateCombine(n,k-1,i+1,index+1);
      }
  }
};

int main () {
  Solution sol;
  vector< vector<int> > result = sol.combine(4, 2);
  int row = result.size();
  int col = result[0].size();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}