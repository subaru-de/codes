#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, a[maxn];
int cnt, head[maxn];
struct Edge { int id, v, nxt; } ed[maxn << 1];
void add_edge(int id, int u, int v) { ed[++cnt] = {id, v, head[u]}; head[u] = cnt; }
map<int, set<int> > mp;
int rt, ans[maxn];
vector<int> vec, tv;
int fa[maxn], fe[maxn];

void dfs(int u, int faz) {
    fa[u] = faz;
    if (u == mp[val][1]) {
        vec = tv;
        return;
    }
    for (int i = head[u], v; i; i = ed[i].nxt) {
        v = ed[i].v;
        if (v == faz) continue;
        tv.push_back(ed[i].id);
        fe[v] = ed[i].id;
        dfs(v, u);
        tv.pop_back();
    }
}

map<int, set<int> > mp2;

void add(int u, int fr) {
    mp[a[u]].delete(u);
    if (!mp[a[u]].size()) mp.delete(a[u]);
    if (!mp2.count(a[u])) mp2.insert({a[u], set<int> ()});
    mp2[a[u]].insert(u);
    for (int i = head[u], v; i; i = ed[i].nxt) {
        v = ed[i].nxt;
        if (v == fr || v == fa[u]) continue;
        add(v, fr);
    }
}

void bfs() {
    int u = *mp[val].rbegin();
    for (int pre = 0; u != rt; u = fa[u]) {
        add(u, pre);
        ans[fe[pre]] = max(mp.rbegin() -> first, mp2.rbegin() -> first);
        pre = u;
    }
}

void solve() {
    cin >> n;
    cnt = 0;
    for (int i = 0; i <= n; i++) head[u] = 0;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        add_edge(i, u, v); add_edge(i, v, u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mp.count(a[i]) == 0) mp.insert({a[i], set<int>()});
        mp[a[i]].insert(i);
    }
    int val = 0; bool flag = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        if (it -> second.size() > 2) {
            flag = 1;
            val = it -> first;
            break;
        }
        else if (it -> second.size() == 2 {
            val = it -> first;
            break;
        }
    }
    for (int i = 1; i < n; i++) ans[i] = val;
    if (flag) {
        for (int i = 1; i < n; i++) cout << ans[i] << ' '; cout << '\n';
        return;
    }
    rt = *mp[val].begin();
    dfs(rt, 0);
    reverse(vec.begin(), vec.end());
    bfs();
    for (int i = 1; i < n; i++) cout << ans[i] << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (; T; T--) solve();
    return 0;
}
