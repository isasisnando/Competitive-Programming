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
#define ff first
#define ss second
 const int INF = 0x3f3f3f3f3f;
const long double PI = acos(-1);
const int MAX = 2e5;

int n,q,d;
int componente[MAX];
vector<int> adj[MAX];
vector<int> adj2[MAX];
vector<int> saida;
int vis[MAX];

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
    saida.pb(u);
}

void dfs2(int u, int c)
{
    vis[u] = 2;
    componente[u] = c;
    for(auto v : adj2[u])
    {
        if(vis[v] == 1) dfs2(v, c);
    }
}


void solve()
{
    cin >> n  >> m;
    
    for(int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj2[y].pb(x);
    }
  


    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    int c = 0;
    for(int i = saida.size() - 1; i >= 0; i--)
    {
        if(vis[saida[i]] == 1)
        {
            c++;
            dfs2(saida[i], c);
        }
    }
 
    return;
}
int32_t main()
{   sws

    int t = 1;
    while(t--) solve();
    return 0;
}