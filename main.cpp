#include <iostream>
#include <vector>
using namespace std;

const int inf = (1 << 30) - 1;
int n, m, v, u, w, a[50][50], mask, ans;

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        --u; --v;
        a[u][v] = a[v][u] = w;
    }
////////////////////////////////////////////////////////
    mask = 1 << n;
    int dp[50][mask];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < mask; ++j)
            dp[i][j] = inf;
    dp[0][1] = 0;
////////////////////////////////////////////////////////
    for(int i = 0; i < n; i++)
        for(int j = 1; j < mask; j++)
            if(dp[i][j] != inf)
                for(int k = 0; k < n; k++)
                    if(a[i][k] != 0 && (j | (1 << k) != j))
                        dp[k][j | (1 << k)] = min(dp[k][j | (1 << k)], dp[i][j] + a[i][k]);
///////////////////////////////////////////////////////
    ans = inf;
    for(int i = 0; i < n; i++)
        if(a[i][0] != 0)
            ans = min(ans, dp[i][mask - 1] + a[i][0]);
    cout << ans;
    return 0;
}
