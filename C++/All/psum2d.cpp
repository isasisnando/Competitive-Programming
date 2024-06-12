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
const int MAXN = 1000 + 5;
int bosque[MAXN][MAXN];
int psum[MAXN][MAXN];

int32_t main()
{   sws
    int n, q;
    cin >> n >> q;
    /*
    for(int i = 0; i <= n; i++)
    {
        psum[i][0] = 0;
        psum[0][i] = 0;
    }
    */
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if(c == '*')
            {
                bosque[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            psum[i][j] = bosque[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
            //cout << psum[i][j] << " ";
        }
        //cout << "\n";
    }

    for(int i = 0; i < q; i++)
    {
        int x1,y1,x2,y2;
        cin >> y1 >> x1 >> y2 >> x2;
        int ans = psum[y2][x2] - psum[y2][x1-1] - psum[y1-1][x2] + psum[y1-1][x1-1];
        cout << ans << "\n";
    }
    return 0;
}