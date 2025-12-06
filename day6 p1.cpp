#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    fastIO();
    string s;
    vector<vector<int>>data;
    vector<char>ops;
    string t;
    
    while (getline(cin, s) && !s.empty()){
        t=s;    // store the last line separately

        stringstream ss(s);
        vector<int> r;
        int num;

        while(ss >> num){
            r.push_back(num);
        }

        if(r.empty()) continue;
        data.push_back(r);
    }

    cout<<"Read "<<data.size()<<" rows and "<<data[0].size()<<" columns\n";

    for(char& ch:t){
        if(ch=='+' || ch=='*'){
            ops.push_back(ch);
        }
    }
    cout<<ops.size()<<" operations read\n";
    
    ll ans=0;
    for(int j=0; j<ops.size(); j++){
        ll curr;
        if(ops[j]=='+'){
            curr=0;
            for(int i=0; i<data.size(); i++){
                curr += data[i][j]*1LL;
            }
        }
        else{
            curr = 1;
            for(int i=0; i<data.size(); i++){
                curr *= data[i][j]*1LL;
            }
        }
        ans += curr;
    }
    cout<<ans;
    return 0;
}

/*
123 328  51 64
 45 64  387 23
  6 98  215 314
*   +   *   +
*/
// ans = 4277556

// final ans = 3968933219902
