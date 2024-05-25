#include <iostream>
using namespace std;

typedef long long ll;

typedef struct StoneStack{
    ll l, lc = 0x7fffffff, r, rc = 0x7fffffff, c = 0, s = 0x7fffffff;
} sto;

ll n;
ll col[305];
ll num[305];
sto dp[305][305];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> col[i];
        dp[i][i].l = col[i];
        dp[i][i].lc = num[i];
        dp[i][i].r = col[i];
        dp[i][i].rc = num[i];
        dp[i][i].s = 1;
    }
    for(int k = 2; k <= n; k++){
        for(int l = 1; l <= n - k + 1; l++){
            ll r = l + k - 1;
            for(int i = l; i <= r - 1; i++){
                ll lr = i, rl = i + 1;
                if(dp[l][lr].r == dp[rl][r].l){
                    int nowl, nowlc, nowr, nowrc;
                    if(dp[l][lr].s == 1){
                        nowl = (dp[l][lr].l + 1) % 3;
                        nowlc = dp[l][lr].rc + dp[rl][r].lc;
                    } else {
                        nowl = dp[l][lr].l;
                        nowlc = dp[l][lr].lc; 
                    }
                    if(dp[rl][r].s == 1){
                        nowr = (dp[rl][r].r + 1) % 3;
                        nowrc = dp[l][lr].rc + dp[rl][r].lc;
                    } else {
                        nowr = dp[rl][r].r;
                        nowrc = dp[rl][r].rc;
                    }
                    ll nows = dp[l][lr].s + dp[rl][r].s - 1;
                    ll nowc = dp[l][lr].c + dp[rl][r].c + dp[l][lr].rc + dp[rl][r].lc;
                    if(nows < dp[l][r].s || (nows == dp[l][r].s && nowc < dp[l][r].c)){
                        dp[l][r].s = nows;
                        dp[l][r].c = nowc;
                        dp[l][r].l = nowl;
                        dp[l][r].lc = nowlc;
                        dp[l][r].r = nowr;
                        dp[l][r].rc = nowrc;
                    }
                } else {
                    ll nowc = dp[l][lr].c + dp[rl][r].c;
                    ll nows = dp[l][lr].s + dp[rl][r].s;
                    ll nowl = dp[l][lr].l;
                    ll nowr = dp[rl][r].r;
                    ll nowlc = dp[l][lr].lc;
                    ll nowrc = dp[rl][r].rc;
                    if(nows < dp[l][r].s || (nows == dp[l][r].s && nowc < dp[l][r].c)){
                        dp[l][r].s = nows;
                        dp[l][r].c = nowc;
                        dp[l][r].l = nowl;
                        dp[l][r].lc = nowlc;
                        dp[l][r].r = nowr;
                        dp[l][r].rc = nowrc;
                    }
                }
            }
            // cout << "locl:" << l << ". locr:" << r << ". l:" << dp[l][r].l << ". r:" << dp[l][r].r << ". lc:" << dp[l][r].lc << ". rc:" << dp[l][r].rc << ". s:" << dp[l][r].s << ". c:" << dp[l][r].c << "\n";
        }
    }
    cout << dp[1][n].s << " " << dp[1][n].c << "\n";
    return 0;
}