#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
vector<int> ch[10005];
int pa[10005] = {0};
int ans[10005] = {0};

int fi(int a);
void co(int a, int b);

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		pa[i] = i;
	}
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1){
			co(b, c);
		} else {
			int fa = fi(b);
			ans[fa] += c;
			for(int j = 0; j < ch[fa].size(); j++){
				ans[ch[fa][j]] += c;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}

int fi(int a){
	if(a == pa[a]) return a; 
	else return pa[a] = fi(pa[a]);
}

void co(int a, int b){
	if(fi(b) == fi(a)) return;
	int paa = fi(a);
	int pab = fi(b);
	if(paa > pab){
		swap(paa, pab);
		swap(a, b);
	}
	pa[pab] = paa;
	ch[paa].push_back(pab);
	for(int i = 0; i < ch[pab].size(); i++){
		ch[paa].push_back(ch[pab][i]);
		pa[ch[pab][i]] = paa;
	}
	ch[pab].clear();
}
