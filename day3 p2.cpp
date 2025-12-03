#include <bits/stdc++.h>
#define ll long long
using namespace std;

// general code for B batteries

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int B; // number of batteries

pair<int,int> solve(int len, int j, int& n, string& s){    // O(B) {max}
    char d='0';
    int idx=0;
    for(int i=j; i<=s.size()-B+len; i++){
        if(s[i]>d){
            d=s[i];
            idx=i;
        }
    }
    return {d-'0', idx+1};
}


int main(){
    fastIO();
    string s;
    ll joltage=0;
    B=12;

    // there is no 0 in digits
    
    while (getline(cin, s) && !s.empty()){
        vector<int>digits(B,0);  // stores 12 digits
        vector<int>index(B+1,0);  // stores next index to search from
        int n=s.length();

        for(int i=0; i<B; i++){                    // O(B*B)
            auto p=solve(i,index[i],n,s);

            digits[i]=p.first;
            index[i+1]=p.second;
        }
        
        // find ith digit from 0 to n-12+i
        // second digit range from LD to n-11
        // third digit range from SD to n-10
        
        ll val=0;
        for(int i=0; i<B; i++){                     // O(B)
            // cout<<digits[i]<<" ";
            val = val*1LL*10 + digits[i]*1LL;
        }
        // cout<<"\n";
        joltage += val;
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
// ans = 3121910778619

// final ans = 172787336861064