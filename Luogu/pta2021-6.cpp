#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string arr[33];
    string fk;
    getline(cin ,fk);
    for(int i = 1; i <= n; i++){
        string a;
        getline(cin, a);
        arr[i] = a;
    }
    int cnt = 0, i = 1;
    for( ; i <= n; i++){
        int p1 = arr[i].find("qiandao");
        int p2 = arr[i].find("easy");
        if(p1 != -1 || p2 != -1){
            continue;
        }
        cnt++;
        if(cnt == m) break;
    }
    i++;
    for(; i <= n; i++){
        int p1 = arr[i].find("qiandao");
        int p2 = arr[i].find("easy");
        if(p1 != -1 || p2 != -1){
            continue;
        }
        break;
    }
    if(i > n){
        cout << "Wo AK le";
    } else {
        cout << arr[i];
    }
    return 0;
}