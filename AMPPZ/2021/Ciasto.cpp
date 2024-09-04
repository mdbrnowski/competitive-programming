#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define sz(x) (int)(x).size()

constexpr ll hsh(pii x) {
    return (ll)(1e9 + 3) * x.first + x.second;
}

ll count_inversions(vector<int>& a) {
    ll res = 0;
    ordered_set s;
    for (auto x : a) {
        res += sz(s) - s.order_of_key(x);
        s.insert(x);
    }
    return res;
}

ll solve(vector<pii>& a, vector<pii>& b) {
    int n = sz(a);
    unordered_map<ll, deque<int>> mapper;
    for (int i = 0; i < n; i++) {
        mapper[hsh(b[i])].push_back(i);
    }
    vector<int> new_a(n);
    for (int i = 0; i < n; i++) {
        if (mapper[hsh(a[i])].empty())
            return -1;
        new_a[i] = mapper[hsh(a[i])].front();
        mapper[hsh(a[i])].pop_front();
    }
    return count_inversions(new_a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<pii> a(n), b(n);
        for (auto& x : a)
            cin >> x.first;
        for (auto& x : a)
            cin >> x.second;
        for (auto& x : b)
            cin >> x.first;
        for (auto& x : b)
            cin >> x.second;

        for (int i = 1; i < n; i += 2) {
            swap(a[i].first, a[i].second);
            swap(b[i].first, b[i].second);
        }

        cout << solve(a, b) << '\n';
    }
    return 0;
}
