#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    fastIO();
    int pos = 50;
    int ans = 0;
    string s;
    while (getline(cin, s) && !s.empty())
    {
        char move = s[0];
        int step = stoi(s.substr(1));
        int newPos;

        if (move == 'R')
        {
            newPos = (pos + step) % 100;
            for(int i=1; i<=step; i++){
                int currPos = (pos + i) % 100;
                if(currPos == 0){
                    ans++;
                }
            }
        }
        else
        {
            if(step == 0){
                ans += (pos==0);
                continue;
            }
            newPos = (pos - step + 100) % 100;

            for(int i=1; i<=step; i++){
                int currPos = (pos - i + 100) % 100;
                if(currPos == 0){
                    ans++;
                }
            }
        }
        pos = newPos;
        // cout<<ans<<endl;
    }
    cout << ans;
    return 0;
}


// 5923