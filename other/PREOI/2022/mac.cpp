#include <bits/stdc++.h>
using namespace std;

struct MonitonicQueue {
    int pop_done = 0, push_done = 0;
    deque<pair<int,int>> q;
    void push(int x) {
        while (!q.empty() && q.back().first > x)
            q.pop_back();
        q.push_back({x, push_done});
        push_done++;
    }
    void pop() {
        while (!q.empty() && q.front().second <= pop_done)
            q.pop_front();
        pop_done++;
    }
    int min() {
        return q.front().first;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<vector<int>> h(n, vector<int>(m));
    for (auto& row : h)
        for (auto& x : row)
            cin >> x;
    vector<vector<int>> row_res(n, vector<int>(m - l + 1)),
                        res(n - k + 1, vector<int>(m - l + 1));
    for (int i = 0; i < n; i++) {
        MonitonicQueue q;
        for (int j = 0; j < l - 1; j++)
            q.push(h[i][j]);
        for (int j = 0; j < m - l + 1; j++) {
            q.push(h[i][j + l - 1]);
            row_res[i][j] = q.min();
            q.pop();
        }
    }
    for (int j = 0; j < m - l + 1; j++) {
        MonitonicQueue q;
        for (int i = 0; i < k - 1; i++)
            q.push(row_res[i][j]);
        for (int i = 0; i < n - k + 1; i++) {
            q.push(row_res[i + k - 1][j]);
            res[i][j] = q.min();
            q.pop();
        }
    }
    for (auto row : res) {
        for (auto x : row)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}