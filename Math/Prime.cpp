// 判斷是否為質數
bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// 埃拉托斯特尼篩法, Find all primes <= n.
vector<int> Eratosthenes1(int n) {
    vector<bool> a(n+1, true);
    for (int i = 2; i*i <= n; i++) {
        if (!a[i]) continue;
        for (int j = i*i; j <= n; j += i) a[j] = false;
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (!a[i]) continue;
        primes.push_back(i);
    }
    return primes;
}

// 埃拉托斯特尼篩法 - 變形, primesCnt[i] 代表數字 i 擁有"幾種"質因數
vector<int> Eratosthenes2(int n) {
    vector<int> primesCnt(n+1, 0);
    for (int i = 2; i <= n; i++) {
        if (primesCnt[i] >= 1) continue;
        primesCnt[i] = 1;
        for (int j = i*2; j <= n; j += i) primesCnt[j]++;
    }
    return primesCnt;
}

// 埃拉托斯特尼篩法 - 變形, 回傳 n 的質因數
vector<int> Eratosthenes3(int n) {
    vector<int> primes;
    if(n >= 2 && n % 2 == 0) {
        primes.push_back(2);
        while(n % 2 == 0)
            n = n/2;
    }
    for (int i = 3; i*i <= n; i += 2) {
        if(n % i)
            continue;
        primes.push_back(i);
        while(n % i == 0)
            n = n/i;
    }
    if(n > 2)
        primes.push_back(n);
    return primes;
}

// 回傳 num 的質因數 (跟Eratosthenes3類似)
vector<int> GetPrimes(int num) {
    static const vector<int> Primes = Eratosthenes1(100005);
    vector<int> ret;
    for(auto p : Primes) {
        if(p > num)
            break;
        if(num % p)
            continue;
        ret.push_back(p);
        while(num % p == 0)
            num = num/p;
    }
    return ret;
}

// 判斷一個數是否為質數
bool isPrime(int num) {
    if(num == 2) 
        return true;
    if(num % 2 == 0 || num < 2)
        return false;
    for(int i = 3; i*i <= num; i += 2) {
        if(num % i == 0)
            return false;
    }
    return true;
}
