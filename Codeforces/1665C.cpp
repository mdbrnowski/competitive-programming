#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> children(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int p;
            cin >> p;
            children[--p]++;
        }
        sort(children.rbegin(), children.rend());
        while (children.back() == 0)
            children.pop_back();
        children.push_back(1);  // root

        int res = children.size();
        for (int i = 0; i < (int) children.size(); i++)
            children[i] += i;
        while (true) {
            int& m = *max_element(children.begin(), children.end());
            if (m <= res)
                break;
            res++, m--;
        }
        cout << res << '\n';
    }
    return 0;
}