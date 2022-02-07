#include <bits/stdc++.h>
using namespace std;

void complete(vector<int>& towns, vector<int>& order) {
    int i = 0;
    for (auto x : order) {
        while (towns[i]) i++;
        towns[i] = towns[i + x] = x;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    if (n % 4 > 1) {
        cout << "NIE\n";
        return 0;
    } else cout << "TAK\n";

    vector<int> order;
    vector<int> towns(2 * n, 0);
    if (n == 1) order = {1};
    else if (n == 5) order = {3, 4, 5, 2, 1};
    else if (n % 4 == 0) {
        for (int i = n; i >= 2; i -= 2)
            order.push_back(i);
        order.push_back(n - 1);
        order.push_back(n / 2 - 1);
        for (int i = n - 3; i >= 1; i -= 2)
            if (i != n / 2 - 1)
                order.push_back(i);
    }
    else if (n % 4 == 1) {
        for (int i = n - 1; i >= 2; i -= 2)
            order.push_back(i);
        order.push_back(n);
        order.push_back(n / 2 - 1);
        for (int i = n - 2; i >= 1; i -= 2)
            if (i != n / 2 - 1)
                order.push_back(i);
    }
    complete(towns, order);
    for (auto x : towns)
        cout << x << ' ';
    cout << '\n';
    return 0;
}