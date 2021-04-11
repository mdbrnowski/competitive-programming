#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> ast;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                if (c == '*') ast.push_back({i, j});
            }
        }
        if (ast[0].first != ast[1].first && ast[0].second != ast[1].second) {
            ast.push_back({ast[0].first, ast[1].second});
            ast.push_back({ast[1].first, ast[0].second});
        } else if (ast[0].first == ast[1].first) {
            int s = (ast[0].first == 0);
            ast.push_back({s, ast[1].second});
            ast.push_back({s, ast[0].second});
        } else {
            int s = (ast[0].second == 0);
            ast.push_back({ast[0].first, s});
            ast.push_back({ast[1].first, s});
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (count(ast.begin(), ast.end(), make_pair(i,j)))
                    cout << '*';
                else cout << '.';
            }
            cout << '\n';
        }
    }
    return 0;
}