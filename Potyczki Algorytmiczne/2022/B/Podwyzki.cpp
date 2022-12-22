#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool is_increasing(vi& a) {
    for (int i = 1; i < (int) a.size(); i++)
        if (a[i-1] >= a[i])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& x : a) cin >> x;
    vi max_start(a), min_start(a);  // max/min [0,i]
    vi max_end(a), min_end(a);      // max/min [i,n)
    for (int i = 1; i < n; i++)
        max_start[i] = max(max_start[i-1], a[i]),
        min_start[i] = min(min_start[i-1], a[i]);
    for (int i = n-2; i >= 0; i--)
        max_end[i] = max(max_end[i+1], a[i]),
        min_end[i] = min(min_end[i+1], a[i]);

    if (k == 2) {
        for (int i = 0; i < n-1; i++) {
            if (min_start[i] >= max_end[i+1]) {
                cout << "TAK\n" << i + 1 << '\n';
                return 0;
            }
        }
        cout << "NIE\n";
    }
    else if (is_increasing(a)) {
        cout << "NIE\n";
    }
    else if (k >= 4) {
        int s = n - 1;
        while (a[s] > max_start[s-1]) s--;
        int p = max_element(a.begin(), a.begin()+s) - a.begin();

        cout << "TAK\n";
        vector<bool> res(n, false);
        res[p] = res[p+1] = res[s+1] = true;
        k -= 4 - (p == 0) - (s == n-1);
        for (int i = 1; k && i < n; i++)
            if (!res[i]) res[i] = true, k--;

        for (int i = 1; i < n; i++)
            if (res[i]) cout << i << ' ';
        cout << '\n';
    }
    else {
        int p = max_element(a.begin(), a.end()-1) - a.begin();
        if (a[p] < a[n-1]) {
            p = min_element(a.begin()+1, a.end()) - a.begin();
            if (a[p] > a[0])
                { cout << "NIE\n"; return 0; }
        }
        cout << "TAK\n";
        vector<bool> res(n, false);
        res[p] = res[p+1] = true;
        k -= 3 - (p == 0);
        for (int i = 1; k && i < n; i++)
            if (!res[i]) res[i] = true, k--;

        for (int i = 1; i < n; i++)
            if (res[i]) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
