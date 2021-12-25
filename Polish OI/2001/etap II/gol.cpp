#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_P = 300000;
vector<bool> is_prime(MAX_P, true);

bool f(int n, int p, vector<int>& res) {
    if (n == 0) return true;
    for (int i = p; i > 2; i -= 2) {
        if (!is_prime[i] || n < i) continue;
        res.push_back(i);
        if (f(n - i, i-2, res)) return true;
        res.pop_back();
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX_P; i++) {
        if (is_prime[i])
            for (int j = i * i; j < MAX_P; j += i)
                is_prime[j] = false;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> res;
        f(n, MAX_P - 1, res);
        sort(res.begin(), res.end());
        cout << res.size() << '\n';
        for (auto x : res) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}