#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi res, nums;
    int sum = 0, x = 1;
    while (sum < n) {
        nums.push_back(x);
        sum += __builtin_popcount(x);
        x++;
    }
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (sum - __builtin_popcount(nums[i]) >= n)
            sum -= __builtin_popcount(nums[i]);
        else
            res.push_back(nums[i]);
    }
    cout << res.size() << '\n';
    for (auto r : res) cout << r << ' ';
    cout << '\n';
    return 0;
}
