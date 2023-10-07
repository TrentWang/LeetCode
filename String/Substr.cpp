// Description: Find all the occurrences of a pattern in str. ex: abcabc, abc -> 0, 3
vector<int> FindSubstr(const string& str, const string& pattern) {
    vector<int> index;
    int n = str.size(), m = pattern.size();
    if (n < m)
        return index;

    // rolling hash
    long mod = 1e9+7;
    long sHash = 0, sHash2 = 0;
    long tHash = 0, tHash2 = 0;
    long mul = 1, mul2 = 1;
    
    for(int i = 0; i < m; ++i) {
        sHash *= 26;
        sHash += (str[i] - 'a');
        sHash %= mod;
        sHash2 *= 27;
        sHash2 += (str[i] - 'a');
        sHash2 %= mod;

        tHash *= 26;
        tHash += (pattern[i] - 'a');
        tHash %= mod;
        tHash2 *= 27;
        tHash2 += (pattern[i] - 'a');
        tHash2 %= mod;

        mul *= 26;
        mul %= mod;
        mul2 *= 27;
        mul2 %= mod;
    }

    if(sHash == tHash && sHash2 == tHash2)
        index.push_back(0);

    for(int i = m; i < n; ++i) {
        sHash *= 26;
        sHash += mod;
        sHash -= (str[i - m] - 'a') * mul % mod;
        sHash += (str[i] - 'a');
        sHash %= mod;
        sHash2 *= 27;
        sHash2 += mod;
        sHash2 -= (str[i - m] - 'a') * mul2 % mod;
        sHash2 += (str[i] - 'a');
        sHash2 %= mod;
        if(sHash == tHash && sHash2 == tHash2)
            index.push_back(i - m + 1);
    }

    return index;
}
