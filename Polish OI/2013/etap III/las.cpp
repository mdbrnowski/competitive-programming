#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef complex<ld> cld;

struct Tip {
    int which;
    ld argz;
    int mz;  // mapped argz
    bool operator<(Tip other) {
        if (mz == other.mz)
            return which > other.which;
        return mz < other.mz;
    }
};

struct Segment {
    Tip begin, end;
    bool operator<(Segment other) {
        return end.mz < other.end.mz;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    vector<Segment> segments;
    vector<ld> mapper;
    for (int i = 0; i < n; i++) {
        ld x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cld z1 = {x1, y1};
        cld z2 = {x2, y2};
        if (arg(z1) > arg(z2)) swap(z1, z2);
        segments.push_back(Segment{
            Tip{1, arg(z1), 0},
            Tip{-1, arg(z2), 0}
        });
        mapper.push_back(arg(z1));
        mapper.push_back(arg(z2));
    }

    unordered_map<ld,int> mapped;
    sort(mapper.begin(), mapper.end());
    mapper.resize(unique(mapper.begin(), mapper.end()) - mapper.begin());
    for (auto& x : mapper)
        mapped[x] = 2 * (lower_bound(mapper.begin(), mapper.end(), x) - mapper.begin());
    int m = 2 * mapper.size();

    for (auto& seg : segments)
        seg.begin.mz = mapped[seg.begin.argz],
        seg.end.mz = mapped[seg.end.argz];

    vector<int> w(m);  // w[x] - number of segments hit by a shot taken at x
    vector<Tip> tips;
    for (auto seg : segments)
        tips.push_back(seg.begin),
        tips.push_back(seg.end);
    sort(tips.begin(), tips.end());
    int cur = 0, j = 0;
    for (int i = 0; i < m; i++) {
        while (j < 2*n && tips[j].mz == i && tips[j].which == 1)
            cur += tips[j].which,
            j++;
        w[i] = cur;
        while (j < 2*n && tips[j].mz == i)
            cur += tips[j].which,
            j++;
    }

    vector<int> l(m);  // l[x] - smallest coordinate of a segment.begin struck by the shot taken at x
    sort(segments.rbegin(), segments.rend());
    int mini = m; j = 0;
    for (int i = m - 1; i >= 0; i--) {
        while (j < n && segments[j].end.mz == i)
            mini = min(mini, segments[j].begin.mz),
            j++;
        l[i] = mini;
    }

    vector<vector<int>> dp(2, vector<int>(m, 0));  // dp[p][x] - answer for p shots within range [0, x]
    bool p = 0;                                    // but with memory optimization
    while (k--) {
        p = !p;
        dp[p][0] = w[0];
        for (int x = 1; x < m; x++)
            dp[p][x] = max(dp[p][x-1],
                           l[x] ? dp[!p][l[x] - 1] + w[x] : w[x]);
    }

    cout << dp[p][m - 1] << '\n';
    return 0;
}