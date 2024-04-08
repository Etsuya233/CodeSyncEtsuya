#include <iostream>
#include <set>
using namespace std;

//answer: 235

typedef struct MyDate{
	int m, d;
	friend bool operator < (MyDate a, MyDate b){
		if(a.m != b.m) return a.m < b.m;
		else return a.d < b.d;
	};
} md;

char carr[105];
int arr[105];
int da[10] = {0};
set<md> mdset;
md tempa;

int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void dfs(int digit, int now);

int main(){
	for(int i = 1; i <= 100; i++) cin >> carr[i];
	for(int i = 1; i <= 100; i++) arr[i] = carr[i] - '0';
	dfs(1, 1);
	cout << "----\n";
	int n = 0;
	for(auto it = mdset.begin(); it != mdset.end(); it++){
		cout << n++ << "\t" <<  (*it).m << "\t" << (*it).d << "\n";
	}
	cout << mdset.size();
}

void dfs(int digit, int now){
	if(digit >= 9){
		//validate
		int month = da[5] * 10 + da[6];
		int day = da[7] * 10 + da[8];
		if(month > 0 && day > 0 && month <= 12 && day <= m[month]){
			tempa.m = month;
			tempa.d = day;
			mdset.insert(tempa);
		}
		return;
	}
	for(int i = now; i <= 100; i++){
		da[digit] = arr[i];
		if(digit == 1 && arr[i] == 2) dfs(digit + 1, i + 1);
		if(digit == 2 && arr[i] == 0) dfs(digit + 1, i + 1);
		if(digit == 3 && arr[i] == 2) dfs(digit + 1, i + 1);
		if(digit == 4 && arr[i] == 3) dfs(digit + 1, i + 1);
		if(digit == 5 && arr[i] <= 1){
			dfs(digit + 1, i + 1);
		}
		if(digit == 6) dfs(digit + 1, i + 1);
		if(digit == 7 && arr[i] <= 3) dfs(digit + 1, i + 1);
		if(digit == 8) dfs(digit + 1, i + 1);
	}
}
