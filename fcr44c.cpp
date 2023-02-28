#include <bits/stdc++.h>

using namespace std;

int n, q, k;
int args[100005];

void merge(int args[], int low, int mid, int right) {
    vector<int> x(args + low, args + mid + 1);
    vector<int> y(args + mid + 1, args + right + 1);

    int i = 0, j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] <= y[j]) {
            args[low] = x[i]; ++low, ++i;
        } else {
            args[low] = y[j]; ++low, ++j;
        }
    }

    while (i < x.size()) {
        args[low] = x[i]; ++low, ++i;
    }

    while (j < y.size()) {
        args[low] = y[j]; ++low, ++j;
    }
}

void mergesort(int args[], int low, int right) {
    if (low >= right) return;
    int mid = (low + right) / 2;
    mergesort(args, low, mid);
    mergesort(args, mid + 1, right);
    merge(args, low, mid, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    // freopen("fcr44c.inp", "r", stdin);
    // freopen("fcr44c.out", "w", stdout);

    cin >> n >> q >> k;

    for (int i = 0; i < n; i++) {
        cin >> args[i];
    }

    args[n + 1] = INT_MAX;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        mergesort(args, l, r);
    }

    cout << args[k] << " ";
    return 0;
}