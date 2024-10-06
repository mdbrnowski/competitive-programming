#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int max_p) {
    vector<bool> is_prime(max_p, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < max_p; i++)
        if (is_prime[i])
            for (int j = i * i; j < max_p; j += i)
                is_prime[j] = false;
    return is_prime;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    vector<int> n(T);
    for (auto& x : n)
        cin >> x;
    int max_n = *max_element(n.begin(), n.end());
    vector<bool> is_prime = sieve(max_n + 1);
    vector<int> res(max_n + 1, 0);
    res[5] = 2;
    set<int> could_be = {5};
    for (int x = 6; x <= max_n; x++) {
        res[x] = res[x - 1];
        if (!is_prime[x])
            continue;
        if (could_be.count(x - 2)) {
            could_be.erase(x - 2);
            res[x]++;
        }
        could_be.insert(x);
    }
    for (int t = 0; t < T; t++)
        cout << "Case #" << t + 1 << ": " << res[n[t]] << "\n";
    return 0;
}
