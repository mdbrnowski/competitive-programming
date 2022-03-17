#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct MonotonicQueue {
    int pop_done = 0, push_done = 0;
    deque<pair<ll,ll>> q;
    void push(ll x) {
        while (q.size() && q.back().first < x)
            q.pop_back();
        q.push_back({x, push_done});
        push_done++;
    }
    void pop() {
        while (q.size() && q.front().second <= pop_done)
            q.pop_front();
        pop_done++;
    }
    ll max() {
        return q.front().first;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d; ll p;
    cin >> n >> p >> d;
    vector<int> w(n);
    for (auto& x : w) cin >> x;

    vector<ll> decha(n - d + 1);
    decha[0] = accumulate(w.begin(), w.begin() + d, 0LL);
    for (int i = 1; i < n - d + 1; i++)
        decha[i] = decha[i - 1] - w[i - 1] + w[d + i - 1];

    int res = d;
    int a = 0, b = d - 1;
    ll sum = decha[0];
    MonotonicQueue mq;
    mq.push(decha[0]);
    while (b < n - 1) {
        b++;
        sum += w[b];
        mq.push(decha[b - d + 1]);
        while (sum - mq.max() > p) {
            sum -= w[a];
            mq.pop();
            a++;
        }
        res = max(res, b - a + 1);
    }
    cout << res << '\n';
    return 0;
}