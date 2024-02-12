#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll n, k, ans = 0;
ll arr[100050], ha[11][100050];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        ll t = arr[i];
        for(int j = 1; j <= 10; j++){
            t *= 10;
            ha[j][t % k] ++;
        }
    }
    for(int i = 1; i <= n; i++){
        //digit
        ll len = 0, a = arr[i];
        while(a > 0){
            a /= 10;
            len ++;
        }
        //find
        
    }

}