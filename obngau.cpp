#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

int n, m, s, t;

vector<pair<int, int>> adj[maxN];

int dijkstra(int s, int t) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> d(n + 1, INT_MAX);
    
    int res = 0;

    d[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto top = q.top(); q.pop();

        int u = top.second;
        int distance = top.first;

        if (distance != d[u]) continue;

        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    return d[t];
}

vector<int> dijkstra2(int s, int t) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> d(n + 1, INT_MAX);
    
    int res = 0;

    d[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto top = q.top(); q.pop();

        int u = top.second;
        int distance = top.first;

        if (distance > d[u]) continue;

        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    return d;
}

int main() {
    freopen("obngau.inp", "r", stdin);
    freopen("obngau.out", "w", stdout);

    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> sp(n + 1, 0), tp(n + 1, 0);
    vector<int> st = dijkstra2(s, t), ts = dijkstra2(t, s);

    for (int i = 1; i <= n; i++) {
        sp[i] = dijkstra(s, i);
        tp[i] = dijkstra(t, i);
    }

    int res = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (i != s && i != t) {
            if (sp[i] == tp[i] && sp[i] == st[i] && tp[i] == ts[i] && sp[i] != 0 && tp[i] != 0) {
                res = min(res, i);
            }
        }
    }

    if (res == 0) {
        cout << "CRY";
    } else {
        cout << res;
    }
    return 0;
}