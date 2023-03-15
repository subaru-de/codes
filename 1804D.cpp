#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int n, m;

void solve() {
  cin >> n >> m;
  vector<vector<bool> > vec; vec.clear();
  vec.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    vec[i].resize(n + 1); 
  }
  ll summn = 0, summx = 0;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      vec[i][j + 1] = str[j] - '0';
      if (vec[i][j + 1]) summn++;
      else summx++;
    }
  }
  for (int i = 1; i <= n; i++) {
    bool pre = 0; int tmp = 0;
    for (int j = 1; j <= m; j++) {
      if (pre && vec[i][j]) tmp++, pre = 0;
      else if (vec[i][j]) pre = 1;
      else pre = 0;
    }
    summn -= min(tmp, m >> 2);
    pre = 0; tmp = 0;
    for (int j = 1; j <= m; j++) {
      if (pre || !vec[i][j]) tmp++, pre = 0;
      else if (!vec[i][j]) pre = 1;
      else pre = 0;
    }
    summx -= min(tmp, m >> 2);
  }
  summx = 1ll * n * ((m >> 1) + (m >> 2)) - summx;
  cout << summn << ' ' << summx << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1; // cin >> T;
  for (; T; T--) solve();
  return 0;
}
