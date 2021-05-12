class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string tmp = "";
        vector<string> container;
        string ans;
        int dotCount = 0;

        for (int i = 0; i < n; i++) {
            if (path[i] == '/') {
                if (tmp.size()) {
                    container.push_back(tmp);
                    tmp.clear();
                }
            } else if (path[i] == '.' && tmp.size() == 0) {
                while (path[i] == '.') {
                    i++;
                    dotCount++;
                    tmp += '.';
                }
                if (i == n || path[i] == '/') {
                    if (dotCount == 2 && !container.empty()) {
                        container.pop_back();
                    }
                    if (dotCount > 2) {
                        container.push_back(tmp);
                    }
                    dotCount = 0;
                    tmp.clear();
                } else {
                    dotCount = 0;
                }
                i--;
            } else {
                tmp += path[i];
            }
        }
        if (tmp.size()) container.push_back(tmp);

        for (int i = 0; i < container.size(); i++) {
            ans += '/' + container[i];
        }
        return  ans.size() ? ans : "/";
    }
};