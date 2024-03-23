#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int score, pta;
} sco;

int n, k, s;
sco arr[100005];
int vis[100005];

bool cmpSco(sco a, sco b);

int main(){
    cin >> n >> k >> s;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].score >> arr[i].pta;
    }
    sort(arr + 1, arr + 1 + n, cmpSco);
    int ans = 0;
    for(int q = 1; q <= k; q++){
        int lastScore;
        int lastPta;
        int i = 1;
        for( ; i <= n; i++) if(vis[i] == 0 && arr[i].score >= 175) {
            lastScore = arr[i].score;
            lastPta = arr[i].pta;
            ans++;
            vis[i] = 1;
            break;
        }
        if(i == n + 1) break;
        i++;
        for( ; i <= n; i++){
            if(vis[i] == 0 && arr[i].score >= 175 &&  (arr[i].score > lastScore || (arr[i].score == lastScore && arr[i].pta >= s))){
                ans++;
                lastPta = arr[i].pta;
                lastScore = arr[i].score;
                vis[i] = 1;
            }
        }
    }
    cout << ans;
    return 0;
}

bool cmpSco(sco a, sco b){
    if(a.score != b.score) return a.score < b.score;
    else return a.pta < b.pta;
}