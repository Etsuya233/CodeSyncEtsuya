#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct stone{
	int no = 0;
	int distance = 0;
	int a = 0;
	int b = 0;
} Stone;

bool cmpStone(Stone a, Stone b);

int main(){
	int l, n, m;
	scanf("%d%d%d", &l, &n, &m);
	Stone arr[n + 2];
	arr[n + 1].no = n + 1;
	arr[n + 1].distance = n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i].distance);
		arr[i].no = i;
		arr[i].a = arr[i].distance - arr[i - 1].distance;
		if(i > 1){
			arr[i - 1].b = arr[i].distance - arr[i - 2].distance;
		}
	}
	arr[n].b = arr[n + 1].distance - arr[n - 1].distance;
	sort(arr + 1, arr + n, cmpStone);
	for(int i = 0; i < m; i++){
		int foot = upper_bound(&arr[0].no, &arr[n].no, arr[i].no + 1) - &arr[0].no;
		int start = upper_bound(&arr[0].no, &arr[n].no, arr[i].no - 1) - &arr[0].no;
		if(start != 0 && start != n + 1){
			arr[foot].a = arr[foot].distance - arr[start].distance;
		}
	}
	int mini = 0x7fffffff;
	for(int i = 0; i < n; i++){
		if(arr[i].a < mini) mini = arr[i].a;
	}
	printf("%d", mini);
}

bool cmpStone(Stone a, Stone b){
	if(a.a > b.a) return true;
	else {
		if(a.b < b.b) return true;
	}
	return false;
}
