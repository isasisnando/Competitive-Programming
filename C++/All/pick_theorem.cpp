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
typedef int cod;
struct point
{
    cod x,y;
    point(cod x = 0, cod y = 0): x(x), y(y)
    {}
 
    double modulo()
    {
        return sqrt(x*x + y*y);
    }
 
    point operator+(point o)
    {
        return point(x+o.x, y+o.y);
    }
    point operator-(point o)
    {
        return point(x - o.x , y - o.y);
    }
 
    cod operator^(point o)
    {
        return x*o.y - y * o.x;
    }
 
};
 
cod area(vector<point> v)
{
    int ans = 0;
    int aux = (int)v.size();
    for(int i = 2; i < aux; i++)
    {
        ans += ((v[i] - v[0])^(v[i-1] - v[0]));
    }
    ans = abs(ans);
    return ans;
}

int bound(point p1 , point p2)
{
    return __gcd(abs(p1.x-p2.x), abs(p1.y-p2.y));
}
int32_t main()
{   sws

    int n;
    cin >> n;

    vector<point> v;
    for(int i = 0; i < n; i++)
    {
        point p1;
        cin >> p1.x >> p1.y;
        v.pb(p1);
    }
    v.pb(v[0]);
    int b = 0;
    for(int i = 0; i < n; i++)
    {
        b += bound(v[i], v[i+1]);
    }

    cod A = area(v)/2; 
    ///teorema de pick
    int ans = A - (b/2) + 1;
    //cout << A << '\n';
    cout << ans << " " << b << '\n';

    return 0;
}