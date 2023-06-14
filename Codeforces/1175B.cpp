#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll INF = 1LL << 32;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l;
    cin >> l;
    ll res = 0;
    stack<ll> s;
    s.push(1);
    for (int i = 0; i < l; i++) {
        string c;
        cin >> c;
        if (c == "for") {
            int n;
            cin >> n;
            s.push(min(INF, s.top() * n));
        }
        else if (c == "end")
            s.pop();
        else
            res += s.top();
    }
    if (res < INF)
        cout << res << '\n';
    else cout << "OVERFLOW!!!\n";
    return 0;
}