#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// here first merge all ID ranges and then for each query, check if it lies in any of the merged ranges

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
    int query_count=0;

    // binary search for each query
    while (getline(cin, s) && !s.empty()){
        query_count++;
        ll q = stoll(s);
        int l=0, h=data.size()-1;

        while(l<=h){
            int mid = l + (h-l)/2;
            if(data[mid].first <= q && data[mid].second >= q){
                fresh++;
                break;
            }
            else if(data[mid].first > q){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

    }
    cout<<fresh<<"\n";
    cout<<query_count;
    return 0;
}

/*
3-5
10-14
16-20
12-18

1
5
8
11
17
32
*/
// ans = 3

// final ans = 601
// queries = 1000
