#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e7;
unordered_map<char, int> bit = {{'B', 0b1}, {'G', 0b10}, {'R', 0b100}, {'Y', 0b1000}};

int get_best_proxy(int x, int y, const set<int>& s) {
    if (s.empty())
        return INF;
    int res = INF;
    auto it = s.upper_bound(x);
    if (it != s.end())
        res = min(res, (max(0, *it - y)));
    if (it != s.begin())
        res = min(res, x - *(--it));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        unordered_map<int, set<int>> pts;
        vector<int> color(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int b = bit[s[0]] | bit[s[1]];
            color[i] = b;
            pts[b].insert(i);
        }
        while (q--) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (x > y)
                swap(x, y);
            if (color[x] & color[y])
                cout << y - x << '\n';
            else {
                int res = INF;
                for (const auto& [b, s] : pts) {
                    if (!(b & color[x]) || !(b & color[y]))
                        continue;
                    int d = get_best_proxy(x, y, s);
                    res = min(res, y - x + 2 * d);
                }
                cout << (res < INF ? res : -1) << '\n';
            }
        }
    }
    return 0;
}
