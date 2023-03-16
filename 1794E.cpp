#include <bits/stdc++.h>
#define base 1000003
#define mod 998244353
#define ull unsigned long long
using namespace std;

int n, a[maxn];
int cnt, head[maxn];
int num[maxn];
ull H[maxn];
ll F[maxn];
ull hpow[maxn];
ll fpow[maxn];
struct Edge {
    int v, nxt;
} ed[maxn << 1];
void add_edge(int u, int v) {
    ed[++cnt] = {v, head[u]};
    head[u] = cnt;
}

pair<ull, ll> modify(int pos) {
    int tmp = n - 1 - pos;
    ull h = H[n - 1];
    h = h - num[pos] * hpow[tmp];
    h = h + (num[pos] + 1) * hpow[tmp];
    ll f = F[n - 1];
    f = (f - num[pos] * fpow[tmp] % mod + mod) % mod;
    f = (f + (num[pos] + 1) * fpow[tmp]) % mod;
    return {h, f};
}

ull T1[maxn];
ll T2[maxn];

void dfs(int u, int fa) {
    ull ans1 = 0, ans2 = 0;
    for (int i = head[u], v; i; i = ed[i].nxt) {
        v = ed[i].v;
        if (v == fa) continue;
        dfs(v, u);
        ans1 += T1[v];
        ans2 = (ans2 + T2[v]) % mod;
    }
    ans1 = ans1 * base + 
}

void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) num[i] = 0;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        num[a[i]]++;
    }
    H[0] = F[0] = num[0];
    for (int i = 1; i < n; i++) {
        H[i] = H[i - 1] * base + num[i];
        F[i] = (F[i - 1] * base + num[i]) % mod;
    }
    set<pair<ull, ll> > st; st.clear();
    for (int i = 0; i < n; i++) {
        st.insert(modify(i));
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    hpow[0] = 0; fpow[0] = 0;
    for (int i = 1; i <= 200000; i++) {
        hpow[i] = hpow[i - 1] * base;
        fpow[i] = fpow[i - 1] * base % mod;
    }
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}
