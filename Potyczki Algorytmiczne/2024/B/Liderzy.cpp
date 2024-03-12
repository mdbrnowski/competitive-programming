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
    sort(counts.rbegin(), counts.rend());

    int i = 0, j = counts.size() - 1;
    while (i <= j) {
        while (i < j && counts[i] > 1) {
            int val = min(counts[i] - 1, counts[j]);
            counts[i] -= val;
            counts[j] -= val;
            if (counts[j] == 0)
                j--;
        }
        i++;
    }
    cout << i << '\n';
    return 0;
}
