#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    cin >> s >> n;
    set<tuple<int, int, int>> v_prev, v = {{0, 0, 1}};
    for (int i = 0; i < sz(s); i++) {
        swap(v_prev, v);
        v.clear();
        for (auto [pos, used, dir] : v_prev) {
            if (s[i] == 'F') {
                v.insert({pos + dir, used, dir});
                if (used < n)
                    v.insert({pos, used + 1, -dir});
            } else {
                v.insert({pos, used, -dir});
                if (used < n)
                    v.insert({pos + dir, used + 1, dir});
            }
        }
    }
    for (auto it = v.begin(); it != v.end();) {
        if (get<1>(*it) % 2 != n % 2)
            it = v.erase(it);
        else
            ++it;
    }
    cout << max(abs(get<0>(*v.begin())), abs(get<0>(*prev(v.end())))) << '\n';
    return 0;
}
