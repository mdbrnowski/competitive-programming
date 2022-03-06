#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int v, int prev, vector<vector<int>>& tree, vector<int>& subtree_size) {
    for (auto u : tree[v])
        if (u != prev) {
            dfs(u, v, tree, subtree_size);
            subtree_size[v] += subtree_size[u];
        }
}

int find_centroid(int v, int prev, int n, vector<vector<int>>& tree, vector<int>& subtree_size) {
    for (auto u : tree[v]) {
        if (u != prev && subtree_size[u] > n / 2)
            return find_centroid(u, v, n, tree, subtree_size);
    }
    return v;
}

void solve_subset_sum(vector<bool>& b, vector<int>& subtrees, vector<int>& subtree_size) {
    // solves subset sum problem in O(n*sqrt(n))
    int n = b.size();
    multiset<int> ms;
    for (auto x : subtrees)
        ms.insert(subtree_size[x]);
    b[0] = 1;
    for (auto it = ms.begin(); it != ms.end(); it++) {
        int x = *it;
        vector<int> new_sums, new_sums_2;
        for (int i = n - x - 1; i >= 0; i--) {
            if (b[i] == 1 && b[i + x] == 0) {
                b[i + x] = 1;
                new_sums.push_back(i + x);
            }
        }
        int j = ms.count(x) - 1;
        while (j--) {
            it++;
            for (auto i : new_sums) {
                if (i + x < n && b[i + x] == 0) {
                    b[i + x] = 1;
                    new_sums_2.push_back(i + x);
                }
            }
            new_sums = new_sums_2;
            new_sums_2.clear();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> subtree_size(n, 1);
    dfs(0, 0, tree, subtree_size);
    int centroid = find_centroid(0, 0, n, tree, subtree_size);
    subtree_size.assign(n, 1);
    dfs(centroid, centroid, tree, subtree_size);

    ll res = accumulate(subtree_size.begin(), subtree_size.end(), 0LL) - n;

    vector<bool> b(n, false);
    solve_subset_sum(b, tree[centroid], subtree_size);

    ll left = 0, right = 0;
    for (int i = (n - 1) / 2; i >= 0; i--)
        if (b[i]) {
            right = i;
            break;
        }
    for (int i = (n - 1) / 2; i < n; i++)
        if (b[i]) {
            left = i;
            break;
        }
    res += max(left * (n - left - 1), right * (n - right - 1));

    cout << n - 1 << ' ' << res << '\n';
    return 0;
}