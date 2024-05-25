#include <iostream>
#include <cstring>
using namespace std;

int l[105], r[105];
char opera[1005];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> l[i] >> r[i];
    }
    cin >> opera;
    int len = strlen(opera);
    int layer = 1, loc = 1;
    for(; layer <= m; layer++){
        if(l[layer] <= loc && r[layer] >= loc){
            break;
        }
    }
    if(layer == m + 1) layer = -1;
    for(int i = 0; i < len; i++){
        if(layer == -1) break;
        if(opera[i] == 'L'){
            if(loc - 1 < 1) continue;
            int j = layer;
            for(; j <= m; j++){
                if(l[j] <= loc - 1 && r[j] >= loc - 1){
                    layer = j;
                    loc--;
                    break;
                }
            }
            if(j == m + 1){
                layer = -1;
            }
        } else {
            if(loc + 1 > n) continue;
            int j = layer;
            for(; j <= m; j++){
                if(l[j] <= loc + 1 && r[j] >= loc + 1){
                    layer = j;
                    loc++;
                    break;
                }
            }
            if(j == m + 1){
                layer = -1;
            }
        }
    }
    cout << layer << "\n";
    return 0;
}