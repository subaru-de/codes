#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;

void solve() {
    int n, x, p; cin >> n >> x >> p;
    ll de = (n - x) % n;
    int tmp = 0;
    for (int i = 1; i <= p; i++) {
        tmp = (tmp + i) % n;
        if (tmp == de) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}