// Description: Find all the occurrences of a pattern in str. ex: abcabc, abc -> 0, 3
vector<int> FindSubstr(const string& str, const string& pattern) {
    vector<int> index;
    int n = str.size(), m = pattern.size();
    if (n < m)
        return index;

    // rolling hash
    long strHash = 0, ptnHash = 0, mul = 1, mod = 1e9+7;

    for(int i = 0; i < m; ++i) {
        ptnHash = (ptnHash*26 + (pattern[i] - 'a' + 1)) % mod;
        mul = mul * 26 % mod;
    }
    
    for(int l = 0, r = 0; r < n; ++r) {
        strHash = (strHash*26 + (str[r] - 'a' + 1)) % mod;

        if(r-l+1 > m)
            strHash = (strHash - ((str[l++] - 'a' + 1) * mul % mod) + mod) % mod;

        if(r-l+1 == m && strHash == ptnHash && memcmp(str.c_str() + l, pattern.c_str(), m) == 0)
            index.push_back(l);
    }
    return index;
}
