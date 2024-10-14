#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) (int)(x).size()
constexpr int MOD = 1e9 + 7;

unordered_set<int> indices;

bool compare(string a, string b) {
    int changes = 0;
    for (int i = 0; i < sz(a); i++) {
        if (a[i] != b[i])
            changes++;
    }
    return changes == 1;
}

pair<ll, ll> get_hsh(string s) {
    ll hsh1 = 0, hsh2 = 0;
    for (int i = 0; i < sz(s); i++) {
        if (indices.count(i))
            hsh1 = (hsh1 * 31 + (s[i] - 'a' + 1)) % MOD;
        else
            hsh2 = (hsh2 * 31 + (s[i] - 'a' + 1)) % MOD;
    }
    return {hsh1, hsh2};
}

struct Mechanism {
    set<string> all_strings;
    unordered_map<int, unordered_map<int, vector<string>>> a;
    void insert(string s) {
        if (all_strings.count(s))
            return;
        all_strings.insert(s);
        auto [hsh1, hsh2] = get_hsh(s);
        a[sz(s)][hsh1].push_back(s);
        a[sz(s)][hsh2].push_back(s);
    }
    bool check(string s) {
        auto [hsh1, hsh2] = get_hsh(s);
        for (auto z : a[sz(s)][hsh1]) {
            if (compare(z, s))
                return true;
        }
        for (auto z : a[sz(s)][hsh2]) {
            if (compare(z, s))
                return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    Mechanism mech;
    mt19937 mt(time(0));
    for (int i = 0; i <= 600000; i++) {
        if (mt() % 2 == 0)
            indices.insert(i);
    }
    while (n--) {
        string s;
        cin >> s;
        mech.insert(s);
    }
    while (m--) {
        string s;
        cin >> s;
        cout << (mech.check(s) ? "YES" : "NO") << '\n';
    }
    return 0;
}
