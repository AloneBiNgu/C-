#include <bits/stdc++.h>

using namespace std;

const long long maxN = 4 * 1e5 + 7;

long long n, m;
list<long long> args[maxN];

void euler(long long u) {
    stack<long long> st;
    vector<long long> ec;
    st.push(u);
    while (!st.empty()) {
        long long x = st.top();
        list<long long>::iterator i;
        for (i = args[x].begin(); i != args[x].end(); i++) {
            long long v = *i;
            if (v != -1) {
                list<long long>::iterator iv = find(args[x].begin(), args[x].end(), v);
                *iv = -1;

                list<long long>::iterator iu  = find(args[v].begin(), args[v].end(), x);
                *iu = -1;
                st.push(v);
                break;
            }
        }
        if (x == st.top()) {
            ec.push_back(x);
            st.pop();
        }
    }
    for (int i = ec.size() - 1; i >= 0; i--) {
        cout << ec[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("euler.inp", "r", stdin);
    freopen("euler.out", "w", stdout);

    cin >> n >> m;
    for (long long i = 1; i <= m; i++) {
        long long u, v; cin >> u >> v;
        args[u].push_back(v);
        args[v].push_back(u);
    }

    euler(1);
    return 0;
}
