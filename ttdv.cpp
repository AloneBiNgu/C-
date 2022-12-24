#include <bits/stdc++.h>

using namespace std;

const int maxN = 5e3 + 5;

int n, m;
vector<pair<int, int>> args[maxN];

int dijkstra(int s) {
    vector<int> d(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    int res = 0;

    d[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        pair<int, int> t = q.top(); q.pop();

        int u = t.second;
        int dis = t.first;

        if (dis != d[u]) continue;
        res += d[u];
        d[u] = -INT_MAX;

        for (auto it : args[u]) {
            int v = it.first;
            int w = it.second;
            if (d[v] > dis + w) {
                d[v] = dis + w;
                q.push({d[v], v});
            }
        }
    }
    return res;
}

int main() {
    freopen("ttdv.inp", "r", stdin);
    freopen("ttdv.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        args[u].push_back({v, w});
        args[v].push_back({u, w});
    }
    
    vector<int> list;
    for (int i = 1; i <= n; i++) {
        list.push_back(dijkstra(i));
    }

    int index = distance(list.begin(), min_element(list.begin(), list.end()));
    cout << index + 1 << "\n" << list[index] << "\n";
    
    return 0;
}