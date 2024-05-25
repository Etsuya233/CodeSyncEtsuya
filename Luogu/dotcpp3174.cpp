#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
#include <map>
using namespace std;

int n;
int arr1[55][55] = {0};
int arr2[55][55] = {0};
int cnt1 = 1, cnt2 = 1;
int ans1[251] = {0}, ans2[250] = {0};
int dp1[55][55] = {0}, dp2[55][55] = {0};
int ii[4] = {0, 1, 0, -1};
int jj[4] = {1, 0, -1, 0};

void spinarr1();
void spinarr2();


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr1[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr2[i][j];
        }
    }
    //1
    queue<pair<int, int> > qu;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr1[i][j] == 1 && dp1[i][j] == 0){
                qu.push(make_pair(i, j));
                dp1[i][j] = cnt1;
                while(!qu.empty()){
                    int iii = qu.front().first;
                    int jjj = qu.front().second;
                    qu.pop();
                    cnt++;
                    for(int k = 0; k < 4; k++){
                        int nowi = iii + ii[k];
                        int nowj = jjj + jj[k];
                        if(nowi >= 1 && nowi <= n && nowj >= 1 && nowj <= n && arr1[nowi][nowj] == 1 && dp1[nowi][nowj] == 0){
                            dp1[nowi][nowj] = cnt1;
                            qu.push(make_pair(nowi, nowj));
                        }
                    }
                }
                ans1[cnt1] = cnt;
                cnt1++;
                cnt = 0;
            }
        }
    }
    //2
    cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr2[i][j] == 1 && dp2[i][j] == 0){
                qu.push(make_pair(i, j));
                dp2[i][j] = cnt2;
                while(!qu.empty()){
                    int iii = qu.front().first;
                    int jjj = qu.front().second;
                    // cout << iii << " " << jjj << " " << cnt << "\n";
                    qu.pop();
                    cnt++;
                    for(int k = 0; k < 4; k++){
                        int nowi = iii + ii[k];
                        int nowj = jjj + jj[k];
                        if(nowi >= 1 && nowi <= n && nowj >= 1 && nowj <= n && arr2[nowi][nowj] == 1 && dp2[nowi][nowj] == 0){
                            dp2[nowi][nowj] = cnt2;
                            qu.push(make_pair(nowi, nowj));
                        }
                    }
                }
                ans2[cnt2] = cnt;
                cnt2++;
                cnt = 0;
            }
        }
    }
    //calc
    map<int, set<int>> ma;
    queue<int> qu1;
    int vis[505] = {0};
    int ans = 0;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4; j++){
            for(int k = -n + 1; k <= n - 1; k++){
                //put
                for(int q = 1; q <= n; q++){
                    int r = q + k;
                    if(r <= 0 || r > n) continue;
                    int a = dp1[q][n], b = dp2[r][1];
                    if(a == 0 || b == 0) continue;
                    ma[a].insert(250 + b);
                    ma[250 + b].insert(a);
                }
                //stat              
                for(auto it = ma.begin(); it != ma.end(); it++){
                    int nowans = 0;
                    int node = it->first;
                    if(vis[node] == 0){
                        qu1.push(node);
                        while(!qu1.empty()){
                            int now = qu1.front();
                            qu1.pop();
                            vis[now] = 1;
                            if(now > 250) nowans += ans2[now - 250];
                            else nowans += ans1[now];
                            set<int> nowset = ma[now];
                            for(auto it1 = nowset.begin(); it1 != nowset.end(); it1++){
                                if(vis[*it1] == 0) qu1.push(*it1);
                            }
                        }
                    }
                    // cout << "i: " << i << ". j:" << j << ". k:" << k << ". ans: " << nowans << "\n";
                    ans = max(ans, nowans);
                    nowans = 0;
                }
                memset(vis, 0, sizeof(vis));
                ma.clear();
            }
            spinarr2();
        }
        spinarr1();
    }
    cout << ans << "\n";
    return 0;
}

void spinarr1(){
    int temp[55][55] = {0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            temp[j][n - i + 1] = dp1[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp1[i][j] = temp[i][j];
        }
    }
}

void spinarr2(){
    int temp[55][55] = {0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            temp[j][n - i + 1] = dp2[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp2[i][j] = temp[i][j];
        }
    }
}