#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    fastIO();
    string next;
    string prev="", curr="";

    int row=0;
    int access=0;
    // for every element in the grid, we need to check its 8 neighbours, i-1 and i+1 row
    // at any time, we only need 3 rows in memory
    
    while (getline(cin, next) && !next.empty()){
        row++;
        if(row==2){  // process the (cnt-1) row
            // 5 neigbhbours
            for(int i=0; i<curr.size(); i++){
                if(curr[i]=='.'){continue;}
                int cnt=0;

                if(i<curr.size()-1 && curr[i+1]=='@'){cnt++;}    // side ngb
                if(i>=1 && curr[i-1]=='@'){cnt++;}

                if(next[i]=='@'){cnt++;}                        // down ngb
                if(i>=1 && next[i-1]=='@'){cnt++;}
                if(i<curr.size()-1 && next[i+1]=='@'){cnt++;}

                if(cnt<4){
                    access++;
                }
            }
        }
        else{
            for(int i=0; i<curr.size(); i++){
                if(curr[i]=='.'){continue;}
                int cnt=0;

                if(prev[i]=='@'){cnt++;}                        // up ngb
                if(i>=1 && prev[i-1]=='@'){cnt++;}
                if(i<curr.size()-1 && prev[i+1]=='@'){cnt++;}

                if(i<curr.size()-1 && curr[i+1]=='@'){cnt++;}   // side ngb
                if(i>=1 && curr[i-1]=='@'){cnt++;}

                if(next[i]=='@'){cnt++;}                        // down ngb
                if(i>=1 && next[i-1]=='@'){cnt++;}
                if(i<curr.size()-1 && next[i+1]=='@'){cnt++;}

                if(cnt<4){
                    access++;
                }
            }
        }
        prev=curr;
        curr=next;
    }
    // process the last row
    for(int i=0; i<curr.size(); i++){
        if(curr[i]=='.'){continue;}
        int cnt=0;

        if(i<curr.size()-1 && curr[i+1]=='@'){cnt++;}    // side ngb
        if(i>=1 && curr[i-1]=='@'){cnt++;}

        if(prev[i]=='@'){cnt++;}                        // up ngb
        if(i>=1 && prev[i-1]=='@'){cnt++;}
        if(i<curr.size()-1 && prev[i+1]=='@'){cnt++;}

        if(cnt<4){
            access++;
        }
    }
    cout<<access<<endl;
    cout<<row;
    return 0;
}

/*
..@@.@@@@.
@@@.@.@.@@
@@@@@.@.@@
@.@@@@..@.
@@.@@@@.@@
.@@@@@@@.@
.@.@.@.@@@
@.@@@.@@@@
.@@@@@@@@.
@.@.@@@.@.
*/
// ans = 13

// final ans = 1367
// rows = 135 