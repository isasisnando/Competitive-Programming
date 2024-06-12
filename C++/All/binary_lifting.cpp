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
const int MAX = 2e5;
const int LOG = 30;

vector<int> adj[MAX];
int up[MAX][LOG], parent[MAX];

void process(int n)
{
    for(int v = 1; v <= n; v++)
    {
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
int32_t main()
{   sws
    int n,q;
    cin >> n >> q;

    parent[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        parent[i] = x;

        adj[i].pb(x);
        adj[x].pb(i);
    }
    
    process(n);
    for(int i = 1; i <= q; i++)
    {
        int a,k;
        cin >> a >> k;
        cout << jump(a,k) << '\n';
    }
    return 0;
}