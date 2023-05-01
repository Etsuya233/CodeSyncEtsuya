#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

int arr[50005] = {0};
int dp[50005] = {0};
int amount[50005] = {0};
vector<int> last;
int systemAmount = 0;
int n = 0;
int ret1 = 0;

int lis[50005];
int l1 = -1;
	
void calcAmount(int loc);
void opera(int loc);
void opera2(int loc);
void calcAmount3(int loc);
void calcAmount2(int loc);

int main(){
	while(~scanf("%d",&arr[n++]));
	n--;
	for(int i = 0; i < n; i++){
		// opera(i);
		opera2(i);
		calcAmount3(i);
	}
	printf("%d %d", l1 + 1, systemAmount);
}

void opera(int loc){
	if(loc < 0 || loc >= n) return;
	int maximum = 0;
	for(int i = 0; i < loc; i++){
		if(arr[i] >= arr[loc] && dp[i] >= maximum){
			maximum = dp[i];
		}
	}
	if((dp[loc] = 1 + maximum) > ret1) ret1 = dp[loc];
}

void opera2(int loc){
	if(lis[l1] >= arr[loc] || l1 == -1){
		lis[++l1] = arr[loc];
	} else {
		*upper_bound(lis, lis + l1, arr[loc], greater<>()) = arr[loc];
//		lis[pos] = arr[loc];
	}
}

void calcAmount(int loc){
	if(systemAmount == 0){
		systemAmount++;
		last.push_back(arr[loc]);
		return;
	}
	vector<int>::iterator pos = lower_bound(last.begin(), last.end(), arr[loc]);
	if(pos == last.end()){
		last.push_back(arr[loc]);
		systemAmount++;
	} else{

	}
}

void calcAmount2(int loc){
	if(systemAmount == 0){
		amount[systemAmount] = arr[loc];
		systemAmount ++;
		return;
	}
	int a = -1;
	int delta = 0x7fffffff;
	for(int i = 0; i < systemAmount; i++){
		if(amount[i] >= arr[loc] && amount[i] - arr[loc] < delta){
			delta = amount[i] - arr[loc];
			a = i;
		}
	}
	if(a == -1){
		amount[systemAmount++] = arr[loc];
	} else {
		amount[a] = arr[loc];
	}   
}

void calcAmount3(int loc){
	if(systemAmount == 0){
		amount[systemAmount] = arr[loc];
		systemAmount ++;
		return;
	}

	// for(int i = 0; i < systemAmount; i++){
	// 	if(amount[i] >= arr[loc] && amount[i] - arr[loc] < delta){
	// 		delta = amount[i] - arr[loc];
	// 		a = i;
	// 	}
	// }

	int* pos = lower_bound(amount, amount + systemAmount, arr[loc]);
	
	if(*pos == 0){
		amount[systemAmount++] = arr[loc];
	} else {
		*pos = arr[loc];
		if(*(pos + 1) != 0 && *pos > *(pos + 1)){
			int temp = *pos;
			*pos = *(pos + 1);
			*(pos + 1) = temp;
		}
	}   
}
