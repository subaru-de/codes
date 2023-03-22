#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
pair<int, int> a[maxn];

void solve() {
    int n; cin >> n;
    multiset<int> st1;
    set<int> st2;
    st1.clear(), st2.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        st1.insert(a[i].second);
    }
    sort(a + 1, a + n + 1);
    int ans = 0x7fffffff;
    for (int i = n; i; i--) {
        if (!st2.empty()) ans = min(ans, abs(a[i].first - *st2.rbegin()));
        st2.insert(a[i].first);
        multiset<int>::iterator pos = st1.find(a[i].first);
        st1.erase(pos);
        pos = st1.lower_bound(a[i].first);
        if (pos != st1.end() && (st2.empty() || *pos > *st2.rbegin())) ans = min(ans, abs(a[i].first - *pos));
        if (pos != st1.begin()) {
            pos--;
            if (st2.empty() || *pos > *st2.rbegin()) ans = min(ans, abs(a[i].first - *pos));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; for (; T; T--) solve();
    return 0;
}
