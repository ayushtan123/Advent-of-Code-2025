#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// find the number of splits (number of ^ on which | falls)
// tNote: there is no ^^ case (suprising)

vector<vector<ll>>dp;
ll solve(int i, int j, vector<vector<char>>& data){
    if(i==data.size()-1){    // last row
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    ll result=0;
    if(data[i][j]=='^'){
        ll left = (j>=1) ? solve(i,j-1,data) : 0;
        ll right = (j+1<data[0].size()) ? solve(i,j+1,data) : 0;
        result = left+right;
    }
    else if(data[i][j] == '.'){
        result = solve(i+1,j,data);
    }

    return dp[i][j] = result;
}

int main(){
    fastIO();
    string s;
    
    vector<vector<char>>data;
    int idx=-1;

    while (getline(cin, s) && !s.empty()){
        vector<char>t;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='S'){
                idx=i;
                s[i]= '.';
            }
            t.push_back(s[i]);
        }
        data.push_back(t);
    }

    dp.resize(data.size(), vector<ll>(data[0].size(), -1LL));
    ll ans = solve(0, idx, data);
    cout<<ans;
    return 0;
}

/*
.......S.......
...............
.......^.......
...............
......^.^......
...............
.....^.^.^.....
...............
....^.^...^....
...............
...^.^...^.^...
...............
..^...^.....^..
...............
.^.^.^.^.^...^.
...............
*/
// ans = 40
// final ans = 15093663987272
