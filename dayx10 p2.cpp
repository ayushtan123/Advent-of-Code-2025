#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// brute approach giving TLE on input but is correct

vector<int> getNextState(const vector<int>& curr, const vector<int>& btn, const vector<int>& joltage) {
    vector<int> next_state = curr;
    for(int idx : btn) {
        next_state[idx]++;
        if(next_state[idx] > joltage[idx]) {
            return {}; 
        }
    }
    return next_state;
}

ll bfs_solve(vector<int>& start_t, vector<vector<int>>& buttons, vector<int>& joltage) {
    //{state, steps}
    queue<pair<vector<int>, int>> q;
    q.push({start_t, 0});

    // Visited set to prevent cycles and redundant calculations
    set<vector<int>> visited;
    visited.insert(start_t);

    while(!q.empty()) {
        vector<int> curr = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Check if we reached the target
        if(curr == joltage) {
            return steps;
        }

        for(const auto& b : buttons) {
            vector<int> next_t = getNextState(curr, b, joltage);

            // If state is valid and not visited yet
            if(!next_t.empty() && visited.find(next_t) == visited.end()) {
                visited.insert(next_t);
                q.push({next_t, steps + 1});
            }
        }
    }

    return 0; 
}

int main(){
    fastIO();
    string s;
    ll ans = 0;

    while(getline(cin, s) && !s.empty()){
        vector<vector<int>> buttons;

        int i=1, n=s.length();
        while(s[i]!=']'){ i++; }
        i+=2;

        while(s[i]!='{'){
            if(s[i]=='(' || s[i]==' '){i++; continue;}

            int num=0;
            vector<int>A;
            while(s[i]!=')'){
                num=num*10 + (s[i++]-'0');
                if(s[i] == ','){
                    A.push_back(num);
                    num=0;
                    i++;
                }
            }
            A.push_back(num);
            buttons.push_back(A);
            i++;
        }
        
        vector<int>joltage;
        int num=0;
        i++;
        while(s[i]!='}'){
            num = num*10 + (s[i++]-'0');
            if(s[i]==','){
                joltage.push_back(num);
                num=0;
                i++;
            }
        }
        joltage.push_back(num);
        vector<int> t(joltage.size(), 0);
        
        ll val = bfs_solve(t, buttons, joltage);
        
        cout << val << endl;
        ans += val;
    }
    cout << ans;
    return 0;
}

/*
[.##.] (3) (1,3) (2) (2,3) (0,2) (0,1) {3,5,4,7}
[...#.] (0,2,3,4) (2,3) (0,4) (0,1,2) (1,2,3,4) {7,5,12,7,2}
[.###.#] (0,1,2,3,4) (0,3,4) (0,1,2,4,5) (1,2) {10,11,11,5,10,5}
*/

// ans = 33

// final ans = X (TLE)