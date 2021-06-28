#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);

        list<vector<int>> tmp;

        for (auto& iter : people) {
            auto pos = tmp.begin();
            advance(pos, iter[1]);
            tmp.insert(pos, iter);
        }

        return vector<vector<int>> (tmp.begin(), tmp.end());
    }
};

int main() {
    Solution solution;
//    beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    vector<vector<int>> people{{7, 0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};

    vector<vector<int>> ans = solution.reconstructQueue(people);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}