#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;
int v[MAX + 2];
int tree[4*MAX + 2];
 
int merge(int a, int b)
{
    return min(a,b);
}
void update(int idx, int x, int id , int il,int ir)
{
    if(il == ir)
    {
        tree[id] = x;
        //cout << "idx: " << idx << " update: " << x << endl;
        return;
    }
 
    int mid = (il + ir) / 2;
 
    if(mid < idx)
    {
        update(idx, x, 2*id+1, mid+1, ir);
    }
    else
    {
        update(idx, x, 2*id, il, mid);
    }
 
    tree[id] = merge(tree[2*id] , tree[2*id + 1]);
    //cout << "id: " << id << "update: " << tree[id] << endl;
    return;
 
 
}
void build(int id, int il, int ir)
{
    if(il == ir)
    {
        //Se os dois forem iguais, é ele msm 
        tree[id] = v[il];
        return;
    }
 
    //Calcular o meio dos dois e construir a árvore dos filhos
    int mid = (il + ir) / 2;
 
    build(2*id, il, mid);
    build(2*id + 1, mid + 1, ir);
 
    // ans vai ser o minimo desses dois filhos
 
    tree[id] = merge(tree[2*id], tree[2*id + 1]);
    return;
 
}
 
int query(int l, int r, int id, int il, int ir)
{
    //se tiver no range, retorna ele
    if(il >= l && ir <= r)
    {
        return tree[id];
    }
 
    if(l > ir || r < il) return 0;
 
    int mid = (il+ir) / 2;
    int left = query(l,r,2*id, il, mid);
    int right = query(l,r,2*id+1,mid + 1, ir);
 
    return merge(left ,right);
 
}
int32_t main()
{
    int N,Q;
    cin >> N >> Q;
    //cout << N << ' ' << Q << endl;
    ;
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    
    build(1, 0, N-1);
 
    
 
    for(int i = 0; i < Q; i++)
    {
        int y, l, r;
        cin >> y >> l >> r;
        l--;r--;
        if(y == 1)
        {
            int k = l;
            int x = r;
            v[k] = x;
            update(k,x,1,0,N-1);
        }
        else if(y == 2)
        {
            int ans = query(l,r,1,0,N-1);
            cout << ans << '\n';
        }
    }
 
 
    return 0;
}