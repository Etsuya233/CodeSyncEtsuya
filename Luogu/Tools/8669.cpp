#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, k;
ll arr[100050];
ll MODA = 1000000009;
ll ans = 1;

inline ll abs(ll a);
bool cmpNum(ll a, ll b);

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, cmpNum);
	ll nowZero = 0;
	ll nowMinus = 0;
	ll nowPlus = 0;
	for(int i = 0; i < k; i++){
		if(arr[i] < 0) nowMinus ++;
		else if(arr[i] == 0) nowZero ++;
		else if(arr[i] > 0) nowPlus ++;
	}
	/*
    奇数个minus
        向下同时找最近的minus a和plus b（包括0）
        如果ab否存在：
			最后一个minus*a，最后一个plus*b，比较abs大小！
        如果只有a存在：
			最后一个plus*a
        如果只有b存在：
			最后一个minus*b
    偶数个minus
		直接输出答案
	*/
	if(nowZero == 0){
		if(nowMinus % 2 == 1){
			ll lastMinus = -1, lastPlus = -1;
			for(int i = 0; i < k; i++){
				if(arr[i] < 0) lastMinus = i;
				else lastPlus = i;
			}
			ll minMinus = 1, maxPlus = -1;
			for(int i = k; i < n; i++){
				if(minMinus == 1 && arr[i] < 0) minMinus = arr[i];
				if(maxPlus == -1 && arr[i] >= 0) maxPlus = arr[i];
				if(minMinus != 1 && maxPlus != -1) break;
			}
			if(k != n){
				ll cantMul = -1, needMul = -1, maxMul = -100000;
				if(lastMinus != -1 && minMinus != 1 && lastPlus != -1 && maxPlus != -1){
					if(arr[lastMinus] * minMinus > maxMul){
						cantMul = lastMinus;
						needMul = minMinus;
						maxMul = arr[lastMinus] * minMinus;
					}
					if(arr[lastPlus] * maxPlus > maxMul){
						cantMul = lastPlus;
						needMul = maxPlus;
					}
				}
				if(cantMul != -1){
					for(int i = 0; i < k; i++){
						if(i != cantMul) ans = (ans * arr[i]) % MODA;
					}
					ans = (ans * needMul) % MODA;
				} else {
					if(arr[0] < 0)
						for(int i = 0; i < k; i++){
							ans = (ans * arr[n - 1 - i]) % MODA;
						}
					else
						for(int i = 0; i < k; i++){
							ans = (ans * arr[i]) % MODA;
						}
				}
			} else {
				for(int i = 0; i < k; i++){
					ans = (ans * arr[i]) % MODA;
				}
			}
		} else {
			for(int i = 0; i < k; i++){
				ans = (ans * arr[i]) % MODA;
			}
		}
	} else {
		ans = 0;
	}
	cout << ans;
	return 0;
}

ll mabs(ll a){
	return (a >= 0)? a: -a;
}

bool cmpNum(ll a, ll b){
	return mabs(a) > mabs(b);
}

/*
ll a = arr[lastMinus] * minMinus;
				ll b = arr[lastPlus] * maxPlus;
				int cantMul, needMul;
				if(lastMinus != -1 && lastPlus != -1){
					cantMul = (a > b)? lastPlus: lastMinus;
					needMul = (a > b)? minMinus: maxPlus;
				} else if(lastMinus == -1 && lastPlus != -1){
					cantMul = lastMinus;
					needMul = maxPlus;
				} else {
					cantMul = lastPlus;
					needMul = minMinus;
				}
				for(int i = 0; i < k; i++){
					if(i != cantMul) ans = (ans * arr[i]) % MODA;
				}
				ans = (ans * needMul) % MODA;

*/
