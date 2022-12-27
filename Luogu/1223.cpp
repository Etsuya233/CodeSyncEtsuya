#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct people{
	int no;
	int time;
} People;

bool cmpTime(People i, People j);

int main(){
	int n;
	scanf("%d", &n);
	People arr[n];
	for(int i = 0; i < n; i++){
		arr[i].no = i + 1;
		scanf("%d", &arr[i].time);
	}
	sort(arr, arr + n, cmpTime);
	double aver, wait = 0;
	long long sum = 0;
	for(int i = 0 ; i < n; i++){
		printf("%d ", arr[i].no);
		sum += arr[i].time * (n - i - 1);
	}
	aver = 1.0 * sum / n;
	printf("\n%.2f", aver);
	return 0;
}

bool cmpTime(People a, People b){
	if(a.time < b.time) return true;
	if(a.time == b.time){
		if(a.no < b.no) return true;
		return false;
	}
	return false;
}
