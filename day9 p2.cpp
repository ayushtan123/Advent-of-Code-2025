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
            ll minX = min(v[i].first, v[j].first);
            ll maxX = max(v[i].first, v[j].first);

            ll minY = min(v[i].second, v[j].second);
            ll maxY = max(v[i].second, v[j].second);

            // every point should lie inside closed polygon formed

            bool flag = true;

            for(int k=0; k<N; k++){
                ll cx = v[k].first, cy = v[k].second;
                ll nx = v[(k+1)%N].first, ny = v[(k+1)%N].second;
                // In your list, every red tile is connected to the red tile 
                /// before and after it by a straight line of green tiles. 
                // The list wraps, so the first red tile is also connected to the last red tile.

                if(!(minX >= max(cx,nx) || maxX <= min(cx,nx) || minY >= max(cy,ny) || maxY <= min(cy,ny))){
                    flag=false;
                    break;
                }
            }

            if(flag){
                ll x = abs(v[i].first - v[j].first) + 1;
                ll y = abs(v[i].second - v[j].second) + 1;
                ll curr = x * y;
                if (curr > area){
                    area = curr;
                }
            }

        }
    }
    return area;
}

int main(){
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
    // order of tiles is important, in that order green tiles are wrapped
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
// ans = 24

// final ans = 4735222687