#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> d;

struct Node {
    int r, d;  // res for a tree, height of a tree
    bool operator<(const Node x) const {
        if (r != x.r) return r > x.r;
        return d < x.d;
    }
};

struct MonitonicQueue {
    int pop_done = 0, push_done = 0;
    deque<pair<Node,int>> q;
    void push(Node x) {
        while (!q.empty() && q.back().first < x)
            q.pop_back();
        q.push_back({x, push_done});
        push_done++;
    }
    void pop() {
        while (!q.empty() && q.front().second <= pop_done)
            q.pop_front();
        pop_done++;
    }
    Node max() {
        return q.front().first;
    }
};

int solve(int k) {
    vector<int> res(n, 0);
    MonitonicQueue q;
    int i = 1;
    for (; i <= k; i++) {
        if (d[i] >= d[0])
            res[i]++;
        q.push(Node{res[i], d[i]});
    }
    for (; i < n; i++) {
        res[i] = q.max().r;
        if (d[i] >= q.max().d)
            res[i]++;
        q.pop();
        q.push(Node{res[i], d[i]});
    }
    return res[n - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d.resize(n);
    for (auto& x : d) cin >> x;
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << solve(k) << '\n';
    }
    return 0;
}