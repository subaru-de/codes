#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;
char a[maxn][maxn];
int mp[maxn][maxn];
int s[maxn][maxn];

int main() {
    int n, m; cin >> n >> m;
    memset(mp, 0, sizeof(mp));
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') mp[i][j] = 0;
            else if (a[i][j] == '*') mp[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    s[i][j] += mp[k][l];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j]) cout << '*';
            else if (!s[i][j]) cout << '.';
            else cout << s[i][j];
        } cout << '\n';
    }
    return 0;
}
