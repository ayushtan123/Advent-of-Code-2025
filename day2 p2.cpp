#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// FIND SUBSTRING PATTERN THAT REPEATS AT LEAST 2 TIMES

ll solve(ll l, ll r){
    ll val = 0;
    for (ll v=l; v<=r; v++){

        string d = to_string(v);
        int len = d.length();
        string pattern = "";
        bool found = false;

        for(int j=0; j<len/2; j++){
            pattern.push_back(d[j]);

            // check if pattern repeats comepletely and at least 2 times

            int cnt=1;
            bool pattternFound=true;
            for(int k=j+1; k<len; k+=j+1){
                if(d.substr(k, j + 1) == pattern){cnt++;}
                else{
                    pattternFound=false;
                    break;
                }
            }
            if(pattternFound && cnt>=2){
                found = true;
            }
            if(found) {break;}
        }
        if(found){
            val += v;
        }
    }
    return val;
}

int main()
{
    fastIO();
    string s;
    cin >> s;
    
    int i=0, n=s.length();
    ll ans=0;
    while(i<s.length()){
        string t1="";
        while(i<n && s[i]!='-'){
            t1+=s[i];
            i++;
        }
        i++;
        string t2="";
        while(i<n && s[i]!=','){
            t2+=s[i];
            i++;
        }
        i++;

        ans += solve(stoll(t1), stoll(t2));
    }
    cout<<ans;
    return 0;
}

/*
example:
11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124
*/

// ans=4174379265

// final ans: 45814076230