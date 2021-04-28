#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int remain = 0;

void dfs(int x, int y, int value) {
    if (remain == 0) return;
    board[y][x] = value, remain--;
    if (x-1 >= 0 && board[y][x-1] == 0) dfs(x-1, y, value);
    if (y+1 < board.size()) dfs(x, y+1, value);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    board.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        cin >> board[i][i];
    for (int i = 0; i < n; i++) {
        remain = board[i][i];
        dfs(i, i, board[i][i]);
    }
    for (auto y : board) {
        for (auto x : y)
            if (x > 0) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}