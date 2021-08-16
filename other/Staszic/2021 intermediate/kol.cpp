#include <bits/stdc++.h>
using namespace std;

vector<int> link, mass, min_iq, max_iq, colony_size;

int find(int x) {
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (colony_size[x] < colony_size[y]) swap(x, y);
    link[y] = x;
    colony_size[x] += colony_size[y];
    mass[x] += mass[y];
    min_iq[x] = min(min_iq[x], min_iq[y]);
    max_iq[x] = max(max_iq[x], max_iq[y]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    link.resize(n), mass.resize(n), min_iq.resize(n), max_iq.resize(n), colony_size.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> mass[i] >> min_iq[i];
        max_iq[i] = min_iq[i];
        colony_size[i] = 1;
        link[i] = i;
    }
    string command;
    while (cin >> command) {
        if (command == "JOIN") {
            int x, y;
            cin >> x >> y;
            unite(--x, --y);
        }
        else {
            int x;
            cin >> x;
            x = find(x-1);
            if (command == "IQ_MAX")
                cout << max_iq[x];
            else if (command == "IQ_MIN")
                cout << min_iq[x];
            else
                cout << mass[x];
            cout << '\n';
        }
    }
    return 0;
}