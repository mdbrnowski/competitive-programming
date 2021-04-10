#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        vector<vector<int>> arr(a.length(), vector<int>(b.length(), 0));
        int lcs = 0;
        for (int i = 0; i < a.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                if (a[i] == b[j]) {
                    if (i == 0 || j == 0) arr[i][j] = 1;
                    else arr[i][j] = arr[i-1][j-1] + 1;
                }
                else arr[i][j] = 0;
                lcs = max(lcs, arr[i][j]);
            }
        }
        cout << a.length() + b.length() - 2 * lcs << '\n';
    }
    return 0;
}