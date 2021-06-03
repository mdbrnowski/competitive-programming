#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    multiset<int> drank;
    int res = 0; long long sum = 0;
    for (auto x : a) {
        if (x >= 0) sum += x, res++;
        else {
            if (sum >= -x) {
                sum += x, res++;
                drank.insert(x);
            } else if (drank.size() > 0 && *drank.begin() < x && sum - *drank.begin() >= -x) {
                sum = sum - *drank.begin() + x;
                drank.erase(drank.begin());
                drank.insert(x);
            }
        }
    }
    cout << res;
    return 0;
}