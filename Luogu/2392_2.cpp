// DFS最接近中值的和
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[4][21] = {0};
int result = 0;
int hashRet[21] = {0};
int ret = 1000000;

void DFS(double half, int sum, int last, int i, int j);

int main(){
	for(int i = 0; i < 4; i++){
		scanf("%d", &arr[i][0]);
	}
	for(int i = 0; i < 4; i++){
		ret = 100000;
		int add = 0;
		for(int j = 1; j <= arr[i][0]; j++){
			scanf("%d", &arr[i][j]);
			add += arr[i][j];
		}
		double half = 1.0 * add / 2;
		DFS(half, 0, 0, i, 1);
		if(1.0 * ret < half){
			ret = add - ret;
		}
		result += ret;
	}
	printf("%d", result);
	return 0;
}

void DFS(double half, int sum, int last, int i, int j){
	if(sum >= half){
		int myRet = (half - 1.0 * last < 1.0 * sum - half)? last: sum;
		ret = (fabs(1.0 * ret - half) < fabs(1.0 * myRet - half))? ret: myRet;
		return;
	}
	if(j > arr[i][0]){
		return;
	}
	DFS(half, sum + arr[i][j], sum, i, j + 1);
	DFS(half, sum, last, i, j + 1);
}
