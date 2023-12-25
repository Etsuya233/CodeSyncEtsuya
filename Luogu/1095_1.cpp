#include <bits/stdc++.h>
using namespace std;

int m, s, t;

int main(){
	cin >> m >> s >> t;
	int nowt = 0, nows = 0, nowm = m;
	while(nows < s){
		int needt = (int)(ceil(1.0 * (10 - nowm) / 4));
		needt = (needt > 0)? needt: 0;
		if(needt + 1 > t - nowt){
			//直接跑
			nows += (t - nowt) * 17;
			nowt += t - nowt;
	  		break;
		}
		if(ceil(1.0 * (s - nows) / 17) <= needt + 1 && needt + 1 >= 4){
			//直接跑
			nowt += (int)ceil(1.0 * (s - nows) / 17);
			nows += (int)ceil(1.0 * (s - nows) / 17) * 17;
			break;
		}
		nowt += needt + 1;
		nowm += needt * 4 - 10;
		nows += 60;
	}
	if(nows >= s){
		cout << "Yes\n" << nowt;
	} else cout << "No\n" << nows;
	return 0;
}
