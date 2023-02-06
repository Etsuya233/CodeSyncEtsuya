#include <cstdio>
#include <algorithm>
using namespace std;

int arr[4][21] = {0};
int sum = 0;
int temp = 0;

void DFS(int left, int right, int i, int j);

int main(){
	for(int i = 0; i < 4; i++){
		scanf("%d", &arr[i][0]);
	}
	for(int i = 0; i < 4; i++){
		int ret = 0x7fffffff;
		for(int j = 1; j <= arr[i][0]; j++){
			scanf("%d", &arr[i][j]);
		}
		sort(&arr[i][1], &arr[i][1] + arr[i][0]);
		do{
			temp = 0;
			DFS(arr[i][1], arr[i][2], i, 2);
			ret = min(temp, ret);
		} while(next_permutation(&arr[i][1], &arr[i][1] + arr[i][0]));
		sum += ret;
	}
	printf("%d", sum);
	return 0;
}

void DFS(int left, int right, int i, int j){
	if(left == 0 || right == 0){
		temp += max(left, right);
		return;
	}
	int diff = left - right;
	if(diff > 0){
		temp += right;
		DFS(diff, arr[i][j + 1], i, j + 1);
	} else if(diff < 0){
		temp += left;
		DFS(arr[i][j + 1], - diff, i, j + 1);
	} else {
		temp += left;
		DFS(arr[i][j + 1], arr[i][j + 2], i, j + 2);
	}
}

