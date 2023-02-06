#include <iostream>
#include <queue>
using namespace std;

typedef struct Tourist{
    int time, country;
} Tourtist;

int main(){
    int country[300005] = {0};
    queue<Tourist> my;
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t, a;
        cin >> t >> a;
        for(int j = 0; j < a; j++){
            int cou;
            cin >> cou;
            if(!country[cou]) ans ++;
            country[cou] ++;
            Tourist temp = { .time = t, .country = cou};
            my.push(temp);
        }
        int limit = t - 86400;
        while(!my.empty()){
            if(my.front().time <= limit){
                country[my.front().country] --;
                if(country[my.front().country] == 0) ans --;
                my.pop();
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
}