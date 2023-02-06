#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int arr[32768] = {0};
	set<int> my;
	int ans = 0, n;
	scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    ans = arr[0];
	my.insert(ans);
	for(int i = 1; i < n; i++){
		int temp = arr[i];
		set<int>::iterator loc1 = my.lower_bound(temp);
		if(*loc1 != temp){
			if(loc1 == my.begin()){
				ans += *loc1 - temp;
			} else if(loc1 == my.end()){
				loc1 --;
				ans += temp - *loc1;
			} else {
				set<int>::iterator loc2 = --loc1;
				loc1 ++;
				ans += min(*loc1 - temp, temp - *loc2);
			}
		}
		my.insert(temp);
	}
	printf("%d", ans);
}