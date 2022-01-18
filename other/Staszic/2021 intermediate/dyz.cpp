#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1e6+3;

void sieve(vector<int>& prime) {
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i < M; i++) {
        if (prime[i] == 0) continue;
        for (int j = i * i; j < M; j += i)
            prime[j] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> prime(M, 1);
    sieve(prime);
    partial_sum(prime.begin(), prime.end(), prime.begin());
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << prime[b] - prime[a-1] << '\n';
    }
    return 0;
}