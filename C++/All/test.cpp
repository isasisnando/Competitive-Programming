#include <bits/stdc++.h>

#define int long long
using namespace std;
#define ff first
#define ss second

bool aprov(string ans1, string ans2)
{
    if((int)ans1.size() == (int)ans2.size())
    {
        bool eh = true;
        for(int k = 0; k < (int)ans1.size(); k++)
        {
            if(ans1[k] != ans2[k])
            {
                eh = false;
            }
        }
        if(eh)
        {
            cout << "Aprovado\n";
            return true;
        }
    }
    return false;
}
int32_t main()
{
    int n;
    cin >> n;
    vector <pair<string,string>> v(n);

    for(int i = 0 ; i < n; i++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        v[i].first = s1;
        v[i].second = s2;
    }
    bool resp = false;
    string ans1 = "";
    string ans2 = "";
    int cnt = 0;
    vector <bool> vis(n, false);
    for(int i1 = 0; i1 < n; i1++)
    {
        cnt = 1;
        if(cnt > n)break;
        ans1 = v[i1].first;
        ans2 = v[i1].second;
        bool eh = aprov(ans1, ans2);
        if(eh)
        {
            cout << cnt << '\n';
            cout << i1 +1 << "\n";
            return 0;
        }
        for(int i2 = 0; i2 < n; i2++)
        {
            for(int aux = 0; aux < n; aux++) vis[aux] = false;
            vis[i1] = true;
            cnt = 2;
            if(cnt > n) break;
            if(vis[i2]) continue;
            ans1 = v[i1].first + v[i2].first;
            ans2 = v[i1].second + v[i2].second;
            bool eh = aprov(ans1, ans2);
            if(eh)
            {
                cout << cnt << '\n';
                cout << i1 +1<< " " << i2+1 << "\n";
                return 0;
            }
            for(int i3 = 0; i3 < n; i3++)
            {
                for(int aux = 0; aux < n; aux++) vis[aux] = false;
                vis[i1] = vis[i2] = true;
                cnt = 3;
                if(cnt > n) break;
                if(vis[i3]) continue;
                ans1 = v[i1].first + v[i2].first + v[i3].ff ;
                ans2 = v[i1].second + v[i2].second + v[i3].ss;
                bool eh = aprov(ans1, ans2);
                if(eh)
                {
                    cout << cnt << '\n';
                    cout << i1+1 << " " << i2+1 << " " << i3 +1<< "\n";
                    return 0;
                }
                for(int i4 = 0; i4 < n; i4++)
                {
                    for(int aux = 0; aux < n; aux++) vis[aux] = false;
                    vis[i1] = vis[i2] = vis[i3] = true;
                    cnt = 4;
                    if(cnt > n) break;
                    if(vis[i4])continue;
                    ans1 = v[i1].first + v[i2].first + v[i3].ff + v[i4].ff;
                    ans2 = v[i1].second + v[i2].second + v[i3].ss + v[i4].ss;
                    bool eh = aprov(ans1, ans2);
                    if(eh)
                    {
                        cout << cnt << '\n';
                        cout << i1+1 << " " << i2 +1 << " " << i3+1 << " " << i4+1 << "\n";
                        return 0;
                    }
                    for(int i5 = 0; i5 < n; i5++)
                    {
                        for(int aux = 0; aux < n; aux++) vis[aux] = false;
                        vis[i1] = vis[i2] = vis[i3] = vis[i4] = true;
                        cnt = 5;
                        if(cnt > n) break;
                        if(vis[i5] ) continue;
                        ans1 = v[i1].first + v[i2].first + v[i3].ff + v[i4].ff + v[i5].ff;
                        ans2 = v[i1].second + v[i2].second + v[i3].ss + v[i4].ss + v[i5].ss;
                        bool eh = aprov(ans1, ans2);
                        if(eh)
                        {
                            cout << cnt << '\n';
                            cout << i1+1 << " " << i2+1 << " " << i3+1 << " " << i4 +1 << " " << i5+1 << "\n";
                            return 0;
                        }
                        for(int i6 = 0; i6 < n; i6++)
                        {
                            for(int aux = 0; aux < n; aux++) vis[aux] = false;
                            vis[i1] = vis[i2] = vis[i3] = vis[i4] = vis[i5] = true;
                            cnt = 6;
                            if(cnt > n ) break;
                            if(vis[i6])continue;
                            ans1 = v[i1].first + v[i2].first + v[i3].ff + v[i4].ff + v[i5].ff + v[i6].ff;
                            ans2 = v[i1].second + v[i2].second + v[i3].ss + v[i4].ss + v[i5].ss + v[i6].ss;
                            bool eh = aprov(ans1, ans2);
                            if(eh)
                            {
                                cout << cnt << '\n';
                                cout << i1+1 << " " << i2+1 << " " << i3 +1 << " " << i4+1 << " "<< i5+1  << " " << i6+1 << "\n";
                                return 0;
                            }
                            for(int i7 = 0; i7 < n; i7++)
                            {
                                for(int aux = 0; aux < n; aux++) vis[aux] = false;
                                vis[i1] = vis[i2] = vis[i3] = vis[i4] = vis[i5] = vis[i6] = true;
                                cnt = 7;
                                if(cnt > n) break;
                                if(vis[i7])continue;
                                ans1 = v[i1].first + v[i2].first + v[i3].ff + v[i4].ff + v[i5].ff + v[i6].ff + v[i7].ff;
                                ans2 = v[i1].second + v[i2].second + v[i3].ss + v[i4].ss + v[i5].ss + v[i6].ss + v[i7].ss;
                                bool eh = aprov(ans1, ans2);
                                if(eh)
                                {
                                    cout << cnt << '\n';
                                    cout << i1 +1 << " " << i2+1 << " " << i3 +1<< " " << i4+1 << " "  << i5 +1 << " " << i6 +1 << " " << i7 +1<< "\n";
                                    return 0;
                                }
                                for(int i8 = 0; i8 < 8; i8++)
                                {
                                    for(int aux = 0; aux < n; aux++) vis[aux] = false;
                                    vis[i1] = vis[i2] = vis[i3] = vis[i4] = vis[i5] = vis[i6] = vis[i7] = true;
                                    cnt = 8;
                                    if(cnt > n) break;
                                    if(vis[i8])continue;
                                    ans1 = v[i1].first + v[i2].first + v[i3].ff + v[i4].ff + v[i5].ff + v[i6].ff + v[i7].ff + v[i8].ff;
                                    ans2 = v[i1].second + v[i2].second + v[i3].ss + v[i4].ss + v[i5].ss + v[i6].ss + v[i7].ss + v[i8].ss;
                                    bool eh = aprov(ans1, ans2);
                                    if(eh)
                                    {
                                        cout << cnt << '\n';
                                        cout << i1 +1 << " " << i2 +1 << " " << i3+1 << " " << i4+1 << " " << i5+1  << " " << i6 +1 << " " << i7 +1 << " " << i8+1 << "\n";
                                        return 0;
                                    }
                                }
                            }
                        }
                        
                    }
                }
            }
  
        }
 
    }

    cout << "Reprovado\n";
 
  return 0;
}