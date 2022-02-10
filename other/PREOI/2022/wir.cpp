#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void parent_dfs(int v, int prev, vector<unordered_set<int>>& graph, vector<int>& parent) {
    parent[v] = prev;
    for (auto u : graph[v])
        if (u != prev)
            parent_dfs(u, v, graph, parent);
}

void dfs(int v, int& s, vector<unordered_set<int>>& graph, deque<int>& q, unordered_map<int,bool>& visited) {
    for (auto u : graph[v])
        if (!visited[u]) {
            s++;
            visited[u] = true;
            q.push_front(u);
            return;
        }
    q.pop_front();
}

void change_comp(int v, int prev, vector<unordered_set<int>>& graph, int c, vector<int>& comp) {
    comp[v] = c;
    for (auto u : graph[v])
        if (u != prev)
            change_comp(u, v, graph, c, comp);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    x--;
    vector<int> g(n - 2);
    for (auto& gi : g) cin >> gi;
    vector<unordered_set<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].insert(b);
        tree[b].insert(a);
    }

    ordered_set not_touched;
    for (int i = 1; i < n; i++)
        not_touched.insert(i);

    int c = 0;
    vector<int> comp(n, c), comp_size(n, 0);
    comp_size[c] = n;
    vector<int> parent(n);
    parent_dfs(0, 0, tree, parent);
    for (int t = 0; t < n - 1; t++) {
        not_touched.erase(x);
        int p = parent[x];
        tree[x].erase(p);
        tree[p].erase(x);

        int x_size = 1, p_size = 1;
        deque<int> q1, q2;
        q1.push_front(x);
        q2.push_front(p);
        unordered_map<int,bool> visited;
        visited[x] = visited[p] = true;
        while (q1.size() && q2.size()) {
            while (q1.size() && x_size == p_size) {
                int v = q1.front();
                dfs(v, x_size, tree, q1, visited);
            }
            while (q2.size() && x_size > p_size) {
                int v = q2.front();
                dfs(v, p_size, tree, q2, visited);
            }
        }

        int res = x_size;
        if (x_size > p_size) {
            res = comp_size[comp[x]] - p_size;
            swap(x, p);
            swap(x_size, p_size);
        }
        comp_size[comp[p]] -= x_size;
        comp_size[++c] = x_size;
        change_comp(x, x, tree, c, comp);

        cout << res << '\n';
        if (t < n - 2) {
            x = (res + g[t]) % (n - t - 2);
            x = *not_touched.find_by_order(x);
        }
    }
    return 0;
}