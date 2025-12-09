#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
ll solve(vector<pair<ll, ll>>& v){
    ll area=0;
    int N=v.size();
    cout<<N<<endl;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            ll x = abs(v[i].first-v[j].first)+1;
            ll y = abs(v[i].second-v[j].second)+1;
            ll curr = x*y;
            if(curr > area){
                area = curr;
            }
        }
    }
    return area;
}

    int main()
{
    fastIO();
    string s;
    vector<pair<ll,ll>>v;

    while (getline(cin, s) && !s.empty()){
        ll x=0, y=0, i=0;

        while(s[i]!=','){
            x=x*10+(s[i]-'0');
            i++;
        }
        i++;
        while(i<s.length()){
            y=y*10+(s[i]-'0');
            i++;
        }
        v.push_back({x,y});
    }
    cout<<solve(v);
    return 0;
}

/*
7,1
11,1
11,7
9,7
9,5
2,5
2,3
7,3
*/
// ans = 50

// final ans = 4735222687