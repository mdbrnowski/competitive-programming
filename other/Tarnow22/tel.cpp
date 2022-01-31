#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    deque<int> a;
    vector<int> c(3, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c[x]++;
        a.push_back(x);
    }
    if (n % 2 == 1) return false;
    int z = (c[1] + c[2] - c[0]) / 2;  // number of pairs (1,2)
    int zeros = 0, ones = 0;
    while (!a.empty()) {
        if (a.front() == 0) zeros++;
        if (a.front() == 1) {
            if (ones < z) ones++;
            else if (zeros) zeros--;
            else return false;
        }
        if (a.front() == 2) {
            if (z && ones) ones--, z--;
            else if (zeros) zeros--;
            else return false;
        }
        a.pop_front();
    }
    return (zeros == 0 && ones == 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Z;
    cin >> Z;
    while (Z--) {
        cout << (solve() ? "TAK" : "NIE") << '\n';
    }
    return 0;
}