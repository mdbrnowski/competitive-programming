#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    string grav;
    if (k) cin >> grav;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            mat[i][j] = s[j];
    }

    for (auto g : grav) {
        if (g == 'D') {
            for (int j = 0; j < m; j++) {
                int free = -1;
                for (int i = n - 1; i >= 0; i--) {
                    if (mat[i][j] == '.' && free == -1)
                        free = i;
                    if (mat[i][j] != '.' && free > -1) {
                        swap(mat[i][j], mat[free][j]);
                        while (free > -1 && mat[free][j] != '.')
                            free--;
                    }
                }
            }
        }
        if (g == 'U') {
            for (int j = 0; j < m; j++) {
                int free = n;
                for (int i = 0; i < n; i++) {
                    if (mat[i][j] == '.' && free == n)
                        free = i;
                    if (mat[i][j] != '.' && free < n) {
                        swap(mat[i][j], mat[free][j]);
                        while (free < n && mat[free][j] != '.')
                            free++;
                    }
                }
            }
        }
        if (g == 'R') {
            for (int i = 0; i < n; i++) {
                int free = -1;
                for (int j = m - 1; j >= 0; j--) {
                    if (mat[i][j] == '.' && free == -1)
                        free = j;
                    if (mat[i][j] != '.' && free > -1) {
                        swap(mat[i][j], mat[i][free]);
                        while (free > -1 && mat[i][free] != '.')
                            free--;
                    }
                }
            }
        }
        if (g == 'L') {
            for (int i = 0; i < n; i++) {
                int free = m;
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == '.' && free == m)
                        free = j;
                    if (mat[i][j] != '.' && free < m) {
                        swap(mat[i][j], mat[i][free]);
                        while (free < m && mat[i][free] != '.')
                            free++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << mat[i][j];
        cout << '\n';
    }
    return 0;
}
