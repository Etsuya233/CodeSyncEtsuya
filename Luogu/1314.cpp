#include <iostream>
#include <cmath>
using namespace std;

int n, m, s;
int w[200005] = {0}, v[200005] = {0}, rangeF[200005] = {0}, rangeT[200005] = {0};
const long long maxx = 1e6 + 10;
long long mem = 0, ans;
long long calc(int W);

int main(){
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> rangeF[i] >> rangeT[i];
    }
    int l = 0, r = maxx, mid;
    while(l < r){
        mid = (l + r) / 2;
        int judge = ((mem = calc(mid)) > 0);
        if(judge){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if(mem == s){
        ans = 0;
    } else {
        long long mem1 = calc(l - 1);
        long long ans0 = mem - s;
        long long ans = s - mem1;
        ans = (ans0 < ans)? ans0: ans;
    }
    cout << ans;
}

long long calc(int W){
    long long res = 0;
    for(int i = 1; i <= m; i++){
        int l = rangeF[i], r = rangeT[i];
        int cnt = 0, sumv = 0;
        for(int j = l; j <= r; j++){
            if(w[j] >= W){
                cnt ++;
                sumv += v[j];
            }
        }
        res += cnt * sumv;
    }
    return res;
}