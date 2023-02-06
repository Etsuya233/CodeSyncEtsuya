#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Number{
    int num, loc;
} num;

bool cmpNum(num a, num b);

int main(){
	num arr[100001];
    int n;
    cin >> n;
    arr[1].num = arr[1].loc = 1;
    for(int i = 2; i <= n; i++){
        arr[i].num = i;
        int a, b;
        cin >> a >> b;
        if(!b) a --;
        arr[i].num = a;
    }
    int m;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        arr[a].loc = -1;
    }
    sort(arr, arr + n + 1, cmpNum);
    for(int i = 0; i < n; i++){
        if(arr[i].loc >= 0) cout << arr[i].num << " ";
    }
}

bool cmpNum(num a, num b){
    if(a.loc < b.loc) return true;
    if(a.loc == b.loc){
        if(a.num < b.num) return true;
    }
    return false;
}