#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve() {
    string a, s, res = "";
    cin >> a >> s;
    a.insert(0, max(0, (int) s.size() - (int) a.size()), '0');
    s.insert(0, max(0, (int) a.size() - (int) s.size()), '0');
    while (s.size() && a.size()) {
        if (a.back() <= s.back()) {
            res += s.back() - a.back() + '0';
            a.pop_back();
            s.pop_back();
        } else {
            if (s.size() < 2 || s[s.size() - 2] != '1') return -1;
            res += 10 - a.back() + s.back() + '0';
            a.pop_back();
            s.pop_back(); s.pop_back();
        }
    }
    while (a.size() && a.back() == '0') a.pop_back();
    if (a.size()) return -1;
    reverse(res.begin(), res.end());
    return stoll(res);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}