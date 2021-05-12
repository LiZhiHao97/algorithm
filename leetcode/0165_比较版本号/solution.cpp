class Solution {
public:
    vector<int> split(string str) {
        vector<int> result;
        int temp = 0;

        for (auto c: str) {
            if (!temp && c == '0') continue;
            if (c == '.') {
                result.push_back(temp);
                temp = 0;
                continue;
            }
            temp *= 10;
            temp += c - '0';
        }

        result.push_back(temp);

        return result;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        int n = min(v1.size(), v2.size());

        while (v1.size() && v2.size()) {
            if (*v1.begin() > *v2.begin()) {
                return 1;
            } else if (*v1.begin() < *v2.begin()) {
                return -1;
            } else {
                v1.erase(v1.begin());
                v2.erase(v2.begin());
            }
        }

        while (v1.size()) {
            if (*v1.begin() != 0) {
                return 1;
            }
            v1.erase(v1.begin());
        }

        while (v2.size()) {
            if (*v2.begin() != 0) {
                return -1;
            }
            v2.erase(v2.begin());
        }

        return 0;
    }
};