// 3008. Find Beautiful Indices in the Given Array II
// s: main string
// p: pattern string
// return: all indexes of occurrence of p in s
vector<int> getPatternMatchingIndex(const string& s, const string& p) {
    string t = p + "@" + s;
    vector<int> suf = longestCommonPrefixSuffix(t);
    
    vector<int> ret;
    for(int i = 0; i < suf.size(); ++i){
        if(suf[i] == p.size()) 
            ret.push_back(i - 2*p.size());
    }
    return ret;
}
////////////////////////////////////////////////////////////////////////



// https://github.com/wisdompeak/LeetCode/blob/master/String/028.Implement-strStr/028.Implement-strStr-KMP.cpp
// https://www.youtube.com/live/JUlgxb8ZwpQ?si=GekEaty4WGjjzVXH
// s: main string
// p: pattern string
// return: index of first occurrence of p in s, -1 if not found
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

        dp[i] = j + (s[i] == p[j]);

        if (dp[i] == m)
            return i - m + 1;
    }
    return -1;
}

// s: main string
// p: pattern string
// return: the maximum length K for s[i] s.t. p[0:K-1] == s[i-K+1:i]
vector<int> getMatchedLen (string s, string p) {
    vector<int> suf = longestCommonPrefixSuffix(p);

    int n = s.size(), m = p.size();
    vector<int> dp(n, 0); // dp[i]: the maximum length K s.t. p[0:K-1] == s[i-K+1:i]
    dp[0] = (s[0] == p[0]);

    for (int i = 1; i < n; i++) {
        int j = dp[i-1];
        while (j > 0 && (j == m || s[i] != p[j]))
            j = suf[j-1];

        dp[i] = j + (s[i] == p[j]);
    }
    
    return dp;
}
////////////////////////////////////////////////////////////////////////



// https://yeefun.github.io/kmp-algorithm-for-beginners/ 
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
