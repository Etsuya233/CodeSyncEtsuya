#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

map<pair<int, int>, int> ma, ma1;
int moda = 1e9 + 7;
int d, t, m;

int main(){
    cin >> d >> t >> m;
    ma[{-1, 1}] = 1;
    if(d > 1){
        ma[{1, 0}] = 1;
    }
    for(int i = 2; i <= t; i++){
        if(i % 2 == 0){
            ma1.clear();
            for(auto it = ma.begin(); it != ma.end(); it++){
                int dis = it->first.first;
                int um = it->first.second;
                int cnt = it->second;
                if(um < m){ //用
                    ma1[{dis - 1, um + 1}] = (ma1[{dis - 1, um + 1}] + cnt) % moda;
                }
                if(dis + 1 < d){ //不用
                    ma1[{dis + 1, um}] += (ma1[{dis + 1, um}] + cnt) % moda;
                }
            }
        } else {
            ma.clear();
            for(auto it = ma1.begin(); it != ma1.end(); it++){
                int dis = it->first.first;
                int um = it->first.second;
                int cnt = it->second;
                if(um < m){ //用
                    ma[{dis - 1, um + 1}] = (ma[{dis - 1, um + 1}] + cnt) % moda;
                }
                if(dis + 1 < d){ //不用
                    ma[{dis + 1, um}] += (ma[{dis + 1, um}] + cnt) % moda;
                }
            }
        }
    }
    int ans = 0;
    if(t % 2 == 0){
        for(auto it = ma1.begin(); it != ma1.end(); it++){
            int dis = it->first.first;
            int um = it->first.second;
            int cnt = it->second;
            if(um == m){
                ans = (ans + cnt) % moda;
            }
        }
    } else {
        for(auto it = ma.begin(); it != ma.end(); it++){
            int dis = it->first.first;
            int um = it->first.second;
            int cnt = it->second;
            if(um == m){
                ans = (ans + cnt) % moda;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}