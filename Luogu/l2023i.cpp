#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pa[100005];
int kk[100005];
vector<pair<int, int> > ch[100005];
int d[100005];
int pre[100005];
int preans = 0;

int n, k;

void calcD(int now, int dist);
int lcm(int now, int a, int b);
int getPath(int a, int b);

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n - 1; i++){
		int a, b, w;
		cin >> a >> b >> w;
		int nowpa = min(a, b);
		int nowch = max(a, b);
		pa[nowch] = nowpa;
		ch[nowpa].push_back(make_pair(nowch, w));
	}
	for(int i = 1; i <= k; i++) cin >> kk[i];
	//d
	calcD(1, 0);
	//pre
	for(int i = 1; i <= k - 1; i++){
		pre[i] = getPath(kk[i], kk[i + 1]);
		preans += pre[i];
	}
	//ans
	for(int i = 1; i <= k; i++){
		int ans = preans - pre[i - 1] - pre[i] + getPath(kk[i - 1], kk[i + 1]);
		cout << ans << " \n";
	}
	cout << "\n";
	return 0;
}

int lcm(int now, int a, int b){
	int sum = 0;
	if(now == a || now == b) sum += -1;
	for(auto it = ch[now].begin(); it != ch[now].end(); it++){
		int c = lcm(it->first, a, b);
		if(c > 0) return c;
		sum += c;
	}
	if(sum == -2) return now;
	return sum;
}	

void calcD(int now, int dist){
	d[now] = dist;
	for(auto it = ch[now].begin(); it != ch[now].end(); it++){
		calcD(it->first, dist + it->second);
	}
}

int getPath(int a, int b){
	if(a == 0 || b == 0) return 0;
	int ca = lcm(1, a, b);
	cout << ca << " ";
	return d[a] - 2 * d[ca] + d[b];
}
