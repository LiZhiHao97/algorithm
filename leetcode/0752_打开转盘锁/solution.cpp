#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    unordered_set<string> dead;
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }
        unordered_set<string> dead(deadends.begin(), deadends.end());
        this->dead = dead;
        if (dead.count("0000")) {
            return -1;
        }

        queue<string> q1;
        queue<string> q2;
        q1.emplace("0000");
        q2.emplace(target);
        unordered_map<string, int> seen1;
        unordered_map<string, int> seen2;
        seen1["0000"] = 0;
        seen2[target] = 0;
        int res = -1;

        while (!q1.empty() && !q2.empty()) {
            if (q1.size() <= q2.size()) {
                res = bfs(q1, seen1, seen2);
            } else {
                res = bfs(q2, seen2, seen1);
            }
            if (res != -1) return res;
        }
        return -1;
    }

    int bfs(queue<string>& q, unordered_map<string, int>& mine, unordered_map<string, int>& other) {
        auto status = q.front();
        int step = mine[status];
        q.pop();

        for (auto&& nextStatus: get(status)) {
            if (!mine.count(nextStatus) && !dead.count(nextStatus)) {
                if (other.count(nextStatus)) {
                    return step + 1 + other[nextStatus];
                }
                q.emplace(nextStatus);
                mine[nextStatus] = step + 1;
            }
        }
        return -1;
    }

    char substract(char x) {
        return x == '0' ? '9' : x - 1;
    };
    char plus(char x) {
        return x == '9' ? '0' : x + 1;
    };

    vector<string> get(string& status) {
        vector<string> ret;
        for (int i= 0; i < 4; i++) {
            char num = status[i];
            status[i] = substract(num);
            ret.push_back(status);
            status[i] = plus(num);
            ret.push_back(status);
            status[i] = num;
        }
        return ret;
    };
};

int main() {
    Solution solution;
    vector<string> deadends{ "0201","0101","0102","1212","2002"};
    string target = "0202";

    int ans = solution.openLock(deadends, target);

    cout << ans << endl;

    return 0;
}