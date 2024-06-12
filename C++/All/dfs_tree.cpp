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
const int MAX = 4e5 + 10;
int n,m;
vector<pair<int,int>> graph[MAX];
vector<pair<int,int>> edge(MAX);
bool bridge[MAX];
bool vis[MAX];
int tin[MAX], low[MAX], comp[MAX],st[MAX];
int componentes = 0, temp = 0, aux;
vector<int> vert_com[MAX];

void dfs(int u, int p)
{
    vis[u] = true;
    temp++;
    tin[u] = low[u]= temp;
    aux++;
    st[aux] = u;
    for(auto [v, idx] : graph[u])
    {
        if(v == p) continue;
        if(vis[v])
        {
            low[u] = min(low[u], tin[v]);
            continue;
        }
        dfs(v,u);
        low[v] = min(low[v], low[u]);
        if(low[v] > tin[u])
        {
            bridge[idx] = true;
        }
    }
    if(low[u] == tin[u])
    {
        componentes++;
        int vert;
        do
        {
            cout << "u: " <<  u << endl;
            vert = st[aux];
            aux--;
            comp[vert] = componentes;
            vert_com[componentes].pb(vert);
        } while (vert != u);     
    }
}
bool vis2[MAX];
bool used[MAX];
void dfs2(int u, int p)
{
    vis2[u] = true;
    for(auto [v, idx] : graph[u])
    {
        if(v == p) continue;
        if(!used[idx])
        {
            if(bridge[idx]) edge[idx] = {v,u};
            else edge[idx] = {u,v};
            used[idx] = true;
        }
        if(vis[v]) continue;
        dfs2(v,u);
    }
}   


int32_t main()
{   sws
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
    }
    dfs(1,0);

    int mx = 0,  ini = 0;
    for(int i = 1; i <= componentes; i++)
    {
        if(vert_com[i].size() > mx)
        {
            ini = i;
            mx = vert_com[i].size();
        }
    }
    for(auto x : vert_com[ini])
    {
        cout << x << " ";
    }
    cout << endl;
    //cout << "ni: " << ini << ' ' << mx << endl;

    dfs2(vert_com[ini][0], vert_com[ini][0]);

    for(int i = 1; i <= m; i++)
    {
        int a = edge[i].ff;
        int b = edge[i].ss;
        cout << a << " " << b << endl;
    }
    return 0;
}