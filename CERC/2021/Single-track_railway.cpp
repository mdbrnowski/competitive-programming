#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) (int)(x).size()

struct SegmentTree {
    int n;
    vector<ll> tree;
    SegmentTree(const vector<int>& a) : n(1 << (1 + __lg(sz(a)))), tree(2 * n, 0) {
        for (int i = 0; i < sz(a); i++)
            tree[n + i] = a[i];
        for (int i = n - 1; i > 0; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    void update(int i, int x) {
        i += n;
        tree[i] = x;
        for (i /= 2; i > 0; i /= 2)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    ll find_best_diff() {
        ll sum = tree[1];
        ll pref_sum = 0;
        int i = 1;
        while (i < n) {
            if (pref_sum + tree[i * 2] < sum / 2) {
                pref_sum += tree[i * 2];
                i = 2 * i + 1;
            } else
                i = 2 * i;
        }
        return min(abs(sum - 2 * pref_sum),
                   abs(sum - 2 * (pref_sum + tree[i])));
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> t(n - 1);
    for (auto& x : t)
        cin >> x;

    auto stree = SegmentTree(t);
    cout << stree.find_best_diff() << '\n';

    int k;
    cin >> k;
    while (k--) {
        int j, new_t;
        cin >> j >> new_t;
        stree.update(j - 1, new_t);
        cout << stree.find_best_diff() << '\n';
    }
    return 0;
}
