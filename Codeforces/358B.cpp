#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

bool solve(string& s, string& z) {
    for (int i = 0, j = 0; i < sz(s); i++, j++) {
        while (j < sz(z) && z[j] != s[i])
            j++;
        if (j == sz(z))
            return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    string s = "<3";
    while (n--) {
        string x;
        cin >> x;
        s += x;
        s += "<3";
    }

    string z;
    cin >> z;

    cout << (solve(s, z) ? "yes" : "no") << '\n';
}
