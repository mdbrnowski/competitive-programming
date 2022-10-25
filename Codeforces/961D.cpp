#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
    bool on_line(Point A, Point B) {
        return (y - A.y) * (B.x - A.x) - (B.y - A.y) * (x - A.x) == 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Point> points(n);
    for (auto& p : points)
        cin >> p.x >> p.y;
    if (n <= 4) { cout << "YES\n"; return 0; }
    vector<pair<int,int>> threepairs = {{0, 1}, {0, 2}, {1, 2}};
    for (auto [i, j] : threepairs) {
        auto A = points[i], B = points[j];
        vector<Point> others;
        for (auto p : points) {
            if (!p.on_line(A, B))
                others.push_back(p);
        }
        if (others.size() <= 2) { cout << "YES\n"; return 0; }
        else {
            auto C = others[0], D = others[1];
            if (all_of(others.begin(), others.end(), [&](Point p){ return p.on_line(C, D); })) {
                cout << "YES\n"; return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}