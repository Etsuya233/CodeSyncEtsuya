#include <iostream>
#include <cmath>
using namespace std;

typedef struct Position{
	int i, j;
} po;

int ans = 0;
int ii[4] = {-1, 0, 1, 0};
int jj[4] = {0, 1, 0, -1};
int arr[10][10] = {0};
int block[10][10] = {0};
int row[10][10] = {0};
int val = 0;
int column[10][10] = {0};
inline int poi(int i, int j){ return 10 - max(abs(i - 5), abs(j - 5)); }

void dfs(int nowi, int nowj);
int nextd(int i, int j);
int getb(int x,int y);
void printMap();
void calc();
int point(int x,int y);

int main(){
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			cin >> arr[i][j];
		}
	}
	//pre
	for(int k = 1; k <= 9; k++){
		int si = (k - 1) / 3 * 3 + 1;
		int sj = (k - 1) % 3 * 3 + 1;
		if(sj < 0) sj = 7;
		for(int i = si; i < si + 3; i++){
			for(int j = sj; j < sj + 3; j++){
				block[k][arr[i][j]] ++;
				row[i][arr[i][j]] ++;
				column[j][arr[i][j]] ++;
				if(arr[i][j] > 0 && block[k][arr[i][j]] > 1){
					cout << -1;
					exit(0);
				}
				if(arr[i][j] > 0 && row[i][arr[i][j]] > 1){
					cout << -1;
					exit(0);
				}
				if(arr[i][j] > 0 && column[j][arr[i][j]] > 1){
					cout << -1;
					exit(0);
				}
			}
		}
	}
	//dfs
	dfs(5, 5);
	if(val) cout << ans << "\n";
	else cout << -1;
//	printMap();
	return 0;
}


void dfs(int nowi, int nowj){
//	if(val) return;
	int nextdd = nextd(nowi, nowj);
	if(arr[nowi][nowj] != 0){
		if(nowi == 1 && nowj == 1){
			calc();
			val = 1;
			return;
		}
		dfs(nowi + ii[nextdd], nowj + jj[nextdd]);
	} else {
		for(int i = 9; i >= 1; i--){
			if(!block[getb(nowi, nowj)][i] && !row[nowi][i] && !column[nowj][i]){
//				cout << nowi << " " << nowj << " " << i << '\n';
				int nextdd = nextd(nowi, nowj);
				block[getb(nowi, nowj)][i] = 1;
				row[nowi][i] = 1;
				column[nowj][i] = 1;
				arr[nowi][nowj] = i;
				if(nowi == 1 && nowj == 1){
					calc();
					return;
				}
				dfs(nowi + ii[nextdd], nowj + jj[nextdd]);
//				if(val) return;
				arr[nowi][nowj] = 0;
				block[getb(nowi, nowj)][i] = 0;
				row[nowi][i] = 0;
				column[nowj][i] = 0;
			}
		}
	}
}

int nextd(int i, int j){
	if(i == 5 && j == 5){
		return 0;
	} else if(j <= 5 && i >= j && i <= 9 - j + 1){
		return 0;
	} else if(i < 5 && j > i && j <= 9 - i){
		return 1;
	} else if(j > 5 && i >= 10 - j && i <= j - 1){
		return 2;
	}
	return 3;
}

int getb(int x,int y){
	if(x>=1&&x<=3){
		if(y>=1&&y<=3)  return 1;
		else if(y>=4&&y<=6) return 2;
		else    return 3;
	}
	if(x>=4&&x<=6){
		if(y>=1&&y<=3)  return 4;
		else if(y>=4&&y<=6) return 5;
		else    return 6;
	}
	if(x>=7&&x<=9){
		if(y>=1&&y<=3)  return 7;
		else if(y>=4&&y<=6) return 8;
		else    return 9;
	}
	return 0;
}

void calc(){
	int temp = 0;
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			temp += point(i, j) * arr[i][j];
		}
	}
	ans = max(temp, ans);
}

int point(int x,int y){
	if(x==1||y==1||x==9||y==9)   return 6;
    else if(x==2||y==2||x==8||y==8)     return 7;
    else if(x==3||y==3||x==7||y==7)   return 8;
    else if(x==4||y==4||x==6||y==6)   return 9;
    else	return 10;
}

void printMap(){
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}





