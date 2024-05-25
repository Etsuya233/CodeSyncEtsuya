#include <iostream> 
#include <queue>
using namespace std;

typedef long long ll;

ll n, np = 4;
ll arr[2000001] = {0, 1, 2, 2};

int main(){
	cin >> n;
	for(int i = 3; i <= 2000000; i++){
		for(int j = 0; j < arr[i] && np + j <= 2000000; j++){
			arr[np + j] = i;
		}
		np += arr[i];
	}
	ll t = 0, q = 0;
	for(int i = 1; ; i++){
//		if(i % 1000000 == 0){
//			cout << i << " " << t << "\n";
//		}
		t += arr[i] * i;
		if(t >= n){
			t -= arr[i] * i;
			cout << q + (n - t + i - 1) / i << "\n";
			break;
		}
		q += arr[i];
	}
	return 0;
}
