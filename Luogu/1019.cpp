//害 垃圾 一遍过哈哈哈哈 you sucks
#include <iostream>
#include <string>
using namespace std;

int n, ans = 0;
int length[21][21] = {0};
string arr[21];
int used[21] = {0};
char start;

void dfs(int tail, int nowLength);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	//Initialize array length
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = arr[i].length() - 1; k > 0 && arr[i].length() - k < arr[j].length(); k--){
				string temp = arr[i].substr(k, arr[i].length());
				string temp1 = arr[j].substr(0, arr[i].length() - k);
				if(temp == temp1){
					length[i][j] = arr[i].length() - k;
					break;
				}
			}
		}
	}
	cin >> start;
	//DFS
	for(int i = 1; i <= n; i++){
		if(arr[i][0] == start){
			used[i] ++;
			dfs(i, arr[i].length());
			used[i] --;
		}
	}
	printf("%d", ans);
	return 0;
}

void dfs(int tail, int nowLength){
	int success = 0;
	for(int i = 1; i <= n; i++){
		if(length[tail][i] > 0 && used[i] < 2){
			used[i] ++;
			success = 1;
			dfs(i, nowLength + arr[i].length() - length[tail][i]);
			used[i] --;
		}
	}
	if(!success){
		ans = (nowLength > ans)? nowLength: ans;
	}
}