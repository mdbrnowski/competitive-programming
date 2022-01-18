#include <bits/stdc++.h>
using namespace std;

void calc_phi(vector<int>& phi, int n) {
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i <= n; i++) {
        if (phi[i] != i) continue;
        for (int j = i; j <= n; j += i)
            phi[j] -= phi[j] / i;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> phi(n+1);
    calc_phi(phi, n);
    cout << 1 + 2 * accumulate(phi.begin(), phi.end(), 0LL) << '\n';
    return 0;
}