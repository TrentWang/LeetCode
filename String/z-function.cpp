// https://kenjichao.gitbooks.io/algorithm/content/z_algorithm.html
/*
X X X X X X X X . . . . . . X X X X X X X X
0             7             L             R 
假設 z[L] = 8, s[0:7] == s[L:R]

X X X X X X X X . . . . . . X X X X X X X X
0         5   7             L         i   R 
假設要計算 z[i]
由於 s[0:7] == s[L:R], 所以 s[5:7] == s[i:R]
因此可以直接參考 z[i-L], 即 z[5] 的結果來計算 z[i]

如果 z[5] == 1, 代表
O O X X X O X X . . . . . . O O X X X O X X
0         5   7             L         i   R 
z[i] 可以直接用 z[5] 的結果


如果 z[5] == 3, 代表
O O O ? ? O O O Y . . . . . O O O ? ? O O O Z
0         5   7             L         i   R 
可以確定 s[0:2] == s[5:7] == s[i:R], 故 z[i] 可以直接繼承 z[5] 的結果
另外可以確定 s[7+1] != [R+1]
但是 s[i+z[5]] 有可能等於 s[z[5]], 即 s[3] 
*/
vector<int> computeZFunction(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}


// return: all indexes of occurrence of pattern in text
vector<int> searchPattern(const string& text, const string& pattern) {
    string concat = pattern + "$" + text;
    vector<int> z = computeZFunction(concat);

    vector<int> ret;
    for (int i = 0; i < z.size(); ++i) {
        if (z[i] == pattern.size())
            ret.push_back(i - pattern.size() - 1);
    }

    return ret;
}
