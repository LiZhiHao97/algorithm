#include <iostream>

using namespace std;

int main() {
    int A, B;
    while(cin >> A >> B) {
        if (A == 0 && B == 0) continue;
        long long ans = 1;
        while(B)
        {
            if(B & 1)
                ans = (ans * A) % 1000;
            B >>= 1;
            A = (A * A) % 1000;
        }
        cout << ans << endl;
    }

    return 0;
}