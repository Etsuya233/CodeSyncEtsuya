#include <iostream>
using namespace std;

int ll, n, m; //起点到终点的距离，起点和终点之间的岩石数，以及组委会至多移走的岩石数。
int arr[50005] = {0};

/*
    最短跳跃距离的最大值。
    确定mid
    如果跳跃距离有小于mid的就移除石头
    计算移走石头的数量
        l - arr[now] < mid ---> 表示最短距离的最大值太大
    lower or upper?
*/

int main(){
    cin >> ll >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    arr[n + 1] = ll;
		
    int l = 0, r = ll + 1, mid, cnt = 0, ans = 0;
    while(l <= r){
		//0 2 11 14 17 21 25
        int now = 0;
        int next = 0;
		cnt = 0;
        mid = (l + r) / 2;
        //Judge(主要是这一部分不太懂！！)
        while(next <= n + 1){//当要跳的石头next还没达到终点那一块时：
            next++;
			if(arr[next] - arr[now] >= mid){//假如要跳的石头的距离大于mid
                now = next;//那就跳过去
            } else {//否则
                cnt ++;//就把这块石头给移开
            }
//			next = next + 1;//无论跳还是没跳，都要把目光放到下一块石头
        }
		//当目光放到最后一块石头的时候，如果距离小于mid，就意味着我当前站的石头也是不该跳的，所以cnt++
		//否则就跳过去
		//二分
		if(cnt <= m){
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
    }
    cout << ans;
}
