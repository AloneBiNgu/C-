#include <bits/stdc++.h>
 
#define fto(i, x, y) for (int i = (x); i < (y); ++i)
#define fdto(i, x, y) for (int i = (x); i > (y); --i)
 
using namespace std;

const int maxN = 10005;
const int oo = 10000007; 

int r, c, ans = 0;
string a[maxN];
 
void check(int i, int j) {
    a[i][j] = '.';
    if (i < r && a[i + 1][j] == '#') check(i + 1, j);
    if (j < c && a[i][j + 1] == '#') check(i, j + 1);
    if (i > 0 && a[i - 1][j] == '#') check(i - 1, j);
    if (j > 0 && a[i][j - 1] == '#') check(i, j - 1);
}
 
int main() {
    freopen("vbgrass.inp", "r", stdin);
    freopen("vbgrass.out", "w", stdout);
    
    scanf("%d%d\n", &r, &c);
    fto (i, 0, r) getline(cin, a[i]);
 
    fto (i, 0, r) {
        fto (j, 0, c) {
            if (a[i][j] == '#') {
                check(i, j);
                ++ans;
            }
        }
    }
 
    printf("%d", ans);
 
    return 0;
}
