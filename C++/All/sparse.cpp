#include <bits/stdc++.h>

using namespace std;
#define int long long
#define vi vector<int>
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAX = 2e5+ 5;

int logv[MAX+1];
void make_log() {
    logv[1] = 0; // pre-computar tabela de log
    for (int i = 2; i <= MAX; i++)
        logv[i] = logv[i/2] + 1;
}
struct Sparse {
    int n;
    vector<vector<int>> st;

    Sparse(vector<int>& v) {
        n = v.size();
        int k = logv[n];
        st.assign(n+1, vector<int>(k+1, 0));

        for (int i=0;i<n;i++) {
            st[i][0] = v[i];
        }

        for(int j = 1; j <= k; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = f(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    int f(int a, int b) {
        return min(a, b);
    }

    int query(int l, int r) {
        int k = logv[r-l+1];
        return f(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

void solve()
{
    int n,q;
    cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    make_log();
    Sparse S = Sparse(v);

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--;r--;
        int ans = S.query(l,r);
        cout << ans << '\n'; 
    }
    return;
}
int32_t main()
{   sws

    int t;
    // cin >> t;
    t = 1;
    while(t--)solve();
    
    return 0;
}