#include <bits/stdc++.h>
using namespace std;

struct C {
    int id, previous;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<C> contestants;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "TAK") {
            contestants.push_back(C{i + 1, x});
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << contestants[i].id << ' ';
    }

    contestants.erase(contestants.begin(), contestants.begin() + 10);
    contestants.erase(remove_if(
                          contestants.begin(),
                          contestants.end(),
                          [](const C &c) { return c.previous >= 2; }),
                      contestants.end());

    for (int i = 0; i < 10; i++) {
        cout << contestants[i].id << ' ';
    }
    cout << "\n";
}
