#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;

int n, c;
int a[maxn], pos[maxn];
ll s[maxn];

void solve() {
    cin >> n >> c;
    vector<pair<int, int> > vec;
    vec.resize(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vec[i] = {a[i] + min(i, n + 1 - i), i};
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= n; i++) {
        pos[vec[i].second] = i;
    }
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + vec[i].first;
    }
    int ans = 0;
    for (int i = 1, res; i <= n; i++) {
        res = c - a[i] - i;
        if (res < 0) continue;
        int tp = upper_bound(s + 1, s + n + 1, res) - s - 1;
        if (tp >= pos[i]) { // sp case
            res += a[i] + min(i, n + 1 - i);
            tp = upper_bound(s + 1, s + n + 1, res) - s - 1;
            ans = max(ans, tp);
        }
        else ans = max(ans, tp + 1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}