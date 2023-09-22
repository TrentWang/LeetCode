int quickPow(int x, unsigned int y) {
    if (y == 0)
        return 1;
    int p = quickPow(x, y / 2);
    p *= p;
    return y % 2 ? (p * x) : p;
}

int modPow(int x, unsigned int y, unsigned int m) {
    if (y == 0)
        return 1;
    long p = modPow(x, y / 2, m) % m;
    p = (p * p) % m;
    return y % 2 ? (p * x) % m : p;
}

int quickPow2(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (int)((1L * res * x) % MOD);
        }
        x = (int)((1L * x * x) % MOD);
        n /= 2;
    }
    return res;
}
