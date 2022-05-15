#include <bits/stdc++.h>
using namespace std;

struct DSU {  // kinda
    int n;
    vector<int> link;
    DSU(int _n) : n(_n), link(n) {
        iota(link.begin(), link.end(), 0);
    }
    int find(int x) {
        if (x == link[x]) return x;
        return link[x] = find(link[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x > y) swap(x, y);
        link[y] = x;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k; string s;
        cin >> n >> k >> s;
        DSU dsu(26);
        for (auto c : s) {
            c = dsu.find(c - 'a');
            while (c > 0) {
                if (k == 0) break;
                k -= (c == dsu.find(c));
                dsu.unite(c, c - 1);
                c--;
            }
        }
        for (auto& c : s)
            c = dsu.find(c - 'a') + 'a';
        cout << s << '\n';
    }
    return 0;
}