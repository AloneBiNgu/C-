#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 5;

struct Data {
    int u, v, c;
};

int n, m, ans;
int Parent[maxN], Rank[maxN], Cost[10005][10005];
bool Visited[10005][10005];
vector<Data> args;

int Find(int u) {
    return Parent[u] == u ? u : (Parent[u] = Find(Parent[u]));
}

bool tmp(Data x, Data y) {
    return x.c < y.c;
}

bool SetJoin(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;
    if (Rank[u] == Rank[v]) Rank[u]++;
    if (Rank[u] > Rank[v]) {
        Parent[v] = u;
    } else {
        Parent[u] = v;
    }
    return true;
}

int main() {
    freopen("traffic.inp", "r", stdin);
    freopen("traffic.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) Parent[i] = i;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        Visited[u][v] = Visited[v][u] = 1;
    }

    for (int i  = 1; i <= n ; i++){
        for (int j = 1; j <= n ; j++){
            cin >> Cost[i][j];
            if (Visited[i][j]) args.push_back({i,j,0});
            else args.push_back({i,j,Cost[i][j]});
        }
    }

    sort(args.begin(), args.end(), tmp);

    for (auto it : args) {
        if (!SetJoin(it.u, it.v)) continue;
        ans += it.c;
    }

    if (ans == 0) {
        cout << "YES" << "\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
