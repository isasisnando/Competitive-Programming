#include <bits/stdc++.h>
using namespace std;

// Complexidade 
// build : O(N)
// find : O(logN)
class DSU
{
    public:
    vector<int> parent, sz;
    void make(int v)
    {
        parent[v] = v;
        sz[v] = 1;
    }

    int find(int v)
    {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void union_(int a, int b)
    {
        a = find(a), b = find(b);

        if(sz[b]>sz[a]) swap(a,b);
        if (a != b)
        {
            sz[a] += sz[b];
            parent[b] = a;
        }
    }
    
    bool same(int a, int b)
    {
        a = find(a), b = find(b);
        return a == b;
    }
    
    DSU(int n): parent(n+1), sz(n+1)
    {
        for(int i=1; i<=n; i++) make(i);
    }
};

void solve()
{
    int n; 
    cin >> n;
    DSU dsu(n);
}

int main()
{
    int t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}