#include "cgdzlib.h"
#include <bits/stdc++.h>
using namespace std;

pair<int,int> divide(vector<int>& p, int power) {
    if (p.size() == 2)
        return {p[0], p[1]};
    int x = *p.begin();
    vector<int> a, b;
    for (auto y : p)
        if (f(x, y, power))
            a.push_back(y);
        else
            b.push_back(y);

    power *= 2;
    vector<int> mm;  // 4 (or 2) maximas or minimas from a and b
    if (a.size() > 1) {
        auto [m1, m2] = divide(a, power);
        mm.push_back(m1);
        mm.push_back(m2);
    }
    if (b.size() > 1) {
        auto [m3, m4] = divide(b, power);
        mm.push_back(m3);
        mm.push_back(m4);
    }

    for (auto i : mm)
        for (auto j : mm)
            if (i != j && f(i, j, power/4 * (p.size() - 1)))
                return {i, j};
}

int main() {
    int n = inicjuj();
    if (n == 1)
        odpowiedz(1);
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    auto [i, j] = divide(p, 2);
    int res = g(i, j) ? j : i;
    odpowiedz(res);
    return 0;
}