#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int distance(string n, string x) {
    int np = 0, xp = 0;
    while (xp < x.size() && np < n.size()) {
        if (n[np] == x[xp]) xp++;
        np++;
    }
    return n.size() + x.size() - 2 * xp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> powers_2;
    for (int i = 0; i < 59; i++) powers_2.push_back(to_string(1LL << i));
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int res = INT_MAX;
        for (auto x : powers_2) res = min(res, distance(n, x));
        cout << res << '\n';
    }
    return 0;
}