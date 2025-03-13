#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

// a struct that stores the best block of each pattern and
// the best block overall
struct M {
    const vector<pi>* aw;
    const vector<ll>* dp;
    map<int, int> best_by_pattern;
    int best_overall = -1;

    void add(int j) {
        if (best_by_pattern.count((*aw)[j].second)) {
            int i = best_by_pattern[(*aw)[j].second];
            if ((*dp)[j] > (*dp)[i])
                best_by_pattern[(*aw)[j].second] = j;
        } else {
            best_by_pattern[(*aw)[j].second] = j;
        }

        if (best_overall == -1 || (*dp)[best_overall] < (*dp)[j]) {
            best_overall = j;
        }
    }

    vector<int> get_best(int pattern) {
        vector<int> result;
        if (best_overall > -1)
            result.push_back(best_overall);
        if (best_by_pattern.count(pattern))
            result.push_back(best_by_pattern[pattern]);
        return result;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, c;
    cin >> n >> c;

    vector<pi> aw(n);
    for (auto& [x, y] : aw)
        cin >> x >> y;

    vector<ll> dp(n, 0);
    for (int i = 0; i < n; i++)
        dp[i] = aw[i].first;

    M m = M{&aw, &dp};

    vector<int> buffer;
    for (int i = n - 1; i >= 0; i--) {
        for (int j : m.get_best(aw[i].second)) {
            dp[i] = max(dp[i], dp[j] + aw[i].first - (aw[i].second == aw[j].second ? 0 : c));
        }
        buffer.push_back(i);
        if (i == 0 || aw[i].first != aw[i - 1].first) {
            for (auto x : buffer)
                m.add(x);
            buffer.clear();
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
