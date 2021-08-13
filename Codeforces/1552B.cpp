#include <bits/stdc++.h>
using namespace std;

struct athlete {
    int rank[5];
    operator<(athlete x) {
        int res = 0;
        for (int j = 0; j < 5; j++)
            if (x.rank[j] < rank[j]) res++;
        return res >= 3;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<athlete> a(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                cin >> a[i].rank[j];
        int gold = 0;
        for (int i = 1; i < n; i++)
            if (a[gold] < a[i]) gold = i;
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (a[gold] < a[i]) ok = false;
        cout << (ok ? gold + 1 : -1) << '\n';
    }
    return 0;
}