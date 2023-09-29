int C1(int n, int m) {
    if(n == m || m == 0)
        return 1;
    return C1(n-1, m) + C1(n-1, m-1);
}

int C2(int n, int m) {
    if(n == m || m == 0)
        return 1;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= i && j <= m; ++j) {
            if(i == j || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    return dp[n][m];
}

int C3(int n, int m) {
    if(n == m || m == 0)
        return 1;
    return C3(n, m-1) * (n-m+1) / m;
}

// C(n, m) = n!/m!(n-m)! = n(n-1)(n-2)...(n-m+1)/m!
int C4(int n, int m) {
    if(n == m || m == 0)
        return 1;
    int ans = 1;
    m = min(m, n-m);
    for(int i = 1; i <= m; ++i)
        ans = ans * (n-i+1) / i;
    return ans;
}

