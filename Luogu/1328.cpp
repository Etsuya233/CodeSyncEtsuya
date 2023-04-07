#include <iostream>
using namespace std;

int judge[5][5] = {
	{0, -1, 1, 1, -1},
	{1, 0, -1, 1, -1},
	{-1, 1, 0, -1, 1},
	{-1, -1, 1, 0, 1},
	{1, 1, -1, -1, 0}
};

int main(){
	int n, a, b, aa[201], bb[201], aans = 0, bans = 0, aloc = 0, bloc = 0;
	cin >> n >> a >> b;
	for(int i = 0; i < a; i++) cin >> aa[i];
	for(int i = 0; i < b; i++) cin >> bb[i];
	for(int i = 0; i < n ; i++){
		int ret = judge[aa[aloc++]][bb[bloc++]];
		if(ret > 0) aans ++;
		else if(ret < 0) bans++;
		if(aloc >= a) aloc = 0;
		if(bloc >= b) bloc = 0;
	}
	cout << aans << " " << bans;
}