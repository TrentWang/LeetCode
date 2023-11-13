using LL = long long;
 
class BIT {
public:
    int N;
    vector<LL> B;
    BIT(int _n) : N(_n) {
        // start from index 1
        B.resize(N+1);
    }
    LL query(int x){
        // x is 1-indexed
        LL ret = 0;
        while (x){
            ret += B[x];           // query prefix sum 
            //ret = max(ret, B[x]);  // query prefix max 
            x -= x & (-x);
        }
        return ret;
    }
    void update(int x, LL val){
        // x is 1-indexed
        while(x <= N){
            B[x] += val;            // update prefix sum 
            //B[x] = max(B[x], val);  // update prefix max 
            x += x & (-x);
        }
    }
}; 
