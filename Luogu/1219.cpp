#include <cstdio>
#include <cmath>

int n;
int arr[15] = {0};
int hashRet[15] = {0};
int cnt = 0;

int check(int loc);
void BFS(int loc);

int main(){
	scanf("%d", &n);
	BFS(1);
	printf("%d", cnt);
	return 0;
}

void BFS(int loc){
	if(loc == n + 1){
		cnt ++;
		if(cnt <= 3){
			for(int i = 1; i <= n; i++){
				printf("%d", arr[i]);
				if(i != n) printf(" ");
				if(i == n) printf("\n");
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(hashRet[i]) continue;
		arr[loc] = i;
		hashRet[i] = 1;
		if(!check(loc)){
			hashRet[i] = 0;
			continue;
		}
		BFS(loc + 1);
		hashRet[i] = 0;
	}
}

int check(int loc){
	int ret = 1;
	if(loc > 1){
		for(int i = 1; i < loc; i++){
			if(abs(arr[loc] - arr[i]) == loc - i){
				ret = 0;
				break;
			}
		}
	}
	return ret;
}
