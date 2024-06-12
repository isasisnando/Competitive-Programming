#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define pb push_back
#define endl "\n"
#define input(x) for (auto &it : x) cin >> it;
#define output(x) for (auto &it : x) cout << it << ' ';
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = 0x3f3f3f3f3f;
const long double PI = acos(-1);
const int MAX = 2e5 + 5;
const int LOG = 30;

int up[MAX][LOG], parent[MAX], depth[MAX];

void process(int n)
{
    for(int v = 1; v <= n; v++)
    {
        if(v != 1) depth[v] = depth[parent[v]] + 1;
        up[v][0] = parent[v];
        for(int i = 1; i < LOG; i++)
        {
            up[v][i] = up[up[v][i-1]][i-1];
        }
    }
}

int jump(int n, int k)
{
    for(int i = 0 ; i < LOG; i++)
    {
        if(k & ( 1 << i))
        {
            n = up[n][i];
        }
    }
    if(n == 0) return -1;
    return n;
}
int lca(int node1 , int node2)
{
    if(depth[node2] > depth[node1]) swap(node1,node2);
    int k = depth[node1] - depth[node2];
    node1 = jump(node1, k);

    if(node1 == node2) return node1;

    for(int i = LOG - 1; i >= 0; i--)
    {
        if(up[node1][i] != up[node2][i])
        {
            node1 = up[node1][i];
            node2 = up[node2][i];
        }
    }

    return up[node1][0];
}
int32_t main()
{   sws
    int n,q;
    cin >> n >> q;

    parent[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        parent[i] = x;

    }
    
    process(n);

    while(q--)
    {
        int a,b;
        cin >> a >> b;
        int ans = lca(a,b);
        cout << ans << '\n';

    }
    return 0;
}