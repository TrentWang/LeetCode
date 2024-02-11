// https://github.com/wisdompeak/LeetCode/blob/master/String/028.Implement-strStr/028.Implement-strStr-KMP.cpp
int strStr(string s, string p) {
    int n = s.size();
    int m = p.size();
    if (m == 0) return 0;
    if (n == 0) return -1;    

    vector<int> suf = longestCommonPrefixSuffix(p);
        
    vector<int> dp(n, 0); // dp[i]: the maximum length K s.t. p[0:K-1] == s[i-K+1:i]
    dp[0] = (s[0] == p[0]);
    if (m == 1 && dp[0] == 1)
        return 0;

    for (int i = 1; i < n; i++) {
        int j = dp[i-1];
        while (j > 0 && (j == m || s[i] != p[j]))
            j = suf[j-1];

        if(j == 0)
            dp[i] = (s[i] == p[0]);
        else
            dp[i] = j + 1;

        if (dp[i] == m)
            return i - m + 1;
    }
    return -1;
}


//////// https://yeefun.github.io/kmp-algorithm-for-beginners/ 
// s: main string
// p: pattern string
// return: index of first occurrence of p in s, -1 if not found
int indexOfByKmp(const string &s, const string &p) {
    int sI = 0;
    int pI = 0;

    vector<int> next = longestCommonPrefixSuffix(p);

    while (sI < s.size() && pI < p.size()) {
        if (s[sI] == p[pI]) {
            sI += 1;
            pI += 1;
        } else if (pI <= 0) {
            sI += 1;
        } else {
            pI = next[pI - 1];
        }
    }

    if (pI >= p.size()) {
        return sI - p.size();
    } else {
        return -1;
    }
}

// s: main string
// p: pattern string
// return: all indexes of occurrence of p in s
vector<int> allIndexOfByKmp(const string &s, const string &p) {
    vector<int> ret;
    int sI = 0;
    int pI = 0;

    vector<int> next = longestCommonPrefixSuffix(p);

    while (sI < s.size()) {
        if (s[sI] == p[pI]) {
            sI += 1;
            pI += 1;
            if (pI == p.size()) {
                ret.push_back(sI - p.size());
                pI = next[pI - 1];
            }
        } else if (pI <= 0) {
            sI += 1;
        } else {
            pI = next[pI - 1];
        }
    }
    
    return ret;
}
////////////////////////////////////////////////////////////////////////
