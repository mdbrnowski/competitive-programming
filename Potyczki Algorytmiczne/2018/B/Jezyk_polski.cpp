#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

array<bool,26> a = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string s1;
    cin >> s1;
    int n = s1.length();
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        s[i] = s1[i] - 'a';

    ll res = 0;
    int last = -1;
    for (int i = 2; i < n; i++) {
        if (a[s[i]] == a[s[i-1]] && a[s[i-1]] == a[s[i-2]]) {
            res += (ll) (i - 2 - last) * (n - i);
            last = i - 2;
        }
    }
    cout << res << '\n';
    return 0;
}
