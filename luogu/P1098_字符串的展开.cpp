#include <bits/stdc++.h>

using namespace std;

int p1, p2, p3;
string str;

string process(char start, char end) {
    string part = "";
    if (end - start <= 0 || end - start >= 'a' - '9') {
        return "-";
    }
    if (end -start == 1) {
        return "";
    }
    for (int i = 1; i <= end - start - 1; i++) {
        char t;
        p3 == 1 ? t = start + i : t = end - i;
        if (p1 == 2) t = toupper(t);
        else if (p1 == 3) t = '*';
        for (int i = 1; i <= p2; i++) {
            part += t;
        }
    }
    return part;
}

int main() {
    cin >> p1 >> p2 >> p3;
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            str.erase(i, 1);
            string part = process(str[i - 1], str[i]);
            str.insert(i, part);
            i += part.size();
        }
    }
    cout << str << endl;
    return 0;
}