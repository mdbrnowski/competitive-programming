#include <bits/stdc++.h>
using namespace std;

int pocz, kon;
int current;
bool found;
vector<int> visited;
vector<int> res;
vector<vector<int>> graph;

void DFS(int x, int parent) {
    visited[x] = current;
    for (auto& v : graph[x]) {
        if (v == parent) continue;
        if (visited[v] == current) {
            pocz = x;
            kon = v;
            found = true;
        } else {
            res[v] = x;
            DFS(v, x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    visited.resize(n+1), res.resize(n+1), graph.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        if(res[i] == 0) {
            found = false;
            current++;
            DFS(i, i);

            if(found == false) {
                cout<<"NIE\n";
                return 0;
            }
            for (auto& v : graph[pocz])
                if (v == kon) swap(v, graph[pocz].back());
            graph[pocz].pop_back();
            for (auto& v : graph[kon])
                if (v == pocz) swap(v, graph[kon].back());
            graph[kon].pop_back();
            res[pocz] = kon;
            current++;
            DFS(pocz, pocz);
        }
    }
    cout << "TAK\n";
    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
    return 0;
}