#include <bits/stdc++.h>
#define maxn 200005
#define base 1000003
#define mod 998244353
#define ll long long
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
    ull h = H[0];
    h = h - num[pos] * hpow[pos];
    h = h + (num[pos] + 1) * hpow[pos];
    ll f = F[0];
    f = (f - num[pos] * fpow[pos] % mod + mod) % mod;
    f = (f + (num[pos] + 1) * fpow[pos]) % mod;
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
    ans1 = ans1 * base + 1;
    ans2 = (ans2 * base + 1) % mod;
    T1[u] = ans1, T2[u] = ans2;
}

vector<int> ans;
set<pair<ull, ll> > st;

void calc(int u, int fa) {
    if (st.find({T1[u], T2[u]}) != st.end()) ans.push_back(u);
    for (int i = head[u], v; i; i = ed[i].nxt) {
        v = ed[i].v;
        if (v == fa) continue;
        ull h = T1[u]; ll f = T2[u];
        h = h - T1[v] * base;
        f = (f - T2[v] * base % mod + mod) % mod;
        T1[v] = T1[v] + h * base;
        T2[v] = (T2[v] + f * base) % mod;
        calc(v, u);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) num[i] = 0;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        num[a[i]]++;
    }
    H[0] = F[0] = num[0];
    for (int i = n - 1; ~i; i--) {
        H[i] = H[i + 1] * base + num[i];
        F[i] = (F[i + 1] * base + num[i]) % mod;
    }
    st.clear();
    for (int i = 0; i < n; i++) {
        st.insert(modify(i));
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 1);
    calc(1, 1);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto &it : ans) cout << it << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    hpow[0] = 1; fpow[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        hpow[i] = hpow[i - 1] * base;
        fpow[i] = fpow[i - 1] * base % mod;
    }
    int T = 1; // cin >> T;
    for (; T; T--) solve();
    return 0;
}