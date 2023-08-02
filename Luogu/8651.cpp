#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Calendar{
	int y, m, d;
} cal;

cal tempa;
int ans;
int sto[3];
int bac[3] = {-1, -1, -1};
int seq[3] = {0, 1, 2};
cal arr[100];
char thiscal[100];
int dom[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int perm = 0;
int permm[10] = {0, 1, 2, 2, 0, 1, 2, 1, 0};

bool judge(int y, int m, int d);
bool next_permutation_fuck();
bool cmpCal(cal a, cal b);

int main(){
	scanf("%s", thiscal);
	sto[0] = (thiscal[0] - '0') * 10 + thiscal[1] - '0';
	sto[1] = (thiscal[3] - '0') * 10 + thiscal[4] - '0';
	sto[2] = (thiscal[6] - '0') * 10 + thiscal[7] - '0';
	do{
		if(sto[seq[0]] == bac[0] && sto[seq[1]] == bac[1] && sto[seq[2]] == bac[2]) continue;
		bac[0] = sto[seq[0]];
		bac[1] = sto[seq[1]];
		bac[2] = sto[seq[2]];
		if(judge(sto[seq[0]], sto[seq[1]], sto[seq[2]])){
			if(sto[seq[0]] >= 60) tempa.y = 1900 + sto[seq[0]];
			else tempa.y = 2000 + sto[seq[0]];
			tempa.m = sto[seq[1]];
			tempa.d = sto[seq[2]];
			arr[ans++] = tempa;
		}
	} while(next_permutation_fuck());
	sort(arr, arr + ans, cmpCal);
	for(int i = 0; i < ans; i++){
		printf("%04d-%02d-%02d\n", arr[i].y, arr[i].m, arr[i].d);
	}
	return 0;
}

bool judge(int y, int m, int d){
	if(m > 12 || d > 31 || d < 1 || m < 1) return false;
	if(y >= 60) y += 1900;
	else y += 2000;
	if(m == 2){
		if(y == 2000 || (y % 4 == 0 && y % 100 != 0)){
			if(d <= 29) return true;
		} else {
			if(d <= 28) return true;
		}
	} else {
		if(d <= dom[m]) return true;
	}
	return false;
}

bool cmpCal(cal a, cal b){
	if(a.y < b.y) return true;
	else if(a.y == b.y && a.m < b.m) return true;
	else if(a.y == b.y && a.m == b.m && a.d < b.d) return true;
	return false;
}

bool next_permutation_fuck(){
	perm ++;
	if(perm >= 3) return false;
	seq[0] = permm[3 * perm];
	seq[1] = permm[3 * perm + 1];
	seq[2] = permm[3 * perm + 2];
	return true;
}
