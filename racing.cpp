#include <bits/stdc++.h>

using namespace std;

const int maxN = 2e4 + 5;

struct Edge {
    int u, v, c;
};

int n, m, ans;
vector<int> par, r;
vector<Edge> args;

bool tmp(Edge x, Edge y) {
    return x.c > y.c;
}

int find(int u) {
    return par[u] == u ? par[u] : par[u] = (find(par[u]));
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (r[u] == r[v]) r[u]++;
    if (r[u] > r[v]) {
        par[v] = u;
    } else {
        par[u] = v;
    }
    return true;
}

int main() {
    freopen("racing.inp", "r", stdin);
    freopen("racing.out", "w", stdout);

    cin >> n >> m;

    par.resize(n + 5);
    r.resize(n + 5);

    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v, c; cin >> u >> v >> c;
        args.push_back({u, v, c});
    }

    sort(args.begin(), args.end(), tmp);

    for (auto e : args) {
        if (join(e.u, e.v)) continue;
        ans += e.c;
    }

    cout << ans;
    return 0;
}
