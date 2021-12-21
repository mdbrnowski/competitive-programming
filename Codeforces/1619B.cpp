#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;
    for (int i = 1; i * i <= 1e9; i++)
        a.push_back(i * i);
    for (int i = 1; i * i * i <= 1e9; i++)
        a.push_back(i * i * i);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << upper_bound(a.begin(), a.end(), n) - a.begin() << '\n';
    }
    return 0;
}