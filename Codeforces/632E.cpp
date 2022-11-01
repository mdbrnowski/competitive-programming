#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cd;
constexpr int MAX_A = 1001;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1 << (__lg(a.size() + b.size() - 1) + 1);
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(MAX_A);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    vector<int> b(a.begin(),  a.end());
    k--;
    while (k) {
        if (k & 1) {
            b = multiply(a, b);
            for (auto& x : b) if (x) x = 1;
        }
        a = multiply(a, a);
        for (auto& x : a) if (x) x = 1;
        k /= 2;
    }

    for (int i = 0; i < (int) b.size(); i++)
        if (b[i])
            cout << i << ' ';
    cout << '\n';
    return 0;
}