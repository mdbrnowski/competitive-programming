#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        int res = 0;
        for (int i = 1; i < n; i++)
            if (a[i-1].second + 1 != a[i].second) res++;
        cout << (res < k ? "Yes" : "No") << '\n';
    }
    return 0;
}