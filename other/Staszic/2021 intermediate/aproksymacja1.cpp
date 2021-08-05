#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

bool create(float w, bool print=false) {
    vector<float> b(n);
    b[0] = a[0] - w;
    for (int i = 1; i < n; i++) {
        b[i] = max(a[i] - w, b[i-1]);
        if (abs(b[i] - a[i]) > w) return false;
    }
    if (print) for (int i = 0; i < n; i++) cout << b[i] << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for (auto& x : a) cin >> x;
    float first = 0, last = 2*1e6;
    while (first <= last) {
        float m = ((int) ((first + last) * 2) / 2) / 2.0;    // floor to halves
        if (create(m)) last = m - .5;
        else first = m + .5;
    }
    cout << fixed << setprecision(3) << first << '\n';
    create(first, true);
    return 0;
}