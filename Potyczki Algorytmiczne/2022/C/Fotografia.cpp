#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define sz(x) (int)(x).size()

struct Cycle {
    int k;
    vi ind;
    array<vector<pii>,2> res;
    void solve() {
        k = sz(ind);
        if (k == 1)
            return;
        else if (k == 2)
            res[0].push_back({ind[0], ind[1]});
        else {
            for (int i = 0; i < (k-1)/2; i++)
                res[0].push_back({ind[i], ind[k-2-i]});
            for (int i = 0; i < k/2; i++)
                res[1].push_back({ind[i], ind[k-1-i]});
        }
    }
};

void print_result(vector<Cycle>& cycles, int round) {
    cout << 2 * accumulate(cycles.begin(), cycles.end(), 0,
                           [round](int a, Cycle b){ return a + sz(b.res[round]); }) << '\n';
    for (int c = 0; c < sz(cycles); c++)
        for (int r = 0; r < sz(cycles[c].res[round]); r++)
            cout << cycles[c].res[round][r].first + 1 << ' ';
    for (int c = sz(cycles)-1; c >= 0; c--)
        for (int r = sz(cycles[c].res[round])-1; r >= 0; r--)
            cout << cycles[c].res[round][r].second + 1 << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi h(n);
    for (auto& x : h) cin >> x;
    vi mapper(h.begin(), h.end());
    sort(mapper.begin(), mapper.end());
    for (auto& x : h)
        x = lower_bound(mapper.begin(), mapper.end(), x) - mapper.begin();

    vector<Cycle> cycles;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            cycles.push_back(Cycle{});
        int j = i;
        while (!visited[j]) {
            cycles.back().ind.push_back(j);
            visited[j] = true;
            j = h[j];
        }
    }

    int max_k = 0;
    for (auto& C : cycles)
        C.solve(),
        max_k = max(max_k, C.k);

    if (max_k == 1)
        cout << "0\n";
    else if (max_k == 2) {
        cout << "1\n";
        print_result(cycles, 0);
    }
    else {
        cout << "2\n";
        print_result(cycles, 0);
        print_result(cycles, 1);
    }
    return 0;
}
