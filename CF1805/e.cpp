#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5 + 5;
int n, cnt, head[maxn], a[maxn];
struct Edge { int id, v, nxt; };
void add_edge(int id, int u, int v) {
    ed[++cnt] = {id, v, head[u]};
    head[u] = cnt;
}
int val[maxn];
map<int, vector<int> > mp;
set<int> st;

int fa[maxn][21], fr[maxn];

void dfs(int u) {
    dep[u] = dep[fa[u][0]] + 1;
    for (int i = head[u], v; i; i = ed[i].nxt) {
        v = ed[i].v;
        if (v == fa[u][0]) continue;
        fa[v][0] = u; fr[v] = i.id;
        dfs(v, u);
    }
}

void dfs2(int u) {
    dep[u] = dep[fa[u][0]] + 1;
    for (int i = 1; ; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        if (!fa[u][i]) break;
    }
    for (int i = head[u], v; i; i = ed[i].nxt) {
        v = ed[i].v;
        if (v == fa[u]) continue;
        fa[v] = u; fr[v] = i.id;
        dfs2(v, u);
    }
}

void color(int u, int v) {
    
}

void solve() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        add_edge(i, u, v); add_edge(i, v, u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!mp.count(a[i]) mp.insert({a[i], vector<int>()});
        mp[a[i]].push_back(i);
    }
    vector<int> ans; ans.resize(n, 0);
    dfs(1);
    int ret = 0; bool flag = 0;
    auto it = mp.rbegin();
    for (; it != mp.rend(); it++) {
        if (it -> second.size() > 2) {
            ret = it -> first;
            flag = 1;
            break;
        }
        else if (it -> second.size() == 2) {
            ret = it -> first;
            flag = 0;
            break;
        }
    }
    if (flag) {
        for (int i = 1; i < n; i++) cout << ret << ' ';
        cout << '\n';
        return;
    }
    color(it -> second[0], it -> second[1]);
    for (; it != mp.rend(); it++) {
        if (it -> second.size() > 2) {

        }
    }
    for (int i = 1; i < n; i++) {
        if (ans[i]) cout << ans[i] << ' ';
        else cout << ret << ' ';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}
