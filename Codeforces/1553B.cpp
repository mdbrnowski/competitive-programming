#include <bits/stdc++.h>
using namespace std;

string s, t;

bool go_left(int i, int i_t) {
    if (i_t == t.size()) return true;
    if (s[i] != t[i_t]) return false;
    bool r = false;
    if (i >= 0) r |= go_left(i - 1, i_t + 1);
    return r;
}

bool go_right(int i, int i_t) {
    if (i_t == t.size()) return true;
    if (s[i] != t[i_t]) return false;
    bool r = false;
    if (i + 1 < s.size()) r |= go_right(i + 1, i_t + 1);
    if (i >= 0) r |= go_left(i - 1, i_t + 1);
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        cin >> s >> t;
        bool ok = false;
        for (int i = 0; i < s.size(); i++)
            if (go_right(i, 0)) ok = true;
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}