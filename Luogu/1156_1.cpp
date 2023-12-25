#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct Garbage{
	int t = 0, h = 0, f = 0;
} ga;

int d, g;
ga arr[105];
int dp[105][3050] = {0};
int sumt = 10;

bool cmpGarbage(ga a, ga b);
void printLine(int ii, int jj);

int main(){
	cin >> d >> g;
	for(int i = 1; i <= g; i++){
		cin >> arr[i].t >> arr[i].f >> arr[i].h;
	}
	sort(arr + 1, arr + g + 1, cmpGarbage);
	for(int i = 1; i <= g; i++){
		if(sumt >= arr[i].t){
			sumt += arr[i].f;
		} else break;
	}
	memset(dp, -1, sizeof(dp));
	dp[0][10] = 0;
	int flag = 0;
	int i = 1;
	for( ; i <= g; i++){
		int ii = i % 2;
		int dt = arr[i].t - arr[i - 1].t;
		for(int j = 0; j <= sumt; j++){
			//用于吃
//			if(j - arr[i].f >= 0 && j - arr[i].f + dt <= sumt && dp[(ii + 1) % 2][j - arr[i].f + dt] != -1) dp[ii][j] = max(0, dp[(ii + 1) % 2][j - arr[i].f + dt]);
			if(j - arr[i].f >= 0 && dp[i - 1][j - arr[i].f + dt] != -1) dp[i][j] = max(0, dp[i - 1][j - arr[i].f + dt]);
			//用于堆放
//			if(dp[(ii + 1) % 2][j + dt] != -1) dp[ii][j] = max(dp[ii][j], dp[(ii + 1) % 2][j + dt] + arr[i].h);
			if(dp[i - 1][j + dt] != -1) dp[i][j] = max(dp[i][j], dp[i - 1][j + dt] + arr[i].h);
			//if(dp[ii][j] >= d){
			if(dp[i][j] >= d){
				flag = 1;
				break;
			}
		}
		if(flag) break;
	}
	if(flag){
		cout << arr[i].t << "\n";
	} else {
		//camen dead
		cout << sumt << "\n";
	}
	return 0;
}

void printLine(int ii, int jj){
	cout << "(" << ii << ", " << jj << "): ";
	for(int i = 0; i <= jj; i++){
		cout << dp[ii][i] << "\t";
	}
	cout << "\n";
}

bool cmpGarbage(ga a, ga b){
	return a.t < b.t;
}
