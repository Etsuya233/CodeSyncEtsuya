#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Line{
	int t, d, l, e;
} li;

li arr[20];
int t, n;

bool cmpLine(li a, li b);

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> arr[i].t >> arr[i].d >> arr[i].l;
			arr[i].e = arr[i].d + arr[i].t + arr[i].l;
		}
		sort(arr + 1, arr + 1 + n, cmpLine);
		bool res = true;
		int nowt = arr[n].d + arr[n].l + arr[n].t;
		for(int i = n; i >= 1; i--){
			if(arr[i].t + arr[i].l <= nowt){
				if(arr[i].e > nowt){
					nowt -= arr[i].l; 
				} else {
					nowt = arr[i].t + arr[i].d;
				} 
			} else {
				res = false;
				break;
			}
		} 
		cout << (res? "YES\n": "NO\n");
	}
	return 0;
}

bool cmpLine(li a, li b){
	if(a.e != b.e) return a.e < b.e;
	if(a.l != b.l) return a.l < b.l;
	if(a.d != b.d) return a.d > b.d;
	if(a.t != b.t) return a.t < b.t;
}
