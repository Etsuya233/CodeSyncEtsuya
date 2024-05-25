#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int arr[20005];
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    int maxn, maxcnt = 0;
    int minn, mincnt = 0;
    maxn = arr[n];
    minn = arr[1];
    for(int i = 1; i <= n; i++){
        if(arr[i] == minn) mincnt++;
        else break;
    }
    for(int i = n; i >= 0; i--){
        if(arr[i] == maxn) maxcnt ++;
        else break;
    }
    cout << minn << " " << mincnt << "\n" << maxn << " " << maxcnt;
    return 0;
}