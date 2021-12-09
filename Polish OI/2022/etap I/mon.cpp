#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct mov {
    int id, time, deadline;
    bool operator<(mov x) {
        return deadline < x.deadline;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<mov> a(n);
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        cin >> a[i].time >> a[i].deadline;
    }
    sort(a.begin(), a.end());
    set<pair<int,int>> s;
    unordered_set<int> schedule;
    for (int i = n-1; i >= 0; i--) {
        s.insert({a[i].time, a[i].id});
        int t = a[i].deadline - (i ? a[i-1].deadline : 0);
        while (t && !s.empty()) {
            auto it = s.begin();
            if (it->first <= t) {
                t -= it->first;
                schedule.insert(it->second);
            }
            else {
                s.insert({it->first - t, it->second});
                t = 0;
            }
            s.erase(it);
        }
    }
    cout << schedule.size() << '\n';
    ll t = 1;
    for (auto x : a) {
        if (!schedule.count(x.id)) continue;
        cout << x.id << ' ' << t << '\n';
        t += x.time;
    }
    return 0;
}