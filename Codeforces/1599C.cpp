#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double binom(int n, int k) {
    // assume that k is small
    if (n < k) return 0;
    ll res = 1;
    for (int i = n - k + 1; i <= n; i++)
        res *= i;
    for (int i = k; i > 0; i--)
        res /= i;
    return (double) res;
}

double prob(int n, int m, float p) {
    return (binom(m, 3) + binom(m, 2) * binom(n - m, 1) + binom(m, 1) * binom(n - m, 2) / 2) / binom(n, 3);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double p;
    cin >> n >> p;

    int a = 0, b = n;
    while (a <= b) {
        int mid = (a + b) / 2;
        if (prob(n, mid, p) >= p)
            b = mid - 1;
        else
            a = mid + 1;
    }
    cout << a << '\n';
    return 0;
}
