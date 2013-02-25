/*
    Komarov Artyom
    2743
*/
#include <iostream>
using namespace std;

const int inf = (1 << 30) - 1;
int n, m, v, u, w, a[50][50], mask, ans;

int main() {
    cin >> n >> m;
    if(n == 1) {
        // Special case
        cout << 0;
        return 0;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        --u; --v;
        a[u][v] = a[v][u] = w;
    }
////////////////////////////////////////////////////////
    //Base dynamics, mask = 2^n
    mask = 1 << n;
    int dp[50][mask];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < mask; ++j)
            dp[i][j] = inf;
    dp[0][1] = 0;
////////////////////////////////////////////////////////
    // Dynamics on subsets
    for(int i = 0; i < n; i++)
        for(int j = 1; j < mask; j++)
            if(dp[i][j] != inf)
                for(int k = 0; k < n; k++)
                    if(a[i][k] != 0 && (j | (1 << k) != j))
                        dp[k][j | (1 << k)] = min(dp[k][j | (1 << k)], dp[i][j] + a[i][k]);
///////////////////////////////////////////////////////
    // Finding an answer
    ans = inf;
    for(int i = 0; i < n; i++)
        if(a[i][0] != 0)
            ans = min(ans, dp[i][mask - 1] + a[i][0]);
    if(ans != inf)cout << ans;
    else "Cycle not found";
    return 0;
}
/*
Test
4 6
1 2 1
2 3 2
3 4 1
4 1 2
1 3 1
2 4 1
*/

