#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Log{
	int time, id;
} lo;

int iine[100010] = {0};
lo arr[100010];
bool flag[100010] = {false};

int n, d, k;

bool cmpLog(lo a, lo b);

int main(){
	cin >> n >> d >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i].time >> arr[i].id;
	}
	sort(arr, arr + n, cmpLog);
	int l = 0, r = 0;
	while(r < n && arr[r].time < d){
		if((iine[arr[r].id] += 1) >= k) flag[arr[r].id] = true;
		r++;
	}
	/*  d = 4:
			0 1 2 3 4 5
		l   - - - 0 1 2
		r   0 1 2 3 4 5
	nowTime
	*/
	int nowTime = d;
	while(r < n){
		//minus
		while(r < n && arr[l].time <= nowTime - d){
			iine[arr[l].id] --;
			l++;
		}
		//plus
		while(r < n && arr[r].time <= nowTime){
			iine[arr[r].id] ++;
			if(iine[arr[r].id] >= k) flag[arr[r].id] = true;
			r++;
		}
		nowTime++;
	}
	for(int i = 0; i < 100005; i++){
		if(flag[i]) cout << i << "\n";
	}
}

bool cmpLog(lo a, lo b){
	return a.time < b.time;
}
