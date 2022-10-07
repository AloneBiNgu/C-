#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000005;

int n, m, soThuTuDfs, dem, tongTien, tongCach = 1, costMin;
int low[maxN], num[maxN], prices[maxN], tsMin[maxN];
int number[maxN], deleted[maxN];
vector<int> args[maxN];
stack<int> st, st2;

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
        costMin = INT_MAX;
        st2 = st;
        dem++;
        int v, v2;
        while (v != u) {
            v = st.top();
            costMin = min(costMin, prices[v]);
            st.pop();
            deleted[v] = true;
        }
        tongTien += costMin;
        while (v2 != u) {
            v2 = st2.top();
            if (costMin == prices[v2]) tsMin[dem]++;
            st2.pop();
        }
        tongCach = tongCach * tsMin[dem] % 1000000007;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("security.inp", "r", stdin);
    freopen("security.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> prices[i];

    cin >> m;

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

    cout << tongTien << " " << tongCach;

    return 0;
}
