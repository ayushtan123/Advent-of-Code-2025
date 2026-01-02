#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// graph : number of ways to reach target node from a source node

ll dfs(string node, unordered_map<string, vector<string>>& mp, unordered_set<string>& vis){
    if(node == "out"){
        return 1;
    }

    vis.insert(node);
    ll a = 0;

    for(auto& ngb : mp[node]){
        if(vis.count(ngb)==0){
            a += dfs(ngb,mp,vis);
        }
    }

    vis.erase(node);
    return a;
}

int main(){
    fastIO();
    string s;

    // all nodes length are same : 3
    unordered_map<string, vector<string>> mp;

    while(getline(cin, s) && !s.empty()){
        string device1 = s.substr(0,3);

        int i=5;
        while(i<s.length()){
            string device2 = s.substr(i,3);
            mp[device1].push_back(device2);
            i += 4;
        }
    }

    // for(auto it:mp){
    //     cout<<it.first<<" ";
    //     for(auto t:it.second){cout<<t<<" ";}
    //     cout<<endl;
    // }

    unordered_set<string>vis;
    ll ans = dfs("you",mp,vis);
    cout << ans;
    return 0;
}

/*
aaa: you hhh
you: bbb ccc
bbb: ddd eee
ccc: ddd eee fff
ddd: ggg
eee: out
fff: out
ggg: out
hhh: ccc fff iii
iii: out
*/
// ans = 5

// final ans = 701