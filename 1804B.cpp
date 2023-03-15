#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

int a[maxn];

void solve() {
    int n, k, d, w; cin >> n >> k >> d >> w;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int cur = 1; cur <= n; ) {
        int i = cur + 1;
        for (; i <= min(cur + k - 1, n); i++) {
            if (a[i] - a[cur] - w > d) break;
        }
        ans++;
        cur = i;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}