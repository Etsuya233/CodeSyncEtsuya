#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include<fstream>     
#include <ctime>       // 文件读写头文件
using namespace std;

int n;
int prime[664588];
int vis[10000001];
vector<int> dp[664588];
int arr[500005];
int maxNum = -1;
// vector<int> impos;

void primeFinder();

int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    ifstream fin("7.in");    // 打开文件, "fin"可以自己命名
    fin >> n;
    // cin >> n;
    clock_t start, end;
    start = clock();
    primeFinder();
    for(int i = 1; i <= n; i++){
        fin >> arr[i];
        // cin >> arr[i];
        maxNum = max(maxNum, arr[i]);
    }
    for(int i = 1; i <= n; i++){
        int now = arr[i];
        if(vis[now] >= 2){
            continue;
        }
        else vis[now] ++;
        for(int j = 1; prime[j] <= now && j <= prime[0]; j++){
            if(now % prime[j] == 0){
                dp[j].push_back(arr[i]);
                while(now % prime[j] == 0) now /= prime[j];
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= prime[0] && prime[i] <= maxNum; i++){
        if(dp[i].size() > 1){
            for(auto it = dp[i].begin(); it != dp[i].end(); it++){
                vis[*it] = 1;
            } 
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(vis[arr[i]] == 0){
            ans++;
            // cout << arr[i] << "\n";
        }
    }
    cout << ans << "\n";
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}

void primeFinder(){
    int maxn = 10000000;
    for(int i = 2; i <= maxn; i++){
        // if(i ==157 || i == 337 || i == 937 || i == 5813) cout << prime[0] + 1 << "\n";
        if(vis[i] == 0){
            vis[i] = 1;
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    memset(vis, 0, sizeof(vis));
}