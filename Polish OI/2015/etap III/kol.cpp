#include <bits/stdc++.h>
#include "ckollib.h"
using namespace std;

struct Solver {
    vector<int> v;
    Solver() : v(31, 0) {}
    void operator+=(int x) {
        for (int i = 0; i < 31; i++)
            if (x & (1 << i))
                v[i]++;
    }
    void operator%=(int m) {
        for (int i = 0; i < 31; i++)
            v[i] %= m;
    }
    int get_res() {
        int res = 0;
        for (int i = 0; i < 31; i++)
            if (v[i])
                res += (1 << i);
        return res;
    }
};

int main() {
    int k1 = karta(), k2;
    Solver S;
    S += k1;
    map<int,int> m;
    m[k1] = 1;

    int k;
    while ((k = karta()) == k1) {
        S += k;
        m[k]++;
    }
    k2 = k;
    if (k2 == 0)
        odpowiedz(k1);
    S += k2, m[k2] = 1;

    while ((k = karta()) > 0) {
        S += k;
        if (k == k1 || k == k2)
            m[k]++;
    }

    S %= max(m[k1], m[k2]);

    odpowiedz(S.get_res());
    return 0;
}