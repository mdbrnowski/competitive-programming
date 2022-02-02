#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

inline bool is_safe(int n) {
    return __builtin_popcount(n) % 2 == 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int loosing = 0;
    if (M == 1) {
        for (int i = N; i >= 1; i--)
            if (!is_safe(i - 1)) {
                loosing = i;
                break;
            }
    }
    if (M == 2) {
        for (int i = N; i >= 2; i--)
            if (!is_safe(i - 1) && !is_safe(i - 2)) {
                loosing = i;
                break;
            }
    }

    for (int i = 1; i <= N; i++)
        if (is_safe(i) && i - loosing > M)
            loosing = i;

    bool ok =  (loosing == N || loosing + M < N);
    cout << (ok ? "Darmowe ciasteczka!" : "Stawiasz") << '\n';
    return 0;
}