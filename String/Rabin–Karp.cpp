// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/
// pattern: pattern string
// text: text string
// return: vector of indices where pattern occurs in text
vector<int> rabin_karp(const string& pattern, const string& text) {
    const int p = 31; 
    const int mod = 1e9 + 9;
    int PS = pattern.size(), TS = text.size();
    vector<long long> p_pow(max(PS, TS)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % mod;
    
    vector<long long> hash(TS + 1, 0); 
    for (int i = 0; i < TS; i++)
        hash[i+1] = (hash[i] + (text[i] - 'a' + 1) * p_pow[i]) % mod; 
    
    long long hash_p = 0; 
    for (int i = 0; i < PS; i++) 
        hash_p = (hash_p + (pattern[i] - 'a' + 1) * p_pow[i]) % mod; 
    
    vector<int> occurrences;
    for (int i = 0; i + PS - 1 < TS; i++) {
        long long hash_cur = (hash[i+PS] + mod - hash[i]) % mod;
        if (hash_cur == hash_p * p_pow[i] % mod)
            occurrences.push_back(i);
    }
    return occurrences;
}
