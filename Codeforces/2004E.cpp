#include <bits/stdc++.h>
using namespace std;

vector<int> compute_sprague_grundy() {
    int m = 1e7 + 3;
    vector<int> sg(m, -1);
    sg[0] = 0;
    sg[1] = 1;
    int p = 2;
    for (int i = 2; i < m; i += 2)
        sg[i] = 0;
    for (int i = 3; i < m; i += 2) {
        if (sg[i] == -1) {
            sg[i] = p++;
            if (i < 1e4)
                for (int j = i * i; j < m; j += i)
                    if (sg[j] == -1)
                        sg[j] = sg[i];
        }
    }
    return sg;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> sg = compute_sprague_grundy();
    int t;
    cin >> t;
    while (t--) {
        int n, res = 0;
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            res ^= sg[x];
        }
        cout << (res ? "Alice" : "Bob") << '\n';
    }
    return 0;
}
