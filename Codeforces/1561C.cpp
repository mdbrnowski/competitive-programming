#include <bits/stdc++.h>
using namespace std;

struct cave{
    vector<int> monsters;
    int hardest = 0;
    void determine_hardest() {
        for (int i = 0; i < monsters.size(); i++)
            hardest = max(hardest, monsters[i] - i);
    }
    bool operator<(cave x) {return hardest < x.hardest;}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<cave> caves(n);
        for (auto& c : caves) {
            int k;
            cin >> k;
            c.monsters.resize(k);
            for (auto& m : c.monsters) cin >> m;
            c.determine_hardest();
        }
        sort(caves.begin(), caves.end());
        int res = 0, power = 0;
        for (auto c : caves) {
            for (auto m : c.monsters) {
                int a = max(m - power + 1, 0);
                res += a, power += a + 1;
            }
        }
        cout << res << '\n';
    }
    return 0;
}