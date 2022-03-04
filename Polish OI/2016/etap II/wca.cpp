#include <bits/stdc++.h>
using namespace std;

int leading_ones(int n) {
    int res = 0;
    for (int i = 29; i >= 0; i--) {
        if ((1 << i) & n)
            res++;
        else if (res > 0)
            break;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int res = -1;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        res += 2 * __lg(a) + 4;
        q.push(leading_ones(a));
    }
    q.pop();
    while (q.size()) {
        int best = q.top(); q.pop();
        if (best == 1)
            res -= 2;
        else
            q.push(best - 1),
            q.pop();
    }
    cout << res << '\n';
    return 0;
}