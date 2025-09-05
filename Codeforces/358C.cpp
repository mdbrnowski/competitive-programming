#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

const vector<string> M = {"Stack", "Queue", "Front"};

void solve(vi& a) {
    for (int _ = 0; _ < min(sz(a), 3); _++) {
        int i = max_element(a.begin(), a.end()) - a.begin();
        a[i] = -1;
    }
    int k = 0;
    for (auto x : a) {
        if (x > -1)
            cout << "pushBack\n";
        else {
            cout << "push" + M[k] + "\n";
            k++;
        }
    }
    if (k == 0)
        cout << k << '\n';
    else {
        cout << k << ' ';
        while (k--) {
            cout << "pop" + M[k];
            if (k) cout << ' ';
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vi a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x)
            a.push_back(x);
        else {
            solve(a);
            a.clear();
        }
    }
    for (int i = 0; i < sz(a); i++)
        cout << "pushBack\n";
}
