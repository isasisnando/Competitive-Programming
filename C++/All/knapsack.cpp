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
const int MAX = 1010;
const int MOD = 1e9 + 7;

int dp[MAX][MAX], custo[MAX], valor[MAX];
int n, s;

int knap(int i, int c)
{
    if(c < 0) return -INF;
    if(i == n) return 0;

    if(dp[i][c] != -1) return dp[i][c];

    return dp[i][c] = max(knap(i+1, c - custo[i]) + valor[i], knap(i+1, c));
}

vector <int> path;
void recover(int i , int c)
{
    if( i == n) return;

    int pega = knap(i + 1, c - custo[i]) + valor[i];
    int npega = knap(i+1, c);
    if(pega >= npega)
    {
        path.pb(i);
        recover(i+1, c - custo[i]);
    }
    else
    {
        recover(i+1,c);
    }
}
int32_t main()
{   sws

    memset(dp,-1,sizeof(dp));
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        cin >> custo[i] >> valor[i];
    }

    recover(0,s);
    int peso = 0;
    for(int x : path)
    {
        peso += custo[x];
        cout << "Pega o valor " << valor[x] << " com peso " << custo[i] << "com idx " << x << "\n";
    }
    cout << "Pega " << path.size() << " itens com o peso total de " << peso << " e valor total de " << knap(0,s) << "\n";
    return 0;
}