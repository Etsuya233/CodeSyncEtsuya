#include <iostream>
#include <cstring>
using namespace std;

typedef struct Boommm{
	int la = 0, ra = 0, lb = 0, rb = 0, lc = 0, rc = 0, h = 0;
} bo;

int a, b, c, m;
int arr[1000050] = {0};//ÑªÁ¿
int pre[1000050] = {0};//²î·Ö
bo boom[1000050];
int fuckubitch = 0;

bool pre_sum();
int* rea(int* arrName, int ii, int jj, int kk);
void start_execution(int round);

int main(){
	cin >> a >> b >> c >> m;
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			for(int k = 1; k <= c; k++){
				cin >> *rea(arr, i, j, k);
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cin >> boom[i].la >> boom[i].ra >> boom[i].lb >> boom[i].rb >> boom[i].lc >> boom[i].rc >> boom[i].h;
	}
	int l = 1, r = m, mid;
	while(l < r){
		mid = (l + r) / 2;
		start_execution(mid);
		if(pre_sum()){
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << l;
	return 0;
}

int* rea(int *arrName, int ii, int jj, int kk){
	int location = ((ii - 1) * b + (jj - 1)) * c + (kk - 1) + 1;
	if(location < 0){
		return &fuckubitch;
	}
	return &arrName[location];
}

void start_execution(int round){
	memset(pre, 0, sizeof(pre));
	for(int i = 1; i <= round; i++){
		*rea(pre, boom[round].la, boom[round].lb, boom[round].lc) += boom[round].h;
		*rea(pre, boom[round].la, boom[round].rb + 1, boom[round].lc) -= boom[round].h;
		*rea(pre, boom[round].la, boom[round].lb, boom[round].rc + 1) -= boom[round].h;
		*rea(pre, boom[round].la, boom[round].rb + 1, boom[round].rc + 1) += boom[round].h;
		*rea(pre, boom[round].ra + 1, boom[round].lb, boom[round].lc) -= boom[round].h;
		*rea(pre, boom[round].ra + 1, boom[round].rb + 1, boom[round].lc) += boom[round].h;
		*rea(pre, boom[round].ra + 1, boom[round].lb, boom[round].rc + 1) += boom[round].h;
		*rea(pre, boom[round].ra + 1, boom[round].rb + 1, boom[round].rc + 1) -= boom[round].h;
	}
}

bool pre_sum(){
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			for(int k = 1; k <= c; k++){
				*rea(pre, i, j, k) += *rea(pre, i - 1, j, k);
				*rea(pre, i, j, k) += *rea(pre, i, j - 1, k);
				*rea(pre, i, j, k) += *rea(pre, i, j, k - 1);
				*rea(pre, i, j, k) -= *rea(pre, i - 1, j - 1, k);
				*rea(pre, i, j, k) -= *rea(pre, i, j - 1, k - 1);
				*rea(pre, i, j, k) -= *rea(pre, i, j - 1, k - 1);
				*rea(pre, i, j, k) += *rea(pre, i - 1, j - 1, k - 1);
				if(*rea(pre, i, j, k) > *rea(arr, i, j, k)) return false;
			}
		}
	}
	return true;
}
