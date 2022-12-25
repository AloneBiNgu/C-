#include <bits/stdc++.h>

using namespace std;

const int maxN = 33000;

int n, m;
vector<pair<int, int>> args[maxN];

void dijkstra(int s) {
    vector<int> d(n + 1, INT_MAX);
    vector<long long> f(n + 1, INT_MAX);
    d[s] = 0;
    f[s] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        pair<int, int> t = q.top(); q.pop();
        int u = t.second;
        int dis = t.first;
        if (u == n) break;
        if (dis != d[u]) continue;
        for (auto it : args[u]) {
            int v = it.second;
            int l = it.first;

            if (d[v] > dis + l) {
                d[v] = dis + l;
                f[v] = f[u];
                q.push({d[v], v});
            } else if (d[v] == dis + l) {
                f[v] += f[u];
            }
        }
    }
    cout << d[n] << " " << f[n] << "\n";
}

int main() {
    freopen("qbschool.inp", "r", stdin);
    freopen("qbschool.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int k, u, v, l; cin >> k >> u >> v >> l;
        args[u].push_back({l, v});
        if (k == 2) {
            args[v].push_back({l, u});
        }
    }
    dijkstra(1);
    return 0;
}
