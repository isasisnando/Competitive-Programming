int log2_ceil(unsigned ll i){
    int ans = (i ? __builtin_clzll(1) - __builtin_clzll(i) : -1);
    if(ans > 0 && (1ULL << ans) ^ i) ans++;
    return ans; 
}

struct SegLazy{
    int n;
    vector<pii> s;
    vi lz;

    SegLazy(int sz) : n(1 << (log2_ceil(sz))) {
        s.assign(2*n, {0LL, 1LL});
        lz.assign(2*n, 0LL);
    }

    void build() {
        for (int i = n - 1; i > 0; i--){
            if(s[i<<1].F == s[i<<1|1].F)
                s[i] = {s[i<<1].F, s[i<<1].S + s[i<<1|1].S};
            else if(s[i<<1].F < s[i<<1|1].F)
                s[i] = {s[i<<1].F, s[i<<1].S};
            else
                s[i] = {s[i<<1|1].F, s[i<<1|1].S};
        }
    }

    void updt(int k){
        if(k < n){
            lz[k*2] += lz[k]; 
            lz[k*2+1] += lz[k]; 
        }
        s[k].F += lz[k];
        lz[k] = 0;
    }

    void add(int l, int r, int x, int k=1, int il=1, int ir=-1){
        if(ir == -1) ir = n;
        updt(k);
        if(il > r || ir < l) return;
        if(il >= l && ir <= r){
            lz[k] += x;
            updt(k);
            return;
        }
        add(l, r, x, k*2, il, (il+ir)/2);
        add(l, r, x, k*2+1, (il+ir)/2+1, ir);
        if(s[k<<1] == s[k<<1|1])
            s[k] = {s[k<<1].F, s[k<<1].S + s[k<<1|1].S};
        else if(s[k<<1] < s[k<<1|1])
            s[k] = {s[k<<1].F, s[k<<1].S};
        else
            s[k] = {s[k<<1|1].F, s[k<<1|1].S};
    }

    int query(){
        return n - (s[1].F ? 0 : s[1].S);  
    }
};