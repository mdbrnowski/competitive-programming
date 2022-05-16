#include <bits/stdc++.h>
using namespace std;

struct Range {
    int a, b, prod;
    bool operator<(Range x) const {
        return prod < x.prod;
    }
};

Range calc(int a, int b, vector<int>& vec) {
    int prod = 1;  // kinda log of it
    int sign = 1;
    for (int i = a; i <= b; i++) {
        if (abs(vec[i]) == 2) prod += 1;
        if (vec[i] < 0) sign *= -1;
    }
    if (sign > 0)
        return Range{a, b, prod};

    Range from_start{a, b, prod}, from_end{a, b, prod};
    for (int i = a; i <= b; i++) {
        if (abs(vec[i]) == 2) from_start.prod -= 1;
        if (vec[i] < 0) { from_start.a = i + 1; break; }
    }
    for (int i = b; i >= a; i--) {
        if (abs(vec[i]) == 2) from_end.prod -= 1;
        if (vec[i] < 0) { from_end.b = i - 1; break; }
    }
    return max(from_start, from_end);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (auto& x : vec) cin >> x;
        Range best{0, -1, 1};
        int last_zero = -1;
        for (int i = 0; i < n; i++) {
            if (vec[i] == 0)
                best = max(best, calc(last_zero + 1, i - 1, vec)),
                last_zero = i;
        }
        best = max(best, calc(last_zero + 1, n - 1, vec));
        cout << best.a << ' ' << n - 1 - best.b << '\n';
    }
    return 0;
}