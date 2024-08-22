#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

void fill_between(int lo, int hi, vector<int>& a) {
    for (; hi - 1 >= lo; hi -= 2) {
        a[hi - 1] = a[hi] * 2;
        if (hi - 2 >= lo)
            a[hi - 2] = a[hi];
    }
}

bool solve(int n, vector<int>& a) {
    int i = 0;
    while (i < n && a[i] == -1)
        i++;
    if (i == n)
        a[--i] = 1;
    fill_between(0, i, a);

    int j = i + 1;
    while (j < n && a[j] == -1)
        j++;

    while (j < n) {
        vector<int> path_i, path_j;
        int val_i = a[i], val_j = a[j];
        while (__lg(val_i) > __lg(val_j)) {
            path_i.push_back(val_i);
            val_i /= 2;
        }
        while (__lg(val_j) > __lg(val_i)) {
            path_j.push_back(val_j);
            val_j /= 2;
        }
        while (val_i != val_j) {
            path_i.push_back(val_i);
            path_j.push_back(val_j);
            val_j /= 2;
            val_i /= 2;
        }
        path_i.push_back(val_i);
        path_i.insert(path_i.end(), path_j.rbegin(), path_j.rend());

        int redundants = (j - i + 1) - sz(path_i);
        if (redundants < 0 || redundants % 2 == 1)
            return false;

        for (int k = i; k < i + sz(path_i); k++)
            a[k] = path_i[k - i];
        fill_between(i + sz(path_i), j, a);

        i = j++;
        while (j < n && a[j] == -1)
            j++;
    }

    reverse(a.begin(), a.end());
    fill_between(0, n - 1 - i, a);
    reverse(a.begin(), a.end());

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;

        if (solve(n, a)) {
            for (auto x : a)
                cout << x << ' ';
            cout << '\n';
        } else
            cout << "-1\n";
    }
    return 0;
}
