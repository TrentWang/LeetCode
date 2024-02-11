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
