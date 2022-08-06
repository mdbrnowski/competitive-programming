#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& perm) {
    for (auto x : perm) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << n << '\n';
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);
        print(perm);
        swap(perm[0], perm[n-1]);
        print(perm);
        for (int i = 0; i < n - 2; i++) {
            swap(perm[i], perm[i + 1]);
            print(perm);
        }
    }
    return 0;
}