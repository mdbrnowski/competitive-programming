#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> students(n);
        vector<vector<ll>> uni(n);
        REP(i, n) {
            int x;
            cin >> x;
            students[i] = x-1;
        }
        REP(i, n) {
            int x;
            cin >> x;
            uni[students[i]].push_back(x);
        }
        REP(i, n) {
            sort(uni[i].rbegin(), uni[i].rend());
            partial_sum(uni[i].begin(), uni[i].end(), uni[i].begin());
        }
        vector<ll> res(n);
        REP(i, n)
            for (int k = 1; k <= uni[i].size(); k++)
                res[k-1] += uni[i][uni[i].size() / k * k - 1];

        REP(i, n) cout << res[i] << ' ';
        cout << '\n';
    }
    return 0;
}