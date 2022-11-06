#include <bits/stdc++.h>

using namespace std;

const long long maxN = 4 * 1e5 + 7;

long long n, m;
int visited[maxN];
vector<pair<int, int>> adj[maxN];

void euler(long long u) {
    stack<long long> st;
    vector<long long> path;
    st.push(u);
    while (!st.empty()) {
        long long v = st.top();
        int f = 0;
        while (!adj[v].empty()) {
            auto [u, i] = adj[v].back(); adj[v].pop_back();
            // cout << u << " ";
            if (!visited[i]) {
                st.push(u);
                visited[i] = 1;
                f = 1;
                break;
            }
        }
        if (!f) {
            path.push_back(v);
            st.pop();
        }
    }
    for (auto i : path) {
        cout << i << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("euler.inp", "r", stdin);
    freopen("euler.out", "w", stdout);

    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
        long long u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    euler(1);
    return 0;
}
