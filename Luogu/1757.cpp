//垃圾
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Thing{
    int v, w;
} mono;

int m, n, maxGroup = 0;
vector<mono> my[102];
int dp[1005];

mono tempa;

bool cmpMono(mono a, mono b);

int main(){
    /*
    dp[i][j] 表示从前i组物品中选择，且体积不超过j的最大价值
        dp[i][j] = for(int i = 0; i < 该组物品数量; i++){
            if(j - 该物品价值 > 0)
                max(dp[i - 1][j - 该物品体积] + 该物品价值)
        }
    */
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        int group;
        cin >> tempa.w >> tempa.v >> group;
        maxGroup = max(maxGroup, group);
        my[group].push_back(tempa);
    }
    for(int i = 1; i <= maxGroup; i++){
        sort(my[i].begin(), my[i].end(), cmpMono);
    }
    for(int i = 1; i <= maxGroup; i++){
        for(int j = m; j >= 0; j--){
            for(int k = 0; k < my[i].size(); k++){
                if(my[i][k].w <= j){
                    dp[j] = max(dp[j], dp[j - my[i][k].w] + my[i][k].v);
                } else {
                    break;
                }
            }
        }
    }
    cout << dp[m] << endl;
}

bool cmpMono(mono a, mono b){
    return a.w < b.w;
}