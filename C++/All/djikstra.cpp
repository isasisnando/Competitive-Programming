#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
const int INF = 0x3f3f3f3f;
#define pii pair<int,int>
vector<vector<pii>> adj(maxn);

vector<int> djikstra(int ini)
{
    vector<int> distance(maxn, INF);
    vector<bool> vis(maxn, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    distance[ini] = 0;
    pq.push({0,ini});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;

        for(auto aux : adj[u])
        {
            int v = aux.first;
            int custo = aux.second;

            if(distance[v] > distance[u] + custo)
            {
                distance[v] = distance[u] + custo;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    vector <int> d = djikstra(1);

    for(int i = 1; i <= n; i++)
    {
        cout << "distancia ate " << i << " e: " << d[i] << endl;
    }
    return 0;
}