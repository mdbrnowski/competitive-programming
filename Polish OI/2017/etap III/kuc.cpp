#include "ckuclib.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int EMAX = 20;
constexpr ll INF = 1e18;

struct Solve {
    int n = 1;
    Solve *sol = nullptr;
    vector<vector<ll>> res;
    Solve() : res({vector<ll>(EMAX + 1, 0), vector<ll>(EMAX + 1, jedno(1))}) {}
    ~Solve() {delete sol;}
    const vector<ll> &operator()(int i) {
        if (i == n)
            return res[1];
        if (i == n-1)
            return res[0];
        if (!sol)
            sol = new Solve;
        while (n < i) {
            n++;
            vector<ll> temp_res(EMAX + 1);
            auto res_pol = (*sol)((n + 1) / 2);
            for (int e = 0; e <= EMAX; e++) {
                temp_res[e] = min({
                    res[1][min(e+1, EMAX)] + jedno(n),
                    res[0][e] + dwa(n),
                    (e > 0 ? res_pol[e-1] + polowa(n) : INF)
                });
            }
            res[0] = res[1];
            res[1] = temp_res;
        }
        return res[1];
    }
};

int main() {
    int n = dajn();
    int e = daje();
    auto solve = Solve();
    odpowiedz(solve(n)[min(e, EMAX)]);
    return 0;
}