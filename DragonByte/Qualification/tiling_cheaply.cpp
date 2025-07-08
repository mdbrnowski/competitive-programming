#include <bits/stdc++.h>
using namespace std;

const vector<string> OPT7 = {
    "aabbccd",
    "aebfcdd",
    "geeffhh",
    "ggijjhk",
    "mmiijkk",
    "mnoppqq",
    "nnoopqq"};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int a = i / 2;
                    int b = j / 2;
                    if ((a % 2 + b % 2) % 2 < 1)
                        cout << "x";
                    else
                        cout << "y";
                }
                cout << "\n";
            }
        } else if (n < 7) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 7; j++) {
                    cout << OPT7[i][j];
                }
                for (int j = 7; j < n; j++) {
                    int a = (i + j % 2) / 2;
                    int b = (j - 1) / 2;
                    if (b % 2) {
                        cout << (a % 2 ? "t" : "u");
                    } else {
                        cout << (a % 2 ? "v" : "w");
                    }
                }
                cout << "\n";
            }
            for (int i = 7; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int a = (i - 1) / 2;
                    int b = (j + i % 2) / 2;
                    if (a % 2) {
                        cout << (b % 2 ? "x" : "y");
                    } else {
                        cout << (b % 2 ? "r" : "s");
                    }
                }
                cout << "\n";
            }
        }
    }
}
