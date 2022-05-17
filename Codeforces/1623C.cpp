#include <bits/stdc++.h>
using namespace std;

bool check(int r, const vector<int>& h) {
    int n = h.size();
    auto ch = h;
    for (int i = n - 1; i >= 2; i--) {
        if (ch[i] < r) return false;
        int to_move = min((ch[i] - r) / 3, h[i] / 3);
        ch[i - 1] += to_move;
        ch[i - 2] += 2 * to_move;
    }
    if (ch[1] < r || ch[0] < r) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        for (auto& x : h) cin >> x;
        int a = 1, b = 1e9;
        while (a <= b) {
            int m = (a + b) / 2;
            if (check(m, h)) a = m + 1;
            else b = m - 1;
        }
        cout << b << '\n';
    }
    return 0;
}