#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n;
ll arr[100005];

void Merge(int arr[],int low,int mid,int high);

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    ll l = 1, r = n;
    ll ans = 0;
    sort(arr + 1, arr + 1 + n);
    while(l < r){
        if(arr[l] != 0 && arr[r] != 0){
            arr[l]--;
            arr[r]--;
            ans += 2;
        }
        else {
            while(arr[l] == 0 && l <= n) l++;
            while(arr[r] == 0 && r >= 1) r--;
        }
    }
    cout << ans << "\n";
    return 0;
}

void Merge(int arr[],int low,int mid,int high){
    //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i=low,j=mid+1,k=0;  //mid+1为第2有序区第1个元素，j指向第1个元素
    int *temp=new int[high-low+1]; //temp数组暂存合并的有序序列
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]) //较小的先存入temp中
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++]=arr[i++];
    while(j<=high)//同上
        temp[k++]=arr[j++];
    for(i=low,k=0;i<=high;i++,k++)//将排好序的存回arr中low到high这区间
	arr[i]=temp[k];
    delete []temp;//释放内存，由于指向的是数组，必须用delete []
}