#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;

        int res = 0;
        bool mid_1 = false, mid_2 = false;
        for (auto x : a) {
            if (x == 0) {
                mid_1 = mid_2 = 0;
            } else if (x <= 2) {
                mid_1 ^= 1;
                mid_2 = 0;
            } else if (x <= 4) {
                if (!mid_1 && !mid_2)
                    res++;
                else
                    mid_1 ^= 1, mid_2 ^= 1;
            } else {
                mid_1 = mid_2 = 0;
                res++;
            }
            res += mid_1 + mid_2;
        }
        cout << res << '\n';
    }
    return 0;
}
