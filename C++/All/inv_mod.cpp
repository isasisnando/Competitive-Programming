#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int gcd(int a ,int b, int &x, int &y)
{
    x = 1;
    y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while(b1)
    {
        int q = a1/b1;

        tie(x,x1) = make_tuple(x1,x - q*x1);
        tie(y, y1) = make_tuple(y1, y - q*y1);
        tie(a1, b1) = make_tuple(b1, a1 - q*b1);
    }
    return a1;
}

int inverso(int a)
{
    int x,y;
    int g = gcd(a,MOD, x,y);
    if(g != 1) return -1;
    else
    {
        x = (x%MOD + MOD) % MOD;
    }
    return x;
}
