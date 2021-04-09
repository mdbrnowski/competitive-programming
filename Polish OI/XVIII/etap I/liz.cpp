#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, firstW = -1, lastW = -1;
	string s;
	cin >> n >> m >> s;
    int totalsum = n + count(s.begin(), s.end(), 'T');
    vector<pair<int,int>> res(totalsum+1, {0,0});
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			lastW = i;
			if (firstW == -1) firstW = i;
		}
	}

	int x = 0, z = n-1, sum = totalsum;
	while (sum > 0) {
		res[sum] = {x+1,z+1};
		if (s[x] == 'T') x++;
		else if (s[z] == 'T') z--;
		else x++, z--;
		sum -= 2;
	}
	if (firstW <= n-1-lastW) {
		x = firstW+1;
		z = n-1;
		sum = totalsum - 2*firstW - 1;
	} else {
		x = 0;
		z = lastW-1;
		sum = totalsum - 2*(n-1-lastW) - 1;
	}
	while (sum > 0){
		res[sum] = {x+1,z+1};
		if (s[x] == 'T') x++;
		else if (s[z] == 'T') z--;
		else x++, z--;
		sum -= 2;
	}

    while (m--) {
		cin >> k;
		if (k >= res.size() || res[k].first == 0) cout << "NIE\n";
		else cout << res[k].first << ' ' << res[k].second << '\n';
	}
    return 0;
}