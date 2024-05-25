#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Competition{
	int a, b;
} com;

com arr[1000005];

bool cmpCom(com a, com b);

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i].a >> arr[i].b;
	}
	sort(arr + 1, arr + 1 + n, cmpCom);
	int l = -1, ans = 0;
	for(int i = 1; i <= n; i++){
		if(arr[i].a >= l){
			ans++;
			l = arr[i].b;
		}
	}
	cout << ans << "\n";
	return 0;
} 

bool cmpCom(com a, com b){
	if(a.b != b.b) return a.b < b.b;
	return a.a > b.a;
}
