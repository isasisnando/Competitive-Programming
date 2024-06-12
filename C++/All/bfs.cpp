#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define pb push_back
#define input(x) for (auto &it : x) cin >> it;
#define output(x) for (auto &it : x) cout << it << ' ';
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = 0x3f3f3f3f3f;
const long double PI = acos(-1);
int maximo = 1e5+10;
vector <vector<int>> adj(maximo);
vector <int> bfs(int s, int N)
{
    vector<int> dist(N+1, INF);
    queue <int> q;

    dist[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        auto u = q.front();
        q.pop();

        for(auto v : adj[u])
        {
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
int32_t main()
{   sws
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    int s,t;
    cin >> s >> t;
    vector <int> d;
    d = bfs(s, n);
    int ans = d[t];
    if(ans != INF) cout << "YES\n";
    else cout << "NO\n";  
    return 0;
}