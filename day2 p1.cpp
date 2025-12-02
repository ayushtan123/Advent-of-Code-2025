#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll solve(ll l, ll r){
    ll val=0;
    for(ll v=l; v<=r; v++){
        string d=to_string(v); int len=d.length();
        if(len%2!=0) continue;

        string first=d.substr(0,len/2);
        string second=d.substr(len/2);  
         
        if(first==second){
            val += v;
        }
    }
    return val;
}

int main()
{
    fastIO();
    string s;
    cin>>s;
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
11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124
*/

// final ans: 35367539282