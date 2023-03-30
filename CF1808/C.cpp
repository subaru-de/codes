#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 33;
int num1[maxn], r1, num2[maxn], r2, mn, mx, *top_;

ll calc(int pos, bool flag) {
    if (!pos) return 1;
    ll ret = 0;
    if (!flag) {
        for (int i = mn; i <= min(mx, top_[pos]); i++) {
            if (i == top_[pos]) ret += calc(pos - 1, 0);
            else ret += calc(pos - 1, 1);
        }
    }
    else {
        for (int i = mn; i <= min(mx, top_[pos]); i++) {
            ret += calc(pos - 1, 1);
        }
    }
    return ret;
}

void solve() {
    int L, R; cin >> L >> R;
    L--;
    for (; L; L /= 10) num1[++r1] = L % 10;
    for (; R; R /= 10) num2[++r2] = R % 10;
    for (int i = 0; i < 10; i++) {
        bool flag = 0;
        for (mn = 0; (mx = mn + i) < 10; mn++) {
            top_ = num2;
            ll tmp = calc(r2, 0);
            top_ = num1;
            tmp -= calc(r1, 0);
            if (tmp) {
                flag = 1;
                cout << tmp << '\n';
            }
        }
        if (flag) {
            cout << i << '\n';
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}
