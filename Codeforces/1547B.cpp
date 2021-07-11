#include <bits/stdc++.h>
using namespace std;

bool is_good(string s) {
    char c = 'a' + s.size() - 1;
    while (!s.empty()) {
        if (s.front() == c) s = s.substr(1, s.size()-1);
        else if (s.back() == c) s.pop_back();
        else return false;
        c--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << (is_good(s) ? "YES" : "NO") << '\n';
    }
    return 0;
}