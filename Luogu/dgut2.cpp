#include <iostream>
using namespace std;

int n;
int arr[2200] = {0};
int y1, y2, k;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dfs(int y);

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> y1 >> y2 >> k;
		int ans = 0;
		for(int j = y1; j <= y2; j++){
			ans += dfs(j);
		}
		cout << ans << "\n";
	}
	return 0;
}

int dfs(int y){
	//ÅĞ¶ÏÈòÄê
	int cnt = 0;
	bool isrun = false;
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) isrun = true;
//	if(isrun) cout << y << " isrun\n";
	//travel
	int ysum = 0;
	int yt = y;
	while(yt > 0){
		ysum += yt % 10;
		yt /= 10;
	}
	//month
	for(int i = 1; i <= 12; i++){
		int msum = 0;
		int mt = i;
		while(mt > 0){
			msum += mt % 10;
			mt /= 10;
		}
		//day
		int mdays = days[i];
		if(isrun && i == 2) mdays += 1;
		for(int j = 1; j <= mdays; j++){
			int dt = j, dsum = 0;
			while(dt > 0){
				dsum += dt % 10;
				dt /= 10;
			}
			if(ysum + msum + dsum == k) cnt++;
		}
	}
	return arr[y] = cnt;
}
