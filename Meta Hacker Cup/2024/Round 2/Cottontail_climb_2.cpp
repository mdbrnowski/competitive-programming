#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) (int)(x).size()

vector<vector<ll>> increasing(9), decreasing(9);
vector<ll> mountains = {1, 2, 3, 4, 5, 6, 7, 8, 9};

bool is_increasing(int x) {
    string s = to_string(x);
    if (count(s.begin(), s.end(), '0'))
        return false;
    for (int i = 1; i < sz(s); i++) {
        if (s[i] < s[i - 1])
            return false;
    }
    if (s.back() == '9')
        return false;
    return true;
}

bool is_decreasing(int x) {
    string s = to_string(x);
    if (count(s.begin(), s.end(), '0'))
        return false;
    for (int i = 1; i < sz(s); i++) {
        if (s[i] > s[i - 1])
            return false;
    }
    if (s[0] == '9')
        return false;
    return true;
}

vector<ll> pow10 = {1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < (int)1e8; i++) {
        if (is_increasing(i))
            increasing[sz(to_string(i))].push_back(i);
        if (is_decreasing(i))
            decreasing[sz(to_string(i))].push_back(i);
    }
    for (int d = 1; d <= 8; d++) {
        for (auto x : increasing[d]) {
            for (auto y : decreasing[d]) {
                for (int mid = max(to_string(x).back() - '0', to_string(y)[0] - '0') + 1; mid <= 9; mid++) {
                    mountains.push_back(x * pow10[d + 1] + mid * pow10[d] + y);
                }
            }
        }
    }
    sort(mountains.begin(), mountains.end());

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll a, b, m;
        cin >> a >> b >> m;
        int res = 0;
        auto l = lower_bound(mountains.begin(), mountains.end(), a);
        auto r = upper_bound(mountains.begin(), mountains.end(), b);
        while (l != r) {
            if (*l % m == 0)
                res++;
            l++;
        }
        cout << "Case #" << t << ": " << res << '\n';
    }
    return 0;
}
