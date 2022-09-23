#include <bits/stdc++.h>

using namespace std;

int n, m, soThuTuDfs, dem;
int low[1000005], num[1000005], deleted[1000005];
vector<int> args[1000005];
stack<int> st;

void dfs(int u) {
    low[u] = num[u] = ++soThuTuDfs;
    st.push(u);
    for (int v : args[u]) {
        if (deleted[v]) continue;
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        ++dem;
        int v;
        while (v != u) {
            v = st.top();
            st.pop();
            deleted[v] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("TJALG.inp", "r", stdin);
    freopen("TJALG.out", "w", stdout);
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        args[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            dfs(i);
        }
    }

    cout << dem;

    return 0;
}

