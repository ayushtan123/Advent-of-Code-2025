#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

string toggleIndicator(vector<int>&A, string& t){
    string ans = t;
    for(int x:A){
        ans[x] = (ans[x]=='.') ? '#' : '.';
    }
    return ans;
}

ll solve(int idx, string t, vector<vector<int>> &buttons, string &state){
    if(t == state){return 0;}
    if(idx == buttons.size()){
        return INT_MAX;
    }
    ll press=INT_MAX;
    for(int j=idx; j<buttons.size(); j++){
        string tS = toggleIndicator(buttons[j], t);
        press = min(press, 1 + solve(j+1, tS, buttons, state));
    }
    return press;
}
// subsequence of buttons to be used

int main(){
    fastIO();
    string s;
    ll ans=0;

    while(getline(cin, s) && !s.empty()){
        vector<vector<int>> buttons;
        string state = "";

        int i=1, n=s.length();
        while(s[i]!=']'){
            state.push_back(s[i++]);
        }
        i+=2;

        while(s[i]!='{'){
            if(s[i]=='(' || s[i]==' '){i++; continue;}

            int num=0;
            vector<int>A;
            while(s[i]!=')'){
                num=num*10 + (s[i++]-'0');
                if(s[i] == ','){
                    // cout<<num<<endl;
                    A.push_back(num);
                    num=0;
                    i++;
                }
            }
            // cout<<num<<"*"<<endl;
            A.push_back(num);
            buttons.push_back(A);
            i++;
        }
        string t = string(state.size(),'.');
        ll val = solve(0, t, buttons, state);
        // cout<<val<<endl;
        ans += val;
    }
    cout<<ans;
    return 0;
}

/*
[.##.] (3) (1,3) (2) (2,3) (0,2) (0,1) {3,5,4,7}
[...#.] (0,2,3,4) (2,3) (0,4) (0,1,2) (1,2,3,4) {7,5,12,7,2}
[.###.#] (0,1,2,3,4) (0,3,4) (0,1,2,4,5) (1,2) {10,11,11,5,10,5}
*/

// ans = 7

// final ans = 550