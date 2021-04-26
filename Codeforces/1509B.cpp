#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> M, T;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') M.push_back(i);
        else T.push_back(i);
    }
    if (T.size() != 2 * M.size())
        return false;
    for (int i = 0; i < M.size(); i++)
        if (M[i] < T[i] || M[i] > T[i + M.size()])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        cout << (solve() ? "YES\n" : "NO\n");
    return 0;
}