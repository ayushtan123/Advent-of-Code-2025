#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// part 2
// here find total number of fresh ingredients from all merged intervals
// input is only ranges, not queries

void mergeIntervals(vector<pair<ll, ll>>& vp){
    sort(begin(vp), end(vp));
    vector<pair<ll,ll>> res;
    
    for(auto& p:vp){
        if(res.empty() || (res.back().second < p.first)){
            res.push_back(p);
        }
        else{
            if(res.back().second < p.second){
                res.back().second = p.second;
            }
        }
    }
    vp = res;
}

int main(){
    fastIO();
    string s;
    vector<pair<ll,ll>> data;
    
    while (getline(cin, s) && !s.empty()){
        ll a=0, b=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='-'){
                a = stoll(s.substr(0,i));
                b = stoll(s.substr(i+1));
            }
        }
        data.push_back({a,b});
    }

    mergeIntervals(data);

    ll fresh=0;
    for(auto& p:data){
        fresh += (p.second - p.first + 1LL);
    }
    
    cout<<fresh;
    return 0;
}

/*
3-5
10-14
16-20
12-18
*/
// ans = 14

// final ans = 367899984917516
