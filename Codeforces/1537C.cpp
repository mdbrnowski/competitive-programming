#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        for (auto& x : h) cin >> x;
        sort(h.begin(), h.end());
        if (n == 2) {
            cout << h[0] << ' ' << h[1] << '\n';
            continue;
        }
        int min_diff = h[1] - h[0], min_diff_id = 1;
        for (int i = 2; i < n; i++)
            if (h[i] - h[i-1] < min_diff)
                min_diff = h[i] - h[i-1],  min_diff_id = i;
        for (int i = min_diff_id; i < n; i++)
            cout << h[i] << ' ';
        for (int i = 0; i < min_diff_id; i++)
            cout << h[i] << ' ';
        cout << '\n';
    }
    return 0;
}