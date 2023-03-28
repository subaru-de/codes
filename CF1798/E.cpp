#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int n, a[maxn];
int f[maxn], g[maxn];
int mxf[maxn], mxg[maxn];
// f: without modify; g: with modify

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n + 1; i++) f[i] = g[i] = mxf[i] = mxg[i] = 0;
    for (int i = n; i; i--) {
        if (i + a[i] == n) f[i] = 1;
        else if (i + a[i] < n && f[i + a[i] + 1]) f[i] = f[i + a[i] + 1] + 1;
        g[i] = mxf[i + 1] + 1;
        if (i + a[i] < n) g[i] = max(g[i], g[i + a[i] + 1] + 1);
        mxf[i] = max(mxf[i - 1], f[i]);
    }
    for (int i = 1; i < n; i++) {
        if (f[i + 1] == a[i]) cout << 0 << ' ';
        else if (f[i + 1] || g[i + 1] >= a[i]) cout << 1 << ' ';
        else cout << 2 << ' ';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}
