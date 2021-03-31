#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace  std;

// mysolution
class Solution {
public:
    string convert(string s, int numRows) {
      if (numRows == 1) {
          return s;
      }
      int group = numRows * 2 - 2;
      string ans =  "";
      vector<string> rows(min(numRows, int(s.size())));
      for (int i = 0, j = 0; i < s.size(); i++) {
          j = i % group;
          if (j > numRows - 1) {
              rows[numRows - 2 - j % numRows].push_back(s[i]);
          } else {
              rows[j % numRows].push_back(s[i]);
          }
      }
      for (int i = 0; i < rows.size(); i++) {
          for (int j = 0; j < rows[i].size(); j++) {
              ans += rows[i][j];
          }
      }

      return ans;
    }
};

class Solution2 {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string ans =  "";
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        for (auto c: s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = ! goingDown;
            curRow += goingDown ? 1 : -1;
        }

        for (auto row: rows) {
            ans += row;
        }

        return ans;
    }
};

int main() {
    Solution2 solution;
    string s = "PAYPALISHIRING";
    int numRows = 4;
    string ans =  solution.convert(s, numRows);
    cout << ans << endl;
    return 0;
}
