#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; ll k;
    cin >> n >> k;
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = a[n + i] = x;
    }

    if (2 * k >= accumulate(a.begin(), a.end(), 1LL)) {
        cout << 1 << '\n';
        return 0;
    }

    vector<vector<int>> jump(2 * n, vector<int>(__lg(n) + 1));
    int head = 0, tail = 0; ll sum = a[0];
    while (tail < n) {
        while (sum <= k) {
            head++;
            sum += a[head];
        }
        jump[tail][0] = head;
        sum -= a[tail];
        tail++;
    }
    for (int i = n; i < 2 * n; i++)
        jump[i][0] = min(2 * n, jump[i-n][0] + n);

    for (int j = 1; j < (int) jump[0].size(); j++) {
        for (int i = 0; i < 2 * n; i++) {
            if (jump[i][j-1] < 2 * n)
                jump[i][j] = jump[jump[i][j-1]][j-1];
            else
                jump[i][j] = 2 * n;
        }
    }

    int res = INT_MAX;
    for (int start = 0; start < n; start++) {
        int i = start;
        int cur_res = 0;
        for (int j = jump[0].size() - 1; j >= 0; j--) {
            if (jump[i][j] < start + n)
                i = jump[i][j], cur_res += (1 << j);
        }
        res = min(res, cur_res + 1);
    }
    cout << res << '\n';
    return 0;
}