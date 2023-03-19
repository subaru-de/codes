#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 205;
int n, m;
int a[maxn][maxn];

void solve() {
    cin >> n >> m;
    cout << n * m << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        } cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= 200; i += 2) {
        for (int j = 1; j <= 200; j += 2) {
            int tmp = i * 200 + j;
            a[i][j] = tmp << 2, a[i][j + 1] = tmp << 2 | 1;
            a[i + 1][j] = tmp << 2 | 2, a[i + 1][j + 1] = tmp << 2 | 3;
        }
    }
    int T; cin >> T;
    for (int i = 1; i <= T; i++) solve();
    return 0;
}
