#include <iostream>
#include <algorithm>
using namespace std;

int arr[305];
int n;
long long ans = 0;
long long res = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int l = 0, r = n - 1;
    ans += arr[l] * arr[l];
    while(l < r){
        if(l < r) ans += (arr[r] - arr[l]) * (arr[r] - arr[l]);
        l++;
        if(l < r) ans += (arr[r] - arr[l]) * (arr[r] - arr[l]);
        r--;
    }
    res = max(ans, res);
    l = 0;
    r = n - 1;
    ans = arr[r] * arr[r];
    while(l < r){
        if(l < r) ans += (arr[r] - arr[l]) * (arr[r] - arr[l]);
        r--;
        if(l < r) ans += (arr[r] - arr[l]) * (arr[r] - arr[l]);
        l++;
    }
    res = max(ans, res);
    cout << res;
}