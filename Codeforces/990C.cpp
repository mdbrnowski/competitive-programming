#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
constexpr int C_MAX = 3e5 + 1;

int calc(string s) {
    int opened = 0, closed = 0;
    for (auto c : s) {
        if (c == '(') {
            opened++;
        }
        if (c == ')') {
            if (opened) opened--;
            else closed++;
        }
    }
    if (opened && closed) return 1e9;
    if (opened) return opened;
    else return -closed;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(2 * C_MAX);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = calc(s);
        if (x != 1e9) a[x + C_MAX]++;
    }
    ll res = 0;
    for (int i = C_MAX; i < 2 * C_MAX; i++)
        res += (ll) a[i] * a[-(i - C_MAX) + C_MAX];
    cout << res << '\n';
    return 0;
}