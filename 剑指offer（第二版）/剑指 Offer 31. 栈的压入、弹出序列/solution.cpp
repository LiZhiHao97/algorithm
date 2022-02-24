#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
private:
    stack<int> stk;
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;

        for (auto item: pushed) {
            stk.push(item);

            while(!stk.empty() && stk.top() == popped[i]) {
                stk.pop();
                i++;
            }
        }

        return stk.empty();
    }
};