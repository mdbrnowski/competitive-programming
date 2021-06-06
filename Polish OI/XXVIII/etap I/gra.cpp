#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, X, z;
    cin >> n >> X >> z;
    vector<int> res(n, 0);
    vector<pair<int,int>> gaps;
    REP(i, n) {
        int k; cin >> k;
        REP(j, k) {
            int d; cin >> d;
            gaps.push_back({d-1, i});
        }
    }
    sort(gaps.rbegin(), gaps.rend());
    for (auto gap : gaps) {
        int i = gap.second;
        if (i != n-1) res[i] = res[i+1] = min(res[i] + 1, res[i+1]);
        else res[i]++;
    }
    REP(i, z) {
        int j; cin >> j;
        cout << res[j-1] << '\n';
    }
    return 0;
}