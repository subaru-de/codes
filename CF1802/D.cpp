#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
int n;
struct Node {
    int w, p;
    bool operator < (const Node& rhs) const {
        return w < rhs.w;
    }
} a[maxn], b[maxn];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> b[i].w;
        a[i].p = b[i].p = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(b + 1, b + n + 1, a[i]) - b;
        if (b[pos].p != a[i].p) ans = min(ans, abs(a[i].w - b[pos].w));
        else if (pos + 1 <= n) ans = min(ans, abs(a[i].w - b[pos + 1].w));
        pos--;
        if (!pos) continue;
        if (b[pos].p != a[i].p) ans = min(ans, abs(a[i].w - b[pos].w));
        else if (pos - 1 > 0) ans = min(ans, abs(a[i].w - b[pos - 1].w));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}
