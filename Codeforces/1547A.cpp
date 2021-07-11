#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int ax, ay, bx, by, fx, fy;
        cin >> ax >> ay >> bx >> by >> fx >> fy;
        int res = abs(ax - bx) + abs(ay - by);
        if (ax == bx && bx == fx) {
            if (ay < by) swap(ay, by);
            if (by < fy && fy < ay)
                res += 2;
        }
        if (ay == by && by == fy) {
            if (ax < bx) swap(ax, bx);
            if (bx < fx && fx < ax)
                res += 2;
        }
        cout << res << '\n';
    }
    return 0;
}