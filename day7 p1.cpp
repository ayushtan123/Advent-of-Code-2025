#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// find the number of splits (number of ^ on which | falls)

int main(){
    fastIO();
    string s, prev="#";
    int split=0;

    while (getline(cin, s) && !s.empty()){
        if(prev=="#"){
            for(int i=0; i<s.size(); i++){
                if(s[i]=='S'){
                    s[i]='|';
                    break;
                }
            }
            prev=s;
            continue;
        }
        for(int i=0; i<s.length(); i++){
            if(s[i]=='.' && prev[i]=='|'){
                s[i]='|';
            }
            else if(s[i]=='^' && prev[i]=='|'){
                split++;

                int j=i-1;
                while(j>=0 && s[j]=='^'){
                    j--;
                }
                if(j>=0 && s[j]!='|'){
                    s[j]='|';
                }

                j=i+1;
                while(j<s.length() && s[j]=='^'){
                    j++;
                }
                if(j<s.length() && s[j]!='|'){
                    s[j]='|';
                }
            }
        }
        prev = s;
    }
    cout<<split;
    return 0;
}

/*
.......S.......
...............
.......^.......
...............
......^.^......
...............
.....^.^.^.....
...............
....^.^...^....
...............
...^.^...^.^...
...............
..^...^.....^..
...............
.^.^.^.^.^...^.
...............
*/
// ans = 21

// final ans = 1573
