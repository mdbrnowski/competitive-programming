#include <bits/stdc++.h>
using namespace std;

struct SpeedHint {
    int next_i;
    int len;
    array<int, 2> sum;
    SpeedHint() {}
    SpeedHint(int _next_i, int x) : next_i(_next_i), len(1), sum({0, x}) {}
};

void merge(SpeedHint& first, SpeedHint& second) {
    first.next_i = second.next_i;
    if (first.len % 2 == 0)
        first.sum[0] += second.sum[0],
            first.sum[1] += second.sum[1];
    else
        first.sum[0] += second.sum[1],
            first.sum[1] += second.sum[0];
    first.len += second.len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int M = *max_element(a.begin(), a.end());
        unordered_map<int, SpeedHint> sph;
        for (int b = 1; b <= M; b++) {
            int res = 0;
            bool paint = 1;
            for (int i = 0; i < n;) {
                if (sph.count(i)) {
                    if (sph.count(sph[i].next_i)) {
                        merge(sph[i], sph[sph[i].next_i]);
                        continue;  // it will go back to the same i
                    }
                    res += sph[i].sum[paint];
                    paint ^= (sph[i].len % 2);
                    i = sph[i].next_i;
                } else {
                    int x = a[i];
                    if (x <= b)
                        sph[i] = SpeedHint(i + 1, x);
                    while (x > b) {
                        if (paint)
                            res += b;
                        x -= b;
                        paint ^= 1;
                    }
                    if (paint)
                        res += x;
                    paint ^= 1;
                    i++;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
