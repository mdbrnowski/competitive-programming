#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> cnt(26);
        for (const auto& c : s)
            cnt[c - 'a']++;

        priority_queue<pair<int, char>> q;
        for (char c = 'a'; c <= 'z'; c++)
            if (cnt[c - 'a'])
                q.push({cnt[c - 'a'], c});

        string z;
        while (q.size()) {
            auto [r1, c1] = q.top();
            q.pop();
            if (q.size() && z.size() && z.back() == c1) {
                auto [r2, c2] = q.top();
                q.pop();
                z += c2;
                q.push({r1, c1});
                if (r2 > 1)
                    q.push({r2 - 1, c2});
            } else {
                z += c1;
                if (r1 > 1)
                    q.push({r1 - 1, c1});
            }
        }

        cout << z << '\n';
    }
}
