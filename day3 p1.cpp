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
    int joltage=0;
    
    while (getline(cin, s) && !s.empty()){
        char d1='0',d2='0';
        int idx=0;
        // find largest digit from 0 to n-2
        // second digit range from LD to n-1
        for(int i=0; i<s.size()-1; i++){
            if(s[i]>d1){
                d1=s[i];
                idx=i;
            }
        }
        for(int i=idx+1; i<s.size(); i++){
            if(s[i]>d2){
                d2=s[i];
            }
        }
        joltage += (d1 - '0') * 10 + (d2 - '0');
    }
    cout<<joltage;
    return 0;
}

/*
987654321111111
811111111111119
234234234234278
818181911112111
*/
// ans = 357

// final ans = 17359