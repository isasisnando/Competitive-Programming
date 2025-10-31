#include<bits/stdc++.h>
 
using namespace std;
 
int nxt(string& p, vector<int>& nbor, int lider, char c)
{
    while(lider != -1)
    {
        if((p[lider + 1] == c) && (lider+1 < p.size()))
        {
            lider++;
            break;
        }
        else
        {
            lider = nbor[lider];
        }
    }
    if(lider == -1 && p[0] == c)
    {
       lider++;
    }
 
    return lider;
 
}
 
vector <int> kmp(string p)
{
    int n = p.size();
    vector<int> nbor(n+1);
 
    nbor[0] = -1;
 
    for(int i = 1; i < n; i++)
    {
        nbor[i] = nbor[i-1];
        nbor[i] = nxt(p, nbor, nbor[i], p[i]);
    }
 
    return nbor;
}
 
int main()
{
    string p,s;
    cin >> s >> p;
 
    int aux = -1;
 
    vector <int> nbor = kmp(p);
 
    int matching = 0;
 
    for(int  i = 0; i < s.size(); i++)
    {
        aux = nxt(p, nbor, aux, s[i]);
        if(aux == (p.size() - 1))
        {
            matching++;
        }
    }
 
    cout << matching << endl;
 
 
 
    return 0;
}