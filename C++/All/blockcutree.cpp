#include <bits/stdc++.h>

using namespace std;
#define int long long
// Block-Cut Tree do brunomaletta
// art[i] responde o numero de novas componentes conexas
// criadas apos a remocao de i do grafo g
// Se art[i] >= 1, i eh ponto de articulacao
// 
// Para todo i <= blocks.size()
// blocks[i] eh uma componente 2-vertce-conexa maximal
// edgblocks[i] sao as arestas do bloco i
// tree[i] eh um vertice da arvore que corresponde ao bloco i
// 
// pos[i] responde a qual vertice da arvore vertice i pertence
// Arvore tem no maximo 2n vertices
const int MAXN = 5e5+2;
struct block_cut_tree {
    vector<vector<int>> g, blocks, tree;
    vector<vector<pair<int, int>>> edgblocks;
    stack<int> s;
    stack<pair<int, int>> s2;
    vector<int> id, art, pos;
    
    block_cut_tree(vector<vector<int>> g_) : g(g_) {
        int n = g.size();
        id.resize(n, -1), art.resize(n), pos.resize(n);
        build();
    }

    int dfs(int i, int& t, int p = -1) {
        int lo = id[i] = t++;
        s.push(i);  
        
        if (p != -1) s2.emplace(i, p);
        for (int j : g[i]) if (j != p and id[j] != -1) s2.emplace(i, j);
        
        for (int j : g[i]) if (j != p) {
            if (id[j] == -1) {
                int val = dfs(j, t, i);
                lo = min(lo, val);

                if (val >= id[i]) {
                    art[i]++;
                    blocks.emplace_back(1, i);
                    while (blocks.back().back() != j) 
                        blocks.back().push_back(s.top()), s.pop();

                    edgblocks.emplace_back(1, s2.top()), s2.pop();
                    while (edgblocks.back().back() != pair(j, i))
                        edgblocks.back().push_back(s2.top()), s2.pop();
                }
                // if (val > id[i]) aresta i-j eh ponte
            }
            else lo = min(lo, id[j]);
        }
        
        if (p == -1 and art[i]) art[i]--;
        return lo;
    }

    void build() {
        int t = 0;
        for (int i = 0; i < g.size(); i++) if (id[i] == -1) dfs(i, t, -1);
        
        tree.resize(blocks.size());
        for (int i = 0; i < g.size(); i++) if (art[i]) 
            pos[i] = tree.size(), tree.emplace_back();

        
        for (int i = 0; i < blocks.size(); i++) for (int j : blocks[i]) {
            if (!art[j]) pos[j] = i;
            else tree[i].push_back(pos[j]), tree[pos[j]].push_back(i);
        }
    }
};

int ans = 1e12;
int u,v;
bool vis[MAXN];
bool ar[2*MAXN];
// void dfs(int no, int cnt, block_cut_tree T)
// {
//     // cout << no << ' ' << cnt << "\n"; 
//     vis[no] = 1;
//     if(T.pos[v] == no)
//     {
//         ans = cnt;
//     }
//     for(auto viz : T.tree[no])
//     {
//         if(vis[viz]) continue;
//         dfs(viz,(ar[viz]? cnt :cnt+1),T);
//     }
//     return;

// }
int32_t main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    for(int i = 1; i <= m; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    block_cut_tree tree(g);
    cin >> u >> v;
    u--; v--;
    if (tree.pos[u] == tree.pos[v])
    {
        cout << 2 << endl;
        return 0;
    }
    // cout << endl;
    for(int i = 0; i < n; i++) ar[tree.pos[i]] = (tree.art[i] >= 1? 1 : 0);
    auto dfs = [&](auto rec, int no, int cnt) {
        if(vis[no])return;
        vis[no] = 1;
        if (tree.pos[v] == no) {
            ans = cnt;
        }
        for (auto viz : tree.tree[no]) {
            if (vis[viz]) continue;
            rec(rec, viz, (ar[viz] ? cnt : cnt + 1));
        }
        return;
    };
    dfs(dfs, tree.pos[u],0);
    ans++;
    ans += (tree.art[u]? 0 : 1);
    cout << ans << '\n';

    // cout << endl;
    // for(int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     cout << tree.blocks[i].size() << endl;
    //     //cout << tree.id[i] << ' ' << tree.art[i] << "\n";
    //     for(auto x : tree.tree[i])cout<<x << " ";
    //     cout << endl;
    // }
    return 0;
}