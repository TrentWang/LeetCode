// https://github.com/wisdompeak/LeetCode/tree/master/String/1392.Longest-Happy-Prefix
// https://www.youtube.com/live/n4an59As73Y?si=wmmfA8OO0cRsZiDi

// return a vector dp that dp[i] is the maximum length K s.t. s[0:K-1] == s[i-K+1:i]
// Time Complexity: O(n)
vector<int> longestCommonPrefixSuffix(string s) {
    
    int n = s.size();
    vector<int>dp(n); // dp[i]: the maximum length K s.t. s[0:K-1] == s[i-K+1:i]
    
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = dp[i-1];
        while (j >= 1 && s[j] != s[i]) {
            j = dp[j-1];
        }
        dp[i] = j + (s[j] == s[i]);
    }
    return dp;
}
