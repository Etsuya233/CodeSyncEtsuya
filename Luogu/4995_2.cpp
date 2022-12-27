#include <bits/stdc++.h>
using namespace std;
long long n,h[500],ans,point=1;
//开数组，不解释
int main(){
	cin >> n;
	for(int i=1;i<=n;i++)cin >> h[i];
	sort(h,h+n+1);//排升序
	int l=0,r=n;//初始化两个游标
	while(r>l){ //如果游标相等或者左边的游标更小那就退出
		ans+=pow(h[r]-h[l],2);//计算跳一次后增加消耗的体力值
		cout << ans << endl;
		l++;
		ans+=pow(h[l]-h[r],2);
		cout << ans << endl;
		r--;//循环一次之后发现，回到了原来的样子，不过问题规模缩小了，要考虑的n少了两个
	}
	cout << ans;
	return 0;
}
