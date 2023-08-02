#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Things{
    int v, w, g;
} mono;

int n, m, maxGroup = 0;

mono tempa;
vector<mono> arr[102];
int dp[1005] = {0};
bool cmpWeight(mono a, mono b);

int main(){
    /*
    dp[i][j]: 在选择前i个组且背包最大容量为j时的最大价值。
        dp[i][j]:
            组内物品循环k
                max dp[i - 1][j], dp[i - 1][j - w[k]] + v[k]
    */
    cin >> m >> n;
	for(int i = 0; i < n; i++){
		cin >> tempa.w >> tempa.v >> tempa.g;
		if(tempa.g > maxGroup) maxGroup = tempa.g;
		arr[tempa.g].push_back(tempa);
	}
	for(int i = 1; i <= maxGroup; i++) sort(arr[i].begin(), arr[i].end(), cmpWeight);
	for(int i = 1; i <= maxGroup; i++){
		int size = arr[i].size();
		for(int j = m; j >= 0; j--){
			for(int k = 0; k < size; k++){
				if(arr[i][k].w <= j) 
					dp[j] = max(dp[j], dp[j - arr[i][k].w] + arr[i][k].v);
				else break;
			}
		}
	}
	cout << dp[m];
}

bool cmpWeight(mono a, mono b){
	return a.w < b.w;
}