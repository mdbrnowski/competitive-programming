#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, r, k;
    cin >> n >> r >> k;
    priority_queue<pair<int,int>> q;
    ll sum = 0, res = 0, goal = n * k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        q.push({-b, a});
        sum += a;
    }
    while (sum < goal && !q.empty()) {
        int a = q.top().second, b = -q.top().first;
        q.pop();
        ll p = min(r - a, goal - sum);
        sum += p;
        res += b * p;
    }
    cout << (sum >= goal ? res : -1) << '\n';
    return 0;
}