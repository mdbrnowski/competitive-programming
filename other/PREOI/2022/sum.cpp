#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }

    int res = 0;
    while (ms.size()) {
        int x = *--ms.end();
        ms.erase(--ms.end());
        int power = 1 << (__lg(x) + 1);
        if (ms.count(power - x))
            ms.erase(ms.find(power - x)),
            res++;
    }
    cout << res << '\n';
    return 0;
}