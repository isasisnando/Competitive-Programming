#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


const int MAX = 2e5 + 2; 
const int INF = 0x3f3f3f3f;


vector <int> lazy(4*MAX, 0);
int tree[4*MAX], v[MAX];
int N;

int merge(int a, int b)
{
    return a + b;
}

void build(int l, int r, int id)
{
    if(l==r)
    {
        tree[id] = v[l];
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*id);
    build(mid+1, r, 2*id+1);

    tree[id] = merge(tree[2*id], tree[2*id+1]);
}

void prop(int l, int r, int id)
{
    if(lazy[id]!=0)
    {
        tree[id] += (r-l+1)*lazy[id];
        if(l!=r)
        {
            lazy[2*id] += lazy[id] ;
            lazy[2*id+1] += lazy[id];
        }
        lazy[id] = 0;
    }
}

void update(int A, int B, int x, int l=0, int r=N-1, int id=1)
{
    prop(l, r, id);
    // 1º caso
    if(B<l or r<A) return;
    // 2º caso
    if(A<=l and r<=B)
    {
        lazy[id] += x;
        prop(l, r, id);
        return;
    }
    // 3º caso
    int mid = (l+r)/2;

    update(A, B, x, l, mid, 2*id);
    update(A, B, x, mid+1, r, 2*id+1);
    
    tree[id] = merge(tree[2*id], tree[2*id+1]);
}

int query(int A, int B, int l=0, int r=N-1, int id=1)
{
    prop(l, r, id);
    // 1º caso
    if(B<l or r<A) return 0;
    // 2º caso
    if(A<=l and r<=B) return tree[id];
    // 3º caso
    int mid = (l+r)/2;

    return merge(query(A, B, l, mid, 2*id),query(A, B, mid+1, r, 2*id+1));
}


int32_t main()
{
    sws;

    int Q, op, a, b, idx, x;
    cin >> N >> Q;
    for(int i=0;i<N;i++)
    {
        cin >> v[i];
    }

    build(0,N-1,1);

    for(int i=0;i<Q;i++)
    {
        cin >> op;
        if(op==1)
        { // update
            cin >> a >> b >> x;
            a--;b--;
            update(a, b, x);
            
            
        }
        else
        { // query
            cin >> idx ;
            idx--; // indice indexado em 0
            cout << query(idx, idx) << endl;
            
        }
    }

    return 0;
}