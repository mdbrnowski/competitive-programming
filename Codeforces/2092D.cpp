#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        map<char, int> num = {{'L', 0}, {'I', 0}, {'T', 0}};
        for (auto c : s)
            num[c]++;

        vi res;

        while (num['L'] != num['I'] || num['I'] != num['T']) {
            map<char, vi> pos = {{'L', {}}, {'I', {}}, {'T', {}}};

            for (int i = 0; i < sz(s) - 1; i++) {
                if ((s[i] == 'L' && s[i + 1] == 'I') || (s[i] == 'I' && s[i + 1] == 'L'))
                    pos['T'].push_back(i);
                if ((s[i] == 'L' && s[i + 1] == 'T') || (s[i] == 'T' && s[i + 1] == 'L'))
                    pos['I'].push_back(i);
                if ((s[i] == 'I' && s[i + 1] == 'T') || (s[i] == 'T' && s[i + 1] == 'I'))
                    pos['L'].push_back(i);
            }

            if (sz(res) > 2 * n)
                break;

            vector<char> possibles;
            for (auto x : "LIT") {
                if (sz(pos[x]) > 0)
                    possibles.push_back(x);
            }

            if (sz(possibles) == 0)
                break;

            char c = *min_element(possibles.begin(), possibles.end(), [&num](char a, char b) {
                return num[a] < num[b];
            });

            int p = pos[c].back();
            pos[c].pop_back();
            res.push_back(p);
            s = s.substr(0, p + 1) + c + s.substr(p + 1);

            pos['L' ^ 'I' ^ 'T' ^ s[p] ^ c].push_back(p);
            pos['L' ^ 'I' ^ 'T' ^ s[p + 1] ^ c].push_back(p + 1);

            num[c]++;
        }

        if (num['L'] != num['I'] || num['I'] != num['T']) {
            cout << "-1\n";
        } else {
            cout << sz(res) << '\n';
            for (auto x : res)
                cout << x + 1 << '\n';
        }
    }
}
