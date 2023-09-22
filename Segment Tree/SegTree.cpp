template<class T> struct Seg {
    const T ID = 0; // change here
    T comb(T a, T b) { return max(a,b); }//change here
    int n; 
    vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void init(const vector<int>& arr) { 
        n = arr.size(); seg.resize(2*n); 
        for(int i = 0; i<n; i++) 
            seg[i+n] = arr[i];
        push();
    }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void push() { for(int i = n-1; i > 0; i--) seg[i] = comb(seg[i<<1], seg[i<<1|1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {	// sum on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};
