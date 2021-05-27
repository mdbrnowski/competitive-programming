#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++)
        if (s[i] != s[n-i-1])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        int z = count(s.begin(), s.end(), '0');
        if (is_palindrome(s)) {
            if (z == 1 | (z & 1) == 0) cout << "BOB\n";
            else cout << "ALICE\n";
        } else {
            if ((n & 1) == 1 && z == 2 && s[n/2] =='0') cout << "DRAW\n";
            else cout << "ALICE\n";
        }
    }
    return 0;
}