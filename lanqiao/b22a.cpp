#include <iostream>
using namespace std;

typedef long long ll;
ll cnt = 0;

void dfs(ll now, ll sum, ll layer);

int arr[11] = {0};

int main(){
    dfs(1, 0, 1);
    cout << cnt << "\n";
    return 0;
}

void dfs(ll now, ll sum, ll layer){
    if(sum >= 2022) return;
    if(2022 - sum < now) return;
    if(layer == 10){
        if(2022 - sum >= now){
            cnt++;
            arr[10] = 2022 - sum;
            if(cnt % 100000000L == 0){
                cout << cnt << ": ";
                for(int i = 1; i <= 10; i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
            return;
        }
    }
    for(ll i = now; i <= 2022; i++){
        arr[layer] = i;
        dfs(i + 1, sum + i, layer + 1);
    }
}