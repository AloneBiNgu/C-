#include <bits/stdc++.h>

using namespace std;

int n, m, soKhop, soCau, thuTu, thoiGian;
int joint[1000005], low[1000005], num[1000005], parent[1000005], child[1000005];
vector<int> args[1000005];
vector<int> dinh;
vector<pair<int, int>> haiDinhMut;

void dfs(int u) {
    num[u] = low[u] = ++thoiGian;
    for (int v : args[u]) {
        if (v == parent[u]) continue;
        if (!num[v]) {
            parent[v] = u;
            ++child[u];
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) {
                soCau++;
                haiDinhMut.push_back(make_pair(u, v));
            }
            if (parent[u] == -1) {
                if (child[u] >= 2) {
                    joint[u] = true;
                }
            } else if (low[v] >= num[u]) {
                joint[u] = true;
            }
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("cut.inp", "r", stdin);
    freopen("cut.out", "w", stdout);
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        args[u].push_back(v);
        args[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            dfs(i);
        }
    }

    for (int u = 1; u <= n; u++) {
        if (joint[u]) {
            soKhop++;
        }
    }

    cout << soCau << " " << soKhop << "\n";

    for (int i = 0; i < haiDinhMut.size(); i++) {
        cout << haiDinhMut[i].first << " " << haiDinhMut[i].second << "\n";
    }

    for (int i = 1; i <= n; i++) {
        if (joint[i]) {
            cout << i << "\n";
        }
    }
    return 0;
}
