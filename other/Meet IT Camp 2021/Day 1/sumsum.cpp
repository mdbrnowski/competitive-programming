#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
set<int> used;

ll ranges(int a, int b) {
    int a_max = 0, b_max = n-1;
    if (used.lower_bound(a) != used.begin()) a_max = *--used.lower_bound(a) + 1;
    if (used.upper_bound(b) != used.end()) b_max = *used.upper_bound(b) - 1;
    return (a - a_max + 1) * (b_max - b + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pair<int,int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.rbegin(), p.rend());
    ll res = 0;
    used.insert(p[0].second);
    for (int i = 1; i < n; i++) {
        int a = p[i].second;
        if (used.upper_bound(a) != used.end()) {
            int b = *used.upper_bound(a);
            res += p[i].first * ranges(a, b);
        }
        if (used.lower_bound(a) != used.begin()) {
            int b = *--used.lower_bound(a);
            res += p[i].first * ranges(b, a);
        }
        used.insert(a);
    }
    cout << res << '\n';
    return 0;
}