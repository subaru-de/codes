#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;

int n;
vector<pair<ll, int> > G[maxn];
ll H[maxn];
ll num[1000005];

void dfs(int u, int fa) {
    for (int i = 0, v; i < G[u].size(); i++) {
        v = G[u][i].second;
        if (v == fa) continue;
        dfs(v, u);
        G[u][i].first = H[v];
    }
    H[u] = num[G[u].size() % 1000000];
    for (int i = 0, v; i < G[u].size(); i++) {
        if (v == fa) continue;
        H[u] ^= num[H[v] % 1000001];
        H[u] ^= num[H[v] % 1000003];
        H[u] ^= num[H[v] % 1000005];
    }
}

bool check(int u, int fa) {
    map<ll, int> mp; mp.clear();
    for (int i = 0, v, val; i < G[u].size(); i++) {
        v = G[u][i].second; val = G[u][i].first;
        if (v == fa) continue;
        auto it = mp.find(val);
        if (it == mp.end()) {
            mp.insert({val, v});
        }
        else mp.erase(val);
    }
    int tmp = mp.size();
    if (!tmp) return 1;
    else if (tmp > 1) return 0;
    else return check(mp.begin() -> second, u);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back({0, v});
        G[v].push_back({0, u});
    }
    dfs(1, 1);
    puts("qwq");
    if (check(1, 1)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    srand(unsigned(time(0)));
    for (int i = 0; i < 1000005; i++) {
        num[i] = rand() | rand() << 15 | rand() << 30 | rand() << 45ll;
    }
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}
