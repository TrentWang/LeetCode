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
/*
為什麼 (n-i+1)/i 可以保證整除?
假設 m = 2
1 2 3 4 5 6 7 8 9
^^^           ^^^
a b           x y   => x/a * y/b   => x/1 * y/2
一個連續數組 [1, k] 任意挑選 [i, i+1], i >= 1 && i < k, 則 i 跟 i+1 之中必定會有一個 2 的倍數(一奇數一偶數), 我們用 1p 代表奇數, 2p 代表偶數
如果 [i, i+1] 是 [1p, 2p], 組合公式會是 1p/1 * 2p/2, 2p 是偶數所以 2p/2 可以整除   
如果 [i, i+1] 是 [2p, 1p], 組合公式會是 2p/1 * 1p/2, 雖然只看 1p/2 是無法整除的, 但是 1p 之前已經出現過偶數, 所以當下 ans 是偶數, 實際上是 (2p/1*1p) / 2, 也可以整除

一個連續數組 [1, k] 任意挑選 [i, i+1, i+2], i >= 1 && i+2 <= k, 每三個連續數組中一定會有一個 3 的倍數, 我們用 3p 來代表該 3 的倍數
如果 [i, i+1, i+2] 是 [1p, 2p, 3p], 組合公式會是 1p/1 * 2p/2 * 3p/3
如果 [i, i+1, i+2] 是 [2p, 3p, 1p], 組合公式會是 2p/1 * 3p/2 * 1p/3
如果 [i, i+1, i+2] 是 [3p, 1p, 2p], 組合公式會是 3p/1 * 1p/2 * 2p/3 (任意兩個連續數中一定有一個 2 的倍數, 所以 1p 或 3p 其中之一必為2的倍數)

簡單說就是
for(int i = 1; i <= m; ++i)
    ans = ans * (n-i+1) / i;
當 i = 2 時, (n-i+1) 那邊會掃過 2 個數, 2 個連續數中必有一 2 的倍數, 所以 ans 可以整除 2
當 i = 3 時, (n-i+1) 那邊會掃過 3 個數, 3 個連續數中必有一 3 的倍數, 所以 ans 可以整除 3
當 i = 4 時, (n-i+1) 那邊會掃過 4 個數, 4 個連續數中必有一 4 的倍數, 所以 ans 可以整除 4
..... 
*/

