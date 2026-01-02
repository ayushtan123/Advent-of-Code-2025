#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<string> rotate90(vector<string>& g) {
    vector<string> res(3, string(3, '.'));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res[j][2 - i] = g[i][j];
        }
    }
    return res;
}

// horizontal flip (left-right)
vector<string> flipH(vector<string>& g) {
    vector<string> res = g;
    for (int i = 0; i < 3; i++) {
        reverse(res[i].begin(), res[i].end());
    }
    return res;
}

// vertical flip (top-bottom)
vector<string> flipV(vector<string>& g) {
    vector<string> res = g;
    reverse(res.begin(), res.end());
    return res;
}

vector<pair<int,int>> extractHash(vector<string>& g) {
    vector<pair<int,int>> coords;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (g[i][j] == '#') {
                coords.push_back({i, j});
            }
        }
    }
    return coords;
}

vector<vector<pair<int,int>>> rotateAndFlip(vector<string>& g){

    set<vector<pair<int,int>>> variants;

    // original rotations
    vector<string> cur = g;
    for (int i = 0; i < 4; i++) {
        variants.insert(extractHash(cur));
        cur = rotate90(cur);
    }

    // horizontal flip + rotations
    cur = flipH(g);
    for (int i = 0; i < 4; i++) {
        variants.insert(extractHash(cur));
        cur = rotate90(cur);
    }

    // vertical flip + rotations
    cur = flipV(g);
    for (int i = 0; i < 4; i++) {
        variants.insert(extractHash(cur));
        cur = rotate90(cur);
    }

    // result
    // cout << variants.size() << "\n";
    // for (auto &v : variants) {
    //     for (auto &row : v) cout << row << "\n";
    //     cout << "\n";
    // }

    vector<vector<pair<int,int>>>ans;
    for(auto& v: variants){
        ans.push_back(v);
    }
    return ans;
}

string createKey(int& x, int& y){
    return to_string(x) + "#" + to_string(y);
}

vector<vector<vector<pair<int, int>>>> book;

bool solve(int k, int& x, int& y, vector<int>& freq, unordered_set<string>& st){
    if (k == 6) return true;

    if (freq[k] == 0)
        return solve(k + 1, x, y, freq, st);

    for (auto& t : book[k]) {   // O(10)

        for (int i = 0; i <= y-3; i++) {
            for (int j = 0; j <= x-3; j++) {
                
                if(st.find(createKey(i,j)) != st.end()){continue;}

                bool flag = true;
                vector<string> placed;

                for (auto& p : t) {             // O(9)
                    int nx = i + p.first;
                    int ny = j + p.second;

                    string cd = createKey(nx, ny);

                    // boundary check
                    if (nx < 0 || nx >= x || ny < 0 || ny >= y || st.count(cd)){
                        flag = false;
                        break;
                    }
                    placed.push_back(cd);
                }

                if(!flag){continue;}

                // place
                for(auto& q : placed){st.insert(q);}
                freq[k]--;

                
                if(solve(k, x, y, freq, st)){return true;}
                

                // undo
                freq[k]++;
                for(auto& q : placed){st.erase(q);}
            }
        }
    }
    return false;
}


int main(){
    fastIO();
    string s;

    int idx=0;
    vector<vector<string>>v;
    vector<string>curr;

    ll regions = 0;

    while(getline(cin,s)){
        if(s.empty()){
            idx++;
            if(idx == 6){                 // can be changed
                book.push_back(rotateAndFlip(curr));
                v.push_back(curr);
                break;
            }
            continue;
        }
        
        if(isdigit(s[0])){
            if(!curr.empty()){
                book.push_back(rotateAndFlip(curr));
                v.push_back(curr);
            }
            curr = {};
            continue;
        }
        curr.push_back(s);
    }


    // for(auto j : book){
    //     cout<<j.size()<<endl;
    // }   // 8 8 2 4 4 2

    vector<pair<int,int>>rsize;
    vector<vector<int>> freq;

    while(getline(cin,s) && !s.empty()){
        int i=0;
        int s1=0, s2=0;
        while(s[i]!='x'){
            s1 = (s1*10) + (s[i++]-'0');
        }
        i++;
        while(s[i]!=':'){
            s2 = (s2*10) + (s[i++]-'0');
        }

        // rsize.push_back({s1,s2});
        i+=2;

        vector<int>freq;
        while(i<s.length()){   
            int val = 0;
            val = (val*10) + (s[i]-'0');
            // val = (val*10) + (s[i+1]-'0');
            freq.push_back(val);

            i += 2; // 3
        }

        // cout<<s1<<" "<<s2<<endl;
        // for(int e : freq){
        //     cout<<e<<" ";
        // }
        // cout<<endl;

        unordered_set<string>st;
        if(solve(0,s1,s2,freq,st)){
            regions++;
        }
    }

    cout<<regions;
    return 0;
}

/*
0:
###
##.
##.

1:
###
##.
.##

2:
.##
###
##.

3:
##.
###
##.

4:
###
#..
###

5:
###
.#.
###

4x4: 0 0 0 0 2 0
12x5: 1 0 1 0 2 2
12x5: 1 0 1 0 3 2
*/
// ans = 2 

// final ans = 460
