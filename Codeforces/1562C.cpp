#include <bits/stdc++.h>
using namespace std;

void print(int a, int b, int c, int d) {
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        if (find(s.begin()+n/2, s.end(), '0') != s.end()) {
            int a = find(s.begin()+n/2, s.end(), '0') - s.begin();
            print(1, a+1, 1, a);
        }
        else if (find(s.begin(), s.end()-n/2, '0') != s.end()-n/2) {
            int a = find(s.begin(), s.end()-n/2, '0') - s.begin() + 1;
            print(a+1, n, a, n);
        }
        else print(1, n-1, 2, n);
    }
    return 0;
}