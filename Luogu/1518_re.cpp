#include <iostream>
#include <algorithm>
using namespace std;

char arr[11][11];
int cowi, cowj, cowd, fai, faj, fad;
int ii[] = {-1, 0, 1, 0};
int jj[] = {0, 1, 0, -1};
int vis[10][10][10][10][4][4] = {0};
int res = 0;

int main(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 'C'){
				cowi = i;
				cowj = j;
				cowd = 0;
				arr[i][j] = '.';
			}
			if(arr[i][j] == 'F'){
				fai = i;
				faj = j;
				fad = 0;
				arr[i][j] = '.';
			}
		}
	}
	vis[cowi][cowj][fai][faj][cowd][fad] = 1;
	while(true){
		//cow
		if(cowi + ii[cowd] >= 0 && cowj + jj[cowd] >= 0 && cowi + ii[cowd] <= 9 && cowj + jj[cowd] <= 9 && arr[cowi + ii[cowd]][cowj + jj[cowd]] != '*'){
			cowi = cowi + ii[cowd];
			cowj = cowj + jj[cowd];
		} else {
			cowd = (cowd + 1) % 4;
		}
		//farmer
		if(fai + ii[fad] >= 0 && fai + jj[fad] >= 0 && fai + ii[fad] <= 9 && faj + jj[fad] <= 9 && arr[fai + ii[fad]][faj + jj[fad]] != '*'){
			fai = fai + ii[fad];
			faj = faj + jj[fad];
		} else {
			fad = (fad + 1) % 4;
		}
		res ++;
		cout << cowi << " " << cowj << " " << fai << " " << faj << "\n";
		//judge
		if(cowi == fai && cowj == faj){
			break;
		}
		if(vis[cowi][cowj][fai][faj][cowd][fad] == 1){
			res = 0;
			break;
		}
		vis[cowi][cowj][fai][faj][cowd][fad] = 1;
	}
	cout << res;
	return 0;
}
