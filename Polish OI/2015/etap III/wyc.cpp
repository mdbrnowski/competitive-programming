#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, n) for (int i = 0; i < n; i++)

const ll INF = 1.6e18;

inline ll times(ll a, ll b) {
    if (a == 0)
        return 0;
    if (b > INF/a)
        return INF;
    return a * b;
}

struct Matrix {
    int n;
    vector<vector<ll>> A;
    Matrix(int _n) : n(_n), A(n, vector<ll>(n, 0)) {}
    auto& operator[](int i) {return A[i];}
    Matrix operator*(Matrix B) {
        Matrix res(n);
        REP(j, n) REP(i, n) REP(k, n) {
            res[i][k] += times(A[i][j], B[j][k]);
            res[i][k] = min(res[i][k], INF);
        }
        return res;
    }
};

ll count_paths(Matrix m) {
    int n = m.n - 1;
    ll res = 0;
    for (int i = 0; i < n; i += 3) {
        res += m[n][i];
        res = min(res, INF);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; ll k;
    cin >> n >> m >> k;
    Matrix graph(3*n+1);
    graph[3*n][3*n] = 1;
    REP(i, n) {
        graph[3*n][3*i] = 1;
        graph[3*i][3*i+1] = 1;
        graph[3*i+1][3*i+2] = 1;
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[3*a + c-1][3*b]++;
    }

    k += n;  // paths of length 0
    vector<Matrix> power;
    power.push_back(graph);
    int ind = 0;
    while ((1LL << ind) <= (1.5 * k) && count_paths(power[ind]) < k) {
        power.push_back(power[ind] * power[ind]);
        ind++;
    }
    ll res = 0;
    if (count_paths(power[ind]) >= k) {
        Matrix g = graph;
        for (int i = ind; i >= 0; i--) {
            if (count_paths(g * power[i]) < k) {
                g = g * power[i];
                res |= (1LL << i);
            }
        }
        res++;
    } else res = -1;
    cout << res << '\n';
    return 0;
}
