#include <iostream>
#include <string>

using namespace std;

void mix(string &str) {
    int len = str.size();

    if (str.find('.') != string::npos) {
        for (int i = len - 1; str[i] == '0'; i--) {
            len--;
        }
    }
    if (str[len - 1] == '.') len--;
    str = str.substr(0, len);
}

int main() {
    string A, B;
    while(cin >> A >> B) {
        mix(A);
        mix(B);
        if (A == B) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
