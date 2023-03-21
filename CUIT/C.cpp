#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = 0; cin >> tmp;
        if (tmp < 100) ans += 1;
        else if (tmp >= 100 && tmp < 200) ans += 2;
        else if (tmp >= 200 && tmp < 300) ans += 5;
        else if (tmp >= 300 && tmp < 400) ans += 10;
        else if (tmp >= 400) ans += 15;
    }
    cout << ans << '\n';
    return 0;
}
