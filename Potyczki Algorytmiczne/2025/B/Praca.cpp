#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, k, t;
    cin >> n >> k >> t;
    vector<char> a(n);
    for (auto& x : a)
        cin >> x;
    int res = -1;

    // at least `m` many meetings
    int m = count_if(a.begin(), a.end(), [](const char x) { return x <= '2'; }) - k;
    if (m < 0) m = 0;

    // without going to work
    int meet_at_home = 0, meet_at_work = 0, free_time = 0;
    for (auto& x : a) {
        if (x == '2') meet_at_home++;
        if (x == '3' || x == '1') free_time++;
    }
    if (meet_at_home >= m)
        res = free_time + max(0, meet_at_home - m);

    // going to work
    for (int to_work = 0; to_work < n - 2 * t; to_work++) {
        meet_at_home = 0, meet_at_work = 0, free_time = 0;
        for (int i = 0; i < to_work; i++) {
            if (a[i] == '2') meet_at_home++;
            if (a[i] == '3' || a[i] == '1') free_time++;
        }
        for (int i = to_work + 2 * t; i < n; i++) {
            if (a[i] == '2') meet_at_home++;
            if (a[i] == '3' || a[i] == '1') free_time++;
        }
        if (meet_at_home + meet_at_work >= m)
            res = max(res, free_time + max(0, meet_at_home - m));
        for (int to_home = to_work + t + 1; to_home < n - t + 1; to_home++) {
            if (a[to_home - 1] <= '2') meet_at_work++;
            if (a[to_home + t - 1] == '2') meet_at_home--;
            if (a[to_home + t - 1] == '3' || a[to_home + t - 1] == '1') free_time--;
            if (meet_at_home + meet_at_work >= m)
                res = max(res, free_time + max(0, meet_at_home - m));
        }
    }

    cout << res << '\n';
}
