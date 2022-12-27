#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int m, n, sum = 0;
	scanf("%d%d", &m, &n);
	int sch[m], stu[n];
	for(int i = 0; i < m; i++) scanf("%d", &sch[i]);
	for(int i = 0; i < n; i++) scanf("%d", &stu[i]);
	sort(sch, sch + m);
	for(int i = 0; i < n; i++){
		int loc = upper_bound(sch, sch + m, stu[i]) - sch;
		int ret;
		if(loc == 0) ret = 0;
		else if(loc == m) ret = m - 1;
		else if(stu[i] - sch[loc - 1] < sch[loc] - stu[i]) ret = loc - 1;
		else ret = loc;
		sum += abs(stu[i] - sch[ret]);
	}
	printf("%d", sum);
}
