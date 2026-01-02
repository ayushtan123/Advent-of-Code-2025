#include <bits/stdc++.h>
#define ll long long
using namespace std;
using namespace std::chrono;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// graph : number of ways to reach target node from a source node 
// optimized via DP and masking

unordered_map<string,map<int,ll>>dp;

ll dfs2(string node, int mask, unordered_map<string, vector<string>>& mp){
    if(node == "out"){
        return (mask==3);
    }

    if(dp[node].find(mask) != dp[node].end()){return dp[node][mask];}

    ll ways = 0;

    for(auto& ngb : mp[node]){
        int newMask = mask;
        
        if(ngb == "dac"){newMask = (newMask | 1);}
        else if(ngb == "fft"){newMask = (newMask | 2);}

        ways += dfs2(ngb,newMask,mp);
    }

    return dp[node][mask] = ways;
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

    auto start = high_resolution_clock::now();

    ll ans = dfs2("svr",0,mp);
    cout <<"Paths: "<< ans << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " ms";
    return 0;
}

/*
// this is different from part 1
svr: aaa bbb
aaa: fft
fft: ccc
bbb: tty
tty: ccc
ccc: ddd eee
ddd: hub
hub: fff
eee: dac
dac: fff
fff: ggg hhh
ggg: out
hhh: out
*/
// ans = 2

// Paths: 390108778818526
// Execution time : 12 ms (will wary always)