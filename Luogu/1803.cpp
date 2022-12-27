#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct match{
	int start;
	int end;
} Match;

bool cmpMatch(Match a, Match b);

int main(){
	int n;
	scanf("%d", &n);
	Match arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d%d", &arr[i].start, &arr[i].end);
	}
	sort(arr, arr + n, cmpMatch);
	int head, foot, sum = 1;
	head = arr[0].start;
	for(int i = 1; i < n; i++){
		if(arr[i].start < head && arr[i].end <= head){
			sum++;
			head = arr[i].start;
			foot = arr[i].end;
		}
	}
	printf("%d", sum);
	return 0;
}

bool cmpMatch(Match a, Match b){
	if(a.start > b.start) return true;
	else if(a.start < b.start) return false;
	else {
		if(a.end >= b.end) return true;
		return false;
	}
}
