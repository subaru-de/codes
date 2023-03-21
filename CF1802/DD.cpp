#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;
int n;
struct Node {
    int w, p;
    bool operator < (const Node& rhs) const {
        return w > rhs.w;
    }
} a[maxn], b[maxn];
set<int> st1, st2;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> b[i].w;
        a[i].p = b[i].p = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1, j = 1; i <= n && j <= n; ) {
        if (a[i].p != b[j].p) {
            ans = min(ans, abs(a[i].w - b[j].w));
            if (a[i].w == b[j].w) break;
        }
        if (a[i].w > b[j].w && st2.find(a[i].p) == st2.end()) i++;
        else if (a[i].w < b[j].w && st1.find(a[i].p) == st1.end()) j++;
        else if (a[i].p == b[j].p) {
            if (a[i + 1].w > a[j + 1].w) i++;
            else j++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}
