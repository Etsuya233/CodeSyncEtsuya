#include <iostream> 
#include <algorithm>
using namespace std;

typedef long long ll;

typedef struct {
	ll num, val;
} node;

ll n;
ll ans = 0;
node arr[1000005];
ll cnt[11] = {0};
ll base;

bool cmpNode(node a, node b);

int main(){
	cin >> n;
	base = n / 10;
	for(int i = 1; i <= n; i++)	{
		cin >> arr[i].num >> arr[i].val;
		cnt[arr[i].num] ++;
	}
	sort(arr + 1, arr + 1 + n, cmpNode);
	for(int i = 1; i <= n; i++){
		if(cnt[arr[i].num] > base){
			ans += arr[i].val;
			cnt[arr[i].num] --;
		}
	}
	cout << ans << "\n";
	return 0;
}

bool cmpNode(node a, node b){
	if(a.num != b.num) return a.num < b.num;
	else return a.val < b.val;
}
