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
        pair<int,int> mini = {INT_MAX, 0};
        pair<int,int> maxi = {INT_MIN, 0};
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > maxi.first) maxi = {x, i};
            if (x < mini.first) mini = {x, i};
        }
        cout << min({
            max(mini.second + 1, maxi.second + 1),
            max(n - mini.second, n - maxi.second),
            mini.second + 1 + n - maxi.second,
            maxi.second + 1 + n - mini.second,
        }) << '\n';
    }
    return 0;
}