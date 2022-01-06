#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, val;
    bool operator<(Point p) {
        if (x != p.x) return x < p.x;
        return val < p.val;
    }
};

struct SegmentTree {
    int n = 1 << (1 + __lg(70003));
    vector<pair<int,int>> tree;  // {sum, max_pref_sum}
    SegmentTree() : tree(2 * n, {0, 0}) {}
    void add(int i, int x) {
        i += n;
        tree[i].first += x;
        tree[i].second = max(0, tree[i].first);
        for (i /= 2; i > 0; i /= 2) {
            tree[i].first = tree[2*i].first + tree[2*i+1].first;
            tree[i].second = max(tree[2*i].second, tree[2*i].first + tree[2*i+1].second);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, w, n;
    cin >> s >> w >> n;
    s++, w++;
    vector<Point> points;
    while (n--) {
        int x, y;
        cin >> x >> y;
        x += 30000, y += 30000;
        points.push_back(Point({x, y, 1}));
        points.push_back(Point({x, y + w, -1}));
        points.push_back(Point({x + s, y, -1}));
        points.push_back(Point({x + s, y + w, 1}));
    }
    sort(points.begin(), points.end());

    int res = 0;
    SegmentTree stree;
    for (auto [x, y, val] : points) {
        stree.add(y, val);
        res = max(res, stree.tree[1].second);
    }
    cout << res << '\n';
    return 0;
}