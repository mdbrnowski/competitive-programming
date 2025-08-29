#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(const vector<ll>& a, int m) {
    vector<ll> b;
    multiset<ll> stack_ends;

    for (auto x : a) {
        if (x == 1 && m > 0) {
            stack_ends.insert(1);
            m--;
        } else if (__builtin_popcountll(x) == 1 && stack_ends.count(x / 2)) {
            stack_ends.erase(stack_ends.find(x / 2));
            stack_ends.insert(x);
        } else {
            b.push_back(x);
        }
    }

    for (auto x : b) {
        if (stack_ends.empty())
            return false;
        auto it = stack_ends.lower_bound(1LL << (__lg(x)));
        if (it == stack_ends.end())
            return false;
        stack_ends.erase(it);
    }

    return true;
}

void solve(const vector<ll>& a) {
    int end = count(a.begin(), a.end(), 1);
    if (!f(a, end)) {
        cout << "-1\n";
        return;
    }

    int first = end / 2, last = end;
    while (first <= last) {
        int m = (first + last) / 2;
        if (!f(a, m))
            first = m + 1;
        else
            last = m - 1;
    }

    for (int i = first; i <= end; i++) {
        cout << i << ' ';
    }

    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<ll> a;
    while (n--) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    solve(a);
}
