#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

bool solve(int n, int k, vi& a) {
    vi sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());
    int threshold = (k == 1 ? 0 : sorted_a[k - 2]);
    a.erase(remove_if(a.begin(), a.end(), [&](const int x) {
                return x > threshold;
            }),
            a.end());
    n = sz(a);

    int left_to_remove = n - (k - 1);
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] == a[j])
            i++, j--;
        else {
            if (a[i] == threshold && left_to_remove > 0)
                i++, left_to_remove--;
            else if (a[j] == threshold && left_to_remove > 0)
                j--, left_to_remove--;
            else
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (auto& x : a)
            cin >> x;

        cout << (solve(n, k, a) ? "YES" : "NO") << '\n';
    }
}
