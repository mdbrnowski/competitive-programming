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
        priority_queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push({x, i+1});
        }
        int res = 0;
        vector<int> res_all;
        while (true) {
            int a1, a2, p1, p2;
            tie(a1, p1) = q.top(); q.pop();
            tie(a2, p2) = q.top(); q.pop();
            if (a2 == 0) break;
            res++;
            res_all.push_back(p1);
            res_all.push_back(p2);
            q.push({a1-1, p1});
            q.push({a2-1, p2});
        }
        cout << res << '\n';
        for (int i = 0; i < 2*res; i+=2)
            cout << res_all[i] << ' ' << res_all[i+1] << '\n';
    }
    return 0;
}