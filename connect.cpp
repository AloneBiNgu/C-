#include <bits/stdc++.h>

using namespace std;

int n, m;
bool visit[1000005];
vector<long long> args[1000005];

void dfs(int u) {
    visit[u] = true;
    cout << u << " ";
    for (int i = 0; i < args[u].size(); i++) {
        if (!visit[args[u][i]]) {
            dfs(args[u][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("connect.inp", "r", stdin);
    freopen("connect.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        args[u].push_back(v);
        args[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(args[i].begin(), args[i].end());
    }

    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            dfs(i);
            cout << "\n";
        }
    }
    return 0;
}
