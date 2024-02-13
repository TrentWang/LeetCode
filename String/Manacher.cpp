// https://www.youtube.com/live/Co5-YaJwq64?si=VD_GaqFvHVjS2uuP
// https://www.youtube.com/live/84RVnu5yhHc?si=8HOHaqA72C4Kl0Vs
// https://github.com/wisdompeak/LeetCode/tree/master/String/005.Longest-Palindromic-Substring

// O(n)
string longestPalindrome(string s) {
    string t = "#";
    for (int i = 0; i < s.size(); i++) {
        t.push_back(s[i]);
        t.push_back('#');
    }
        
    int N = t.size();
    vector<int> P(N, 0);
    int maxCenter = -1;
    int maxRight = -1;
        
    for (int i = 0; i < N; i++) {
        int r = 0;
        if (i < maxRight) {
            int j = maxCenter*2 - i;
            r = min(P[j], maxRight-i);
        }
        
        while (i-r >= 0 && i+r < N && t[i-r] == t[i+r]) 
            r++;

        P[i] = r-1;
        if (i + P[i] > maxRight) {
            maxRight = i + P[i];
            maxCenter = i;
        }
    }    
    
    int maxLen = -1;
    int center = -1;
    for (int i = 0; i < P.size(); i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            center = i;                
        }
    }
    return s.substr(center/2 - maxLen/2, maxLen);
}
