#include <bits/stdc++.h>
using namespace std;

struct Mtng {
    int a, b, id;
};

bool sorta(Mtng x, Mtng y) { return x.a < y.a; }
bool sortb(Mtng x, Mtng y) { return x.b < y.b; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<Mtng>> meetings(m);
    for (int i = 0; i < n; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        meetings[--d].push_back(Mtng{a, b, i});
    }
    for (int i = 0; i < m; i++) {
        if (meetings[i].size() < 2) {
            cout << "NIE\n";
            continue;
        }
        auto x = *min_element(meetings[i].begin(), meetings[i].end(), sortb);
        auto y = *max_element(meetings[i].begin(), meetings[i].end(), sorta);
        if (x.b < y.a)
            cout << "TAK " << x.id + 1 << ' ' << y.id + 1 << '\n';
        else
            cout << "NIE\n";
    }
    return 0;
}