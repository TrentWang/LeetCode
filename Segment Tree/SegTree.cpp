// simple segment tree (no range update)
template<class T> struct Seg {
    const T DEFAULT = 0; // change here
    int n; 
    vector<T> seg;

    T comb(T a, T b) { return max(a, b); } //change here

    // 0-indexed
    void init(int _n) { 
        n = _n; 
        seg.assign(2*n, DEFAULT);
    }
    void init(const vector<int>& arr) { 
        n = arr.size(); seg.resize(2*n); 
        for(int i = 0; i<n; i++) 
            seg[i+n] = arr[i];
        push();
    }
    void pull(int p) { 
        seg[p] = comb(seg[2*p], seg[2*p+1]); 
    }
    void push() { 
        for(int i = n-1; i > 0; i--) 
            seg[i] = comb(seg[i<<1], seg[i<<1|1]); 
    }
    void update(int p, T val) { // set val at position p
        seg[p += n] = val; 
        for (p /= 2; p; p /= 2) 
            pull(p); 
    }
    T query(int l, int r) {	// sum on interval [l, r]
        T ra = DEFAULT, rb = DEFAULT;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra, seg[l++]);
            if (r&1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};



// simple segment tree (no range update)
struct SegTree {
    vector<LL> tree;
    int N;
    // 0-indexed
    SegTree(int _n) : N(_n) {
        tree.resize(4*N);
    }
    void update(int ind, LL val) {
        update(ind, val, 0, N-1, 0);
    }    
    void update(int ind, LL val, int l, int r, int i) {
        if (l == r) {
            tree[i] = val;
            return;
        }
        int m = (l+r) >> 1;
        if (ind <= m) 
            update(ind, val, l, m, i*2+1);
        else 
            update(ind, val, m+1, r, i*2+2);
        tree[i] = max(tree[i*2+1], tree[i*2+2]);
    }
    LL query(int x, int y) {
        return query(x, y, 0, N-1, 0);
    }
    LL query(int x, int y, int l, int r, int i) {        
        if (x > r || y < l) 
            return 0;
        if (x <= l && r <= y)
            return tree[i];
        int m = (l+r) >> 1;
        return max(query(x, y, l, m, i*2+1), query(x, y, m+1, r, i*2+2));
    }
};



// segment tree with range update (Lazy Propagation)
template<class T> struct Seg {
    int lo, ro, size;
    vector<T> seg;
    vector<T> lazy;
    Seg(int n) {
        // range [1:n]
        lo = 1;
        ro = n;
        size = ro - lo + 1;
        seg.resize(4*size, 0);
        lazy.resize(4*size, 0);
    }
    void updateRange(int left, int right, int val) {
        return update(1, lo, ro, left, right, val);
    }
    T queryRange(int left, int right) {
        return query(1, lo, ro, left, right);
    }
    void update(int curr, int left, int right, int updateLeft, int updateRight, T val) {
        if(updateLeft > updateRight)
            return;
        if(left == updateLeft && right == updateRight) {
            if(left == right) {
                seg[curr] += val;
            } else {
                seg[curr] += T(right - left + 1) * val;
                lazy[curr] += val;
            }
            return;
        }
        int leftChild = curr*2, rightChild = curr*2+1;
        int mid = left + (right - left)/2;
        if(lazy[curr])
            doLazy(curr, leftChild, rightChild, left, mid, right);

        update(leftChild, left, mid, updateLeft, min(mid, updateRight), val);
        update(rightChild, mid+1, right, max(mid+1, updateLeft), updateRight, val);
        seg[curr] = seg[leftChild] + seg[rightChild];
    }
    T query(int curr, int left, int right, int queryLeft, int queryRight) {
        if(queryLeft > queryRight)
            return 0;
        if(left == queryLeft && right == queryRight)
            return seg[curr];
        int leftChild = curr*2, rightChild = curr*2+1;
        int mid = left + (right - left)/2;
        if(lazy[curr])
            doLazy(curr, leftChild, rightChild, left, mid, right);

        return query(leftChild, left, mid, queryLeft, min(mid, queryRight)) 
             + query(rightChild, mid+1, right, max(mid+1, queryLeft), queryRight);
    }
    void doLazy(int curr, int leftChild, int rightChild, int left, int mid, int right) {
        seg[leftChild] += T(mid - left + 1) * lazy[curr];
        lazy[leftChild] += lazy[curr];
        seg[rightChild] += T(right - (mid + 1) + 1) * lazy[curr];
        lazy[rightChild] += lazy[curr];
        lazy[curr] = 0;
    }
};



// segment tree with range update (Lazy Propagation)
template<class T> struct SegmentTree {
    int n;
    vector<T> lzy;
    vector<T> sum;

    SegmentTree (int _n) : n(_n) {
        // range: [0:n-1]
        lzy.resize(4*n, 0);
        sum.resize(4*n, 0);
    }
    void updateRange(int l, int r, int val) {
        update(0, 0, n-1, l, r, val);
    }
    T queryRange(int l, int r) {
        return query(0, 0, n-1, l, r);
    }
    void update_lzy(int curr, int l, int r) {
        if(lzy[curr] == 0)
            return;
        if (l != r) {
            lzy[curr*2+1] += lzy[curr];
            lzy[curr*2+2] += lzy[curr];
        }
        sum[curr] = sum[curr] + lzy[curr] * (r-l+1);
        lzy[curr] = 0;
    }
    void update(int curr, int l, int r, int ul, int ur, int val) {
        update_lzy(curr, l, r);
        if (r < ul || l > ur) 
            return;
        if (l >= ul && r <= ur) {
            lzy[curr] = val;
            return update_lzy(curr, l, r);
        }
        int m = (l+r) >> 1, leftChild = curr*2+1, rightChild = curr*2+2;
        update(leftChild, l, m, ul, ur, val);
        update(rightChild, m+1, r, ul, ur, val);
        sum[curr] = sum[leftChild] + sum[rightChild];
    }
    T query(int curr, int l, int r, int ql, int qr) {
        update_lzy(curr, l, r);
        if (r < ql || l > qr) 
            return 0;
        if (l >= ql && r <= qr)
            return sum[curr];
        int m = (l+r) >> 1;
        return query(curr*2+1, l, m, ql, qr) + query(curr*2+2, m+1, r, ql, qr);
    }    
};

