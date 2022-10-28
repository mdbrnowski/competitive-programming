#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int A_MAX = 2000001;
    vector<ll> arr(A_MAX, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a]++;
    };
    ll res = 0;
    for (int i = 1; i < A_MAX; i++) {
        if (!arr[i]) continue;
        res += arr[i] * (arr[i] - 1);
        for (int j = 2*i; j < A_MAX; j += i)
            res += arr[i] * arr[j];
    }
    cout << res << '\n';
    return 0;
}