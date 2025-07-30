#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, k;
    string s;
    cin >> n >> k >> s;

    vi res;
    vi stck;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            stck.push_back(i);
        else {
            if (!stck.empty()) {
                if (sz(res) < k) {
                    res.push_back(stck.back());
                    res.push_back(i);
                }
                stck.pop_back();
            }
        }
    }

    sort(res.begin(), res.end());
    for (auto i : res)
        cout << s[i];
    cout << '\n';
}
