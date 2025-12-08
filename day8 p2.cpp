#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int Find(int x, vector<int>& parent){
    if(parent[x] == x){return x;}
    return Find(parent[x], parent);
}

typedef pair<ll,pair<int,int>> plp;

ll solve(vector<vector<ll>>& v){
    int N=v.size();
    // int threshold = (N==1000) ? 1000 : 11;
    set<plp>st;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){

            ll x2 = (v[i][0]-v[j][0])*(v[i][0]-v[j][0]);
            ll y2 = (v[i][1]-v[j][1])*(v[i][1]-v[j][1]);
            ll z2 = (v[i][2]-v[j][2])*(v[i][2]-v[j][2]);

            ll dis = x2 + y2 + z2;
            st.insert({dis, {i,j}});
        }
    }
    cout<<st.size()<<" pairs"<<endl;

    vector<int>parent(N,0), rank(N,0);      // DSU
    for(int i=0; i<N; i++){
        parent[i]=i;
    }

    int cnt=0;

    for(auto&it: st){
        int i=it.second.first, j=it.second.second;
        int pi = Find(i,parent), pj = Find(j, parent);

        if(rank[pi] >= rank[pj]){
            parent[pj] = pi;
            rank[pi]++;
        }
        else{
            parent[pi] = pj;
            rank[pj]++;
        }
        cnt++;

        int baap = Find(0,parent);
        for(int i=1; i<N; i++){
            // find parent in DSU by Find(x)
            if(baap != Find(i,parent)){
                baap = -1;
                break;
            }
        }
        if(baap != -1){
            cout<<cnt<<" connections"<<endl;
            cout<<v[i][0]<<" "<<v[j][0]<<endl;
            return v[i][0]*v[j][0];
        }
    }
    return -1;
}

int main(){
    fastIO();
    string s;
    vector<vector<ll>>v;

    while (getline(cin, s) && !s.empty()){
        ll x=0,y=0,z=0, i=0;
        while(s[i]!=','){
            x=x*10+(s[i]-'0');
            i++;
        }
        i++;
        while(s[i]!=','){
            y=y*10+(s[i]-'0');
            i++;
        }
        i++;
        while(i<s.length()){
            z=z*10+(s[i]-'0');
            i++;
        }
        // cout<<x<<" "<<y<<" "<<z<<endl;
        v.push_back({x,y,z}); 
    }
    cout<<solve(v);
    return 0;
}

/*
162,817,812
57,618,57
906,360,560
592,479,940
352,342,300
466,668,158
542,29,236
431,825,988
739,650,466
52,470,668
216,146,977
819,987,18
117,168,530
805,96,715
346,949,466
970,615,88
941,993,340
862,61,35
984,92,344
425,690,689
*/

// 190 pairs
// 29 connections
// 216 117
// ans = 25272

// 499500 pairs
// 5943 connections
// 14332 3108
// final ans = 44543856