#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int solve(vector<string>& grid, int& row){
    int i_access=0;
    string prev="", curr="", next="";

    vector<pair<int,int>> changes; // to store changes to be made

    for(int r=0; r<row; r++){
        prev = (r==0) ? "" : grid[r-1];
        curr = grid[r];
        next = (r==row-1) ? "" : grid[r+1];

        for(int i=0; i<curr.size(); i++){
            if(curr[i]=='.'){continue;}
            int cnt=0;
    
            if(r!=0){
                if(prev[i]=='@'){cnt++;}                        // up ngb
                if(i>=1 && prev[i-1]=='@'){cnt++;}
                if(i<curr.size()-1 && prev[i+1]=='@'){cnt++;}
            }

            if(i<curr.size()-1 && curr[i+1]=='@'){cnt++;}       // side ngb
            if(i>=1 && curr[i-1]=='@'){cnt++;}

            if(r!=row-1){
                if(next[i]=='@'){cnt++;}                        // down ngb
                if(i>=1 && next[i-1]=='@'){cnt++;}
                if(i<curr.size()-1 && next[i+1]=='@'){cnt++;}
            }

            if(cnt<4){
                i_access++;
                changes.push_back({r,i});            
            }
        }
    }
    for(auto& p : changes){
        grid[p.first][p.second] = '.';
    }
    return i_access;
}

int main(){
    fastIO();
    string s;
    
    vector<string> grid;
    // for every element in the grid, we need to check its 8 neighbours, i-1 and i+1 row
    // for second part, we need to store complete data
    // after one iteration, repeat the process until no more changes occur

    while (getline(cin, s) && !s.empty()){
        grid.push_back(s);
    }

    int access = 0, N=grid.size();
    while(true){
        int i_access = solve(grid, N);
        if(i_access==0){
            break;
        }
        access += i_access;
    }
    cout<<access;
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
// ans = 43

// final ans = 9144
// rows = 135 