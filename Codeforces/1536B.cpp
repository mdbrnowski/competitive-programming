#include <bits/stdc++.h>
using namespace std;

string increment(string m) {
    if (m.back() != 'z') {
        m.back()++;
        return m;
    }
    if (m.size() == 1) return "aa";
    m.pop_back();
    return increment(m) + "a";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        string mex = "a";
        while (true) {
            if (s.find(mex) == string::npos) break;
            mex = increment(mex);
        }
        cout << mex << '\n';
    }
    return 0;
}