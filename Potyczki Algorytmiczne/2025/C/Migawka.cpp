#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 100;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    for (int i = 0; i < SIZE - 1; i++) {
        cout << 1;
        for (int j = 1; j < SIZE - 1; j++)
            cout << (i % 2 == 1);
        cout << 0;
        cout << '\n';
    }
    cout << 0;
    for (int j = 1; j < SIZE; j++)
        cout << 1;
    cout << '\n';
}
