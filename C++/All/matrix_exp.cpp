#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define ff first
#define ss second
#define input(x) for (auto &it : x) cin >> it;
#define output(x) for (auto &it : x) cout << it << ' ';
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = 0x3f3f3f3f3f;
const long double PI = acos(-1);
const int MAX = 1e7+ 5;
const int MOD = 1e9 + 7;

struct Matrix {
    vector<vi> m;
    int r, c;

    Matrix(vector<vi> mat) {
        m = mat;
        r = mat.size();
        c = mat[0].size();
    }

    Matrix(int row, int col, bool ident=false) {
        r = row; c = col;
        m = vector<vi>(r, vi(c, 0));
        if(ident) {
            for(int i = 0; i < min(r, c); i++) {
                m[i][i] = 1;
            }
        }
    }

    Matrix operator*(const Matrix &o) const {
        assert(c == o.r); // garantir que da pra multiplicar
        vector<vi> res(r, vi(o.c, 0));

        for(int i = 0; i < r; i++) {
            for(int k = 0; k < c; k++) {
                for(int j = 0; j < o.c; j++) {
                    res[i][j] = (res[i][j] + m[i][k]*o.m[k][j]) % MOD;
                }
            }
        }

        return Matrix(res);
    }
};

Matrix fexp(Matrix b, int e, int n) {
    if(e == 0) return Matrix(n, n, true); // identidade
    Matrix res = fexp(b, e/2, n);
    res = (res * res);
    if(e%2) res = (res * b);

    return res;
}
void solve()
{
    int n;
    cin >> n;
    if(n == 0)
    {
        cout << 0 << "\n";
        return;
    }
    vector<vi> v = {{1LL, 1LL}, {1LL, 0LL}};
    Matrix m = Matrix(v);
    vvi aux = {{1LL}, {0LL}};
    Matrix b = Matrix(aux);

    m = fexp(m,n-1,2);
    m = m * b;
    cout << m.m[0][0] << "\n";
    return;
}
int32_t main()
{   sws

    int t;
    // cin >> t;
    t = 1;
    while(t--)solve();
    
    return 0;
}