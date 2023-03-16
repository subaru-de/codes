#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

int n, c;
int a[maxn];

void solve() {
    cin >> n >> c;
    vector<pair<int, int> > vec;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vec.push_back({a[i] + min(i, n + 1 - i), i});
    }
    sort(vec.begin(), vec.end());
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}
