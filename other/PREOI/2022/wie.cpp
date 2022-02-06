#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> h;

bool check(int k) {
    for (int i = 1; i < n; i++)
        if (h[i] * n >= (h[n] + k) * i)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    h.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == 'D') h[i] = h[i-1] - 1;
        else h[i] = h[i - 1] + 1;
    }
    int a = 0, b = 2e6;
    while (a <= b) {
        int m = (a + b) / 2;
        if (check(m)) b = m - 1;
        else a = m + 1;
    }
    cout << a << '\n';
    return 0;
}