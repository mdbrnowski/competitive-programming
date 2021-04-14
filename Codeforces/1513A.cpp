#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if ((n - 1) / 2 < k) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> arr;
        for (int i = 1; i <= n; i++) arr.push_back(i);
        int i = 1;
        while (k--) {
            arr.insert(arr.begin() + i, arr.back());
            arr.pop_back();
            i += 2;
        }
        for (int i = 0; i < n; i++) cout << arr[i] << ' ';
        cout << '\n';
    }
    return 0;
}