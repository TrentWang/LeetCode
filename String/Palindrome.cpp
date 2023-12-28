// Leetcode 564. Find the Closest Palindrome

string makeNextSmallerPalindrome(const string &str) {
    int n = str.size();
    string s = str;
    for (int i = 0, j = n-1; i <= j; ++i, --j)
        s[j] = s[i];                    
    if (s < str)
        return s;
    int carry = 1;
    for (int i = (n-1)/2; i >= 0; i--) {
        int d = s[i]-'0'-carry;
        if (d >= 0) {
            s[i] = '0'+d;
            carry = 0;
        } else {
            s[i] = '9';
            carry = 1;
        }
        s[n-1-i] = s[i];
    }
    if (s[0] == '0' && n > 1)
        return string(n-1, '9');
    else
        return s;
}

string makeNextGreaterPalindrome(const string &str) {
    int n = str.size();
    string s = str;
    for (int i = 0, j = n-1; i <= j; ++i, --j)
        s[j] = s[i];                    
    if (s > str)
        return s;
    int carry = 1;
    for (int i = (n-1)/2; i >= 0; i--) {
        int d = s[i]-'0'+carry;
        if (d<=9) {
            s[i] = '0'+d;
            carry = 0;
        } else {
            s[i] = '0';
            carry = 1;
        }
        s[n-1-i] = s[i];
    }
    if (carry == 1) 
        return "1" + string(n+1-2, '0') + "1";
    else
        return s;
}
