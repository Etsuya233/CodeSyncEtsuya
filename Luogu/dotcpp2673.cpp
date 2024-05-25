#include <iostream>
using namespace std;

int n;
int arr[100005];
int pre[100005] = {0};

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pre[arr[i]] += 1;
    }
    for(int i = 1; i <= 100001; i++){
        pre[i] += pre[i - 1];
    }
    for(int i = 1; i <= n; i++){
        int l = 0, r = 100000, mid, val = arr[i];
        int pl, pr;
        while(l < r){
            mid = (l + r) / 2;
            if(val < mid){
                pl = pre[mid - 1] - 1;
                pr = pre[100001] - pre[mid];
            } else if(val == mid){
                pl = pre[mid - 1];
                pr = pre[100001] - pre[mid];
            } else {
                pl = pre[mid - 1];
                pr = pre[100001] - pre[mid] - 1;
            }
            if(pl < pr){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if(l <= val) cout << 0 << " ";
        else cout << l - val << " ";
    }
    return 0;
}