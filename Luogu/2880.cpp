#include <iostream>
using namespace std;

typedef struct Result{
	int s, t;
} re;

int n, q;
int arr[50050];

re binary(int l, int r);

int main(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		re ans = binary(a, b);
		cout << ans.t - ans.s << "\n";
	}
	return 0;
}

re binary(int l, int r){
	re ret;
	if(l == r){
		ret.s = ret.t = arr[l];
		return ret;
	}
	int mid = (l + r) / 2;
	re a = binary(l, mid);
	re b = binary(mid + 1, r);
	ret.s = (a.s < b.s)? a.s: b.s;
	ret.t = (a.t > b.t)? a.t: b.t;
	return ret;
}
