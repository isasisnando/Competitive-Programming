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

const int INF = 0x3f3f3f3f;
const long double PI = acos(-1);
const int MAX = 2e5 + 5;
const int LOG = 30;
const int pot = 1<< 20;


int up[MAX][LOG], parent[MAX], depth[MAX];
int prof[MAX];
pair<bool,int> locks[MAX];
vector<int> keys;
int need[MAX];
vector<pii> adj[MAX];
int ances[20][20];
int memo[20][pot];
bool vis[MAX], rep[20][pot];

int n,k;

void dfs(int i)
{
    if(vis[i]) return;
    vis[i] = true;
    for(auto [j, w] : adj[i])
    {
        prof[j] = prof[i] + w;
        if(locks[j].ff)
        {
            need[j] = (need[i] | (1 << locks[j].ss));
        }
        else
        {
            need[j] = need[i];
        }
        dfs(j);
    }
}

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
int dist(int a, int b)
{
    return prof[keys[a]] + prof[keys[b]] - 2*(prof[ances[a][b]]);
}
bool check(int i, int conj)
{
    bool ok = true;
    for(int j = 0; j <= k; j++)
    {
        if(((1<<j) & need[keys[i]]) and not ((1 << j) & conj)) ok = false;    
    }
    return ok;
}
int dp(int id, int conj)
{
    if(keys[id] == n) return 0;
    if(memo[id][conj] != -1) return memo[id][conj];
   
    

    int ans = INF;
    for(int i = 1; i <= k+1; i++)
    {
        if(i == id) continue;
        if(!check(i, conj) ) continue;
        if((1 << i) & conj) continue;
        int aux = conj;
        if(i <= k and i >= 1) aux |= (1<<i);
        ans = min(dp(i, aux) + dist(id, i), ans);
        //cout << "dp " << id << " " << conj << ' ' << ans << "\n";  
    }
    
    return memo[id][conj] = ans;
}

int32_t main()
{   sws
    memset(memo, -1, sizeof(memo));

    cin >> n >> k;


    for(int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        locks[x] = {true, i};
    }
    keys.pb(1);
    for(int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        keys.pb(x);
    }
    for(int i = 1; i <= n-1; i++)
    {
        int a,b,p;
        cin >> a >> b >> p;
        parent[b] = a;
        adj[a].pb({b,p});
    }
    dfs(1);
    keys.pb(n);
    process(n);
    for(int i = 0; i <= k+1; i++)
    {
        for(int j = i + 1; j <= k+1; j++)
        {
            int x = lca(keys[i], keys[j]);
            ances[i][j] = ances[j][i] = x;
            //cout << i << " " << j << ' ' << ances[i][j] << " ";
            //cout << dist(i,j) << "\n";
        }
    }
    //cout << endl;
    int ans = dp(0,0);
    if(ans == INF) ans = -1;
    cout << ans << endl;
    /*
    for(int i = 0; i <= k+1; i++)
    {
        for(int j = 0 ; j <= 15; j++)
        {
            cout << memo[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    return 0;
}