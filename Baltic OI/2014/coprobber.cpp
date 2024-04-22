#include "coprobber.h"
#include <bits/stdc++.h>
using namespace std;

int next_move[MAX_N][MAX_N];
int left_to_win_C[MAX_N][MAX_N];
int left_to_win_R[MAX_N][MAX_N];

int start(int N, bool A[MAX_N][MAX_N]) {
    for (int r = 0; r < N; r++) {
        int degree = count(A[r], A[r] + N, true);
        for (int c = 0; c < N; c++) {
            if (c == r) continue;
            left_to_win_C[c][r] = 1;
            left_to_win_R[c][r] = degree;
        }
    }

    queue<tuple<int,int,char>> q;
    for (int i = 0; i < N; i++)
        q.push({i, i, 'C'}),
        q.push({i, i, 'R'});

    int winnable = 0;
    while (q.size()) {
        auto [c, r, who] = q.front(); q.pop();
        winnable++;
        if (who == 'C') {
            for (int i = 0; i < N; i++) {
                if (A[r][i] && left_to_win_R[c][i]) {
                    left_to_win_R[c][i]--;
                    if (left_to_win_R[c][i] == 0)
                        q.push({c, i, 'R'});
                }
            }
        } else if (who == 'R') {
            for (int i = 0; i < N; i++) {
                if ((A[c][i] || c == i) && left_to_win_C[i][r]) {
                    left_to_win_C[i][r] = 0;
                    q.push({i, r, 'C'});
                    next_move[i][r] = c;
                }
            }
        }
    }
    return (winnable == 2 * N * N) ? 0 : -1;
}

int C = 0;

int nextMove(int R) {
    return C = next_move[C][R];
}
