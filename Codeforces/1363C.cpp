#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<vector<int>> graph(n + 1);
        for (int e = 0; e < n - 1; e++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (n == 1 || sz(graph[x]) == 1 || n % 2 == 0)
            cout << "Ayush\n";
        else
            cout << "Ashish\n";

    }
    return 0;
}
