#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef unordered_set<int> usi;
constexpr int ONE = 1;  // only for visual distinction (special vertex)

void add_one_to_all(int n, vector<usi>& graph_s, vector<pii>& additions) {
    usi to_add;
    queue<int> q;
    for (int i = 2; i <= n; i++) {
        if (graph_s[ONE].count(i) == 0)
            to_add.insert(i);
        else
            q.push(i);
    }
    while (to_add.size()) {
        int v = q.front();
        q.pop();
        for (auto u : graph_s[v]) {
            if (to_add.count(u)) {
                to_add.erase(u);
                q.push(u);
                additions.push_back({ONE, u});
                graph_s[ONE].insert(u), graph_s[u].insert(ONE);
            }
        }
    }
}

void handle_differences(int n, vector<usi>& graph_s, vector<usi>& graph_d, vector<pii>& additions,
                        vector<pii>& deletions) {
    for (int v = 2; v <= n; v++) {
        for (auto u : graph_d[v]) {
            if (graph_s[v].count(u) == 0) {
                graph_s[v].insert(u);
                if (u > v)
                    additions.push_back({u, v});
            }
        }
    }
    for (int v = 2; v <= n; v++) {
        for (auto u : graph_s[v])
            if (u != ONE && graph_d[v].count(u) == 0)
                if (u > v)
                    deletions.push_back({u, v});
    }
    for (auto [v, u] : deletions)
        graph_s[v].erase(u), graph_s[u].erase(v);
}

void remove_redundant_ones(int n, vector<usi>& graph_s, vector<usi>& graph_d, vector<pii>& deletions) {
    int previous_deletions = deletions.size();
    usi to_delete;
    queue<int> q;
    for (int i = 2; i <= n; i++) {
        if (graph_d[ONE].count(i) == 0)
            to_delete.insert(i);
        else
            q.push(i);
    }
    while (to_delete.size()) {
        int v = q.front();
        q.pop();
        for (auto u : graph_d[v]) {
            if (to_delete.count(u)) {
                to_delete.erase(u);
                q.push(u);
                deletions.push_back({ONE, u});
                graph_s[ONE].erase(u), graph_s[u].erase(ONE);
            }
        }
    }
    reverse(deletions.begin() + previous_deletions, deletions.end());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m_s, m_d;
    cin >> n >> m_s;
    vector<usi> graph_s(n+1), graph_d(n+1);
    for (int i = 0; i < m_s; i++) {
        int a, b;
        cin >> a >> b;
        graph_s[a].insert(b);
        graph_s[b].insert(a);
    }
    cin >> m_d;
    for (int i = 0; i < m_d; i++) {
        int a, b;
        cin >> a >> b;
        graph_d[a].insert(b);
        graph_d[b].insert(a);
    }

    vector<pii> additions, deletions;
    add_one_to_all(n, graph_s, additions);
    handle_differences(n, graph_s, graph_d, additions, deletions);
    remove_redundant_ones(n, graph_s, graph_d, deletions);

    cout << additions.size() + deletions.size() << '\n';
    for (auto [a, b] : additions)
        cout << "+ " << a << ' ' << b << '\n';
    for (auto [a, b] : deletions)
        cout << "- " << a << ' ' << b << '\n';
    return 0;
}
