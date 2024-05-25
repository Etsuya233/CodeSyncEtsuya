#include <iostream>
#include <algorithm>
using namespace std;

typedef struct ListNode {
	int front = 0, next = 0, val = 0, e = 1, now = 0;
} node;

typedef struct ListNodePro{
	int now = 0;
	int* e; 
	int* val;
	int* front;
	int* next;
} nodepro;

node arr[500005];
nodepro dp[500005];
int n, k;
bool cmpNodepro(nodepro a, nodepro b);

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> arr[i].val;
		arr[i].now = i;
		arr[i].next = i + 1;
		arr[i].front = i - 1;
		dp[i].now = i;
		dp[i].e = &(arr[i].e);
		dp[i].front = &(arr[i].front);
		dp[i].next = &(arr[i].next);
		dp[i].val = &(arr[i].val);
	}
	for(int i = 1; i <= k; i++){
		sort(dp + 1, dp + 1 + n, cmpNodepro);
//		cout << "Operation: " << i << "\n";
//		for(int j = 1; j <= n; j++){
//			if(arr[j].e == 1) cout << arr[j].val << " ";
//		}
//		cout << "\n";
		arr[dp[1].now].e = 0;
//		cout << "min: arr["  << dp[1].now << "], val: " << *(dp[1].val) << "\n";
		arr[*(dp[1].front)].val += *(dp[1].val);
//		cout << "front: location" << *(dp[1].front) << " --> " << arr[*(dp[1].front)].val << "\n";
		arr[*(dp[1].next)].val += *(dp[1].val);
//		cout << "next: location" << *(dp[1].next) << " --> " << arr[*(dp[1].next)].val << "\n";
		arr[*(dp[1].front)].next = arr[dp[1].now].next;
//		cout << "con: " << *(dp[1].front) << ".next:" <<  arr[dp[1].now].next << "\n";
		arr[*(dp[1].next)].front = arr[dp[1].now].front;
//		cout << "con: " << *(dp[1].next) << ".front:" <<  arr[dp[1].now].front << "\n";
	}
	for(int i = 1; i <= n; i++){
		if(arr[i].e) cout << arr[i].val << " ";
	}
	cout << "\n";
	return 0;
}

bool cmpNodepro(nodepro a, nodepro b){
	if(*(a.e) != *(b.e)) return *(a.e) > *(b.e); 
	else if(*(a.val) != *(b.val)) return *(a.val) < *(b.val);
	else if(a.now != b.now) return a.now < b.now;
	else if(*(a.front) != *(b.front)) return *(a.front) < *(b.front);
	else return *(a.next) < *(b.next);
}
