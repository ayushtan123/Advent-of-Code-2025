#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// it was tough to solve, got it right on 4th trial

int main(){
    fastIO();
    string s;
    vector<vector<char>>data;
    
    while (getline(cin, s) && !s.empty()){
        vector<char>v;

        for(char& ch:s){
            v.push_back(ch);
        }
        data.push_back(v);
    }

    cout<<"Read "<<data.size()<<" rows and "<<data[0].size()<<" columns\n";
    
    ll ans=0;
    int j=0, problems=0;
    int last = data.size()-1;

    // problems is the number of columns 
    // j points on the operator position in last row

    while(j<data[last].size()){
        problems++;
        int next = j+1;

        while(next<data[last].size() && data[last][next]==' '){
            next++;
        }

        // cout<<next<<endl;
        // next counts the gap between operators (j and j+1)
        // tricky part is next is different for each problem and not same

        ll val = (data[last][j]=='+') ? 0 : 1;

        for(int i=j; i<next; i++){
            ll num=-1;

            for(int k=0; k<last; k++){
                if(i<data[k].size() && data[k][i]!=' '){
                    if(num==-1){num=0;}   // first check if num is uninitialized
                    num = num*10 + (data[k][i]-'0');
                }
            }
            
            if(num==-1){
                // cout<<i<<" "<<j<<" "<<-1<<endl;
                continue;
            }
            if(num<0){cout<<i<<" "<<j<<" "<<num<<endl;}

            if(data[last][j]=='+'){
                val += num*1LL;
            }
            else{
                val *= num*1LL;
            }
        }

        // cout<<val<<endl;
        ans += val;
        j = next;
    }
    cout<<problems<<" problems processed\n";
    // make sure you get 1000 problems, you can find no. of problems from day6 p1.cpp

    cout<<ans;
    return 0;
}

/*
123 328  51 64
 45 64  387 23
  6 98  215 314
*   +   *   +
*/
// ans = 3263827

// final ans = 6019576291014

// wrong answers
// 3353988131088
// 3364020834724
// 3407126025476