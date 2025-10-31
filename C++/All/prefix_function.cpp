#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n,0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j-1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

void solve()
{
    string s;
    cin >> s;
    vi aux = prefix_function(s);
    vector<int> ans;
    int i = s.size()-1;
    int j = aux[i];

    while(j > 0)
    {
        ans.push_back(j);
        j = aux[j-1];
    }
    sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " ";
    cout <<"\n";
    return;
}
int32_t main()
{   sws

    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}