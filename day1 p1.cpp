#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    fastIO();
    int pos=50;
    int ans=0;
    string s;
    
    while (getline(cin, s) && !s.empty()){
        char move = s[0];
        int step = stoi(s.substr(1));

        if (move == 'R'){
            pos = (pos + step) % 100;
        }
        else{
            pos = (pos - step + 100) % 100;
        }
        if(pos==0){ 
            // the actual password is the number of times 
            // the dial is pointing at 0 after any rotation in the sequence.
            ans++;
        }
    }
    cout<<ans;
    return 0;
}