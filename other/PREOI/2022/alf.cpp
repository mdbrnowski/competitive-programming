#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    cin >> N >> L;
    vector<vector<int>> name(N, vector<int>(L));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            char c;
            cin >> c;
            name[i][j] = c - 'a';
        }
    }
    int n = N - 1;
    vector<vector<int>> vec(n, vector<int>(L, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < L; j++) {
            if (name[i][j] < name[i+1][j])
                vec[i][j] = 1;
            if (name[i][j] > name[i+1][j])
                vec[i][j] = 2;
        }
    }
    // in every row there must be a 1 and no 2 should be before the first 1

    pair<int,int> res = {0, L - 1};

    int a = 0, b = -1;
    vector<int> ones(n, 0);
    int without_ones = n;
    while (a < L) {
        bool ok = true;
        while (without_ones > 0 && b + 1 < L) {
            b++;
            for (int i = 0; i < n; i++) {
                if (vec[i][b] == 1) {
                    if (ones[i] == 0)
                        without_ones--;
                    ones[i]++;
                }
                if (vec[i][b] == 2) {  // propagate to previous 0s
                    for (int j = b; j >= a; j--)
                        if (vec[i][j] == 0) vec[i][j] = 2;
                        else break;
                }
            }

            for (int i = 0; i < n; i++)
                if (vec[i][a] == 2) {ok = false; break;}
            if (!ok) break;
        }
        for (int i = 0; i < n; i++)
            if (vec[i][a] == 2) {ok = false; break;}

        if (ok && without_ones == 0 && b - a < res.second - res.first)
            res = {a, b};

        for (int i = 0; i < n; i++) {
            if (vec[i][a] == 1) {
                ones[i]--;
                if (ones[i] == 0)
                    without_ones++;
            }
        }
        a++;
    }
    cout << res.first + 1 << ' ' << res.second + 1 << '\n';
    return 0;
}