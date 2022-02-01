#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int MOD = 1e9+7;
int NMAX;

vector<ll> res, fact, inv, r_fact;

void calc_factorial() {
    fact[0] = 1;
    for (int i = 1; i < NMAX; i++)
        fact[i] = fact[i-1] * i % MOD;
}

void calc_r_factorial() {
    inv[1] = 1;
    for(int i = 2; i < NMAX; i++)
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;

    r_fact[0] = 1;
    for (int i = 1; i < NMAX; i++) {
        r_fact[i] = r_fact[i-1] * inv[i] % MOD;
    }
}

ll f(vector<int>& a, ll ones) {  // number of permutations
    ll p = fact[a.size() + ones];
    p = p * r_fact[ones] % MOD;
    int k = 1;
    for (int i = 1; i < (int) a.size(); i++) {
        if (a[i] == a[i-1]) k++;
        else p = p * r_fact[k] % MOD, k = 1;
    }
    p = p * r_fact[k] % MOD;
    return p;
}

void calc(vector<int>& a, ll& num, ll& prod, ll& sum) {
    int mini = (a.empty() ? 2 : a.back());
    for (int i = mini; i < NMAX; i++) {
        a.push_back(i);
        num++, prod *= i, sum += i;
        if (num + (prod - sum) < NMAX) {
            res[num + (prod - sum)] += f(a, prod - sum);
            res[num + (prod - sum)] %= MOD;
            calc(a, num, prod, sum);
            a.pop_back();
            num--, prod /= i, sum -= i;
        } else {
            a.pop_back();
            num--, prod /= i, sum -= i;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    vector<int> cases(T);
    for (auto& n : cases) cin >> n;
    NMAX = *max_element(cases.begin(), cases.end()) + 3;
    res.resize(NMAX, 0), fact.resize(NMAX),
    inv.resize(NMAX), r_fact.resize(NMAX);

    calc_factorial(), calc_r_factorial();
    vector<int> a;
    ll num = 0, prod = 1, sum = 0;
    calc(a, num, prod, sum);

    for (auto n : cases)
        cout << res[n] << '\n';
    return 0;
}