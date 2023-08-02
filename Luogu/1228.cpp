#include <iostream>
#include <cmath>
using namespace std;

int k;

void dfs(int a1, int b1, int a2, int b2, int ii, int jj);

int main(){
	cin >> k;
	int a, b; //ÐÐ ÁÐ
	cin >> a >> b;
	dfs(1, 1, (int)pow(2, k), (int)pow(2, k), a, b);
	return 0;
}

void dfs(int a1, int b1, int a2, int b2, int ii, int jj){
	if(a1 ==  a2) return;
	int mida = (a1 + a2) / 2;
	int midb = (b1 + b2) / 2;
//	if(mida == a1 && midb == b1){
//		if(ii <= mida && jj <= midb){
//			cout << ii << " " << jj << " 1" << "\n";
//		} else if(ii > mida && jj <= midb){
//			cout << ii << " " << jj << " 3" << "\n";
//		} else if(ii <= mida && jj > midb){
//			cout << ii << " " << jj << " 2" << "\n";
//		} else {
//			cout << ii << " " << jj << " 4" << "\n";
//		}
//		return;
//	}
	if(ii <= mida && jj <= midb){
		cout << mida + 1 << " " << midb + 1 << " 1" << "\n";
		dfs(a1, b1, mida, midb, ii, jj);
		dfs(mida + 1, b1, a2, midb, mida + 1, midb);
		dfs(a1, midb + 1, mida, b2, mida, midb + 1);
		dfs(mida + 1, midb + 1, a2, b2, mida + 1, midb + 1);
	} else if(ii > mida && jj <= midb){
		cout << mida << " " << midb + 1 << " 3" << "\n";
		dfs(a1, b1, mida, midb, mida, midb);
		dfs(mida + 1, b1, a2, midb, ii, jj);
		dfs(a1, midb + 1, mida, b2, mida, midb + 1);
		dfs(mida + 1, midb + 1, a2, b2, mida + 1, midb + 1);
	} else if(ii <= mida && jj > midb){
		cout << mida + 1 << " " << midb << " 2" << "\n";
		dfs(a1, b1, mida, midb, mida, midb);
		dfs(mida + 1, b1, a2, midb, mida + 1, midb);
		dfs(a1, midb + 1, mida, b2, ii, jj);
		dfs(mida + 1, midb + 1, a2, b2, mida + 1, midb + 1);
	} else if(ii > mida && jj > midb){
		cout << mida << " " << midb << " 4" << "\n";
		dfs(a1, b1, mida, midb, mida, midb);
		dfs(mida + 1, b1, a2, midb, mida + 1, midb);
		dfs(a1, midb + 1, mida, b2, mida, midb + 1);
		dfs(mida + 1, midb + 1, a2, b2, ii, jj);
	}
}
