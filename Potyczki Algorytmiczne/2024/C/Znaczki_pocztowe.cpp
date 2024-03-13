#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    unordered_set<int> s(ms.begin(), ms.end());
    vector<int> counts;
    for (int x : s)
        counts.push_back(ms.count(x));

    vector<int> res(n+1, 0);
    for (int x : counts)
        for (int i = 1; i <= x; i++)
            res[i] += x - x % i;

    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';
    return 0;
}
