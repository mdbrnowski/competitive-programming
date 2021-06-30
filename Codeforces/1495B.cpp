#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n), d(n);
    for (auto& x : p) cin >> x;
    for (int i = 1; i < n; i++) d[i] = p[i] > p[i-1];
    int lms = 2, current_lms = 2, num_of_lms = 1;
    for (int i = 2; i < n; i++) {
        if (d[i] == d[i-1]) current_lms++;
        else current_lms = 2;
        if (current_lms > lms) num_of_lms = 1, lms = current_lms;
        else if (current_lms == lms) num_of_lms++;
    }
    if (num_of_lms != 2 || (lms & 1) == 0) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (d[i-1] && !d[i]) {
            int l = i-1, r = i;
            while (l-1 > 0 && d[l-1]) l--;
            while (r+1 < n && !d[r+1]) r++;
            if (i-l+1 == lms && r-i+2 == lms) {
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}