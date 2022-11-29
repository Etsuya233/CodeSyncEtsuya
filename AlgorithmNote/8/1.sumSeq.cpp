#include <cstdio>
#include <vector>
using namespace std;

int n;
int arr[20];
vector<int> result[20];
vector<int> temp;
int sum = 0;
int loc = 0;

void sumSeq(int i, int nowSum);

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	scanf("%d", &sum);
	sumSeq(n - 1, 0);
	for(int i = 0; i < loc; i++){
		for(vector<int>::iterator it = result[i].begin(); it != result[i].end(); it++){
			printf("%d\t", *it);
		}
		printf("\n");
	}
	return 0;
}


void sumSeq(int i, int nowSum){
	if(nowSum == sum){
		for(vector<int>::iterator it = temp.begin(); it != temp.end(); it++){
			result[loc].push_back(*it);
		}
		loc++;
		return;
	}
	if(i == -1){
		return;
	}
	sumSeq(i - 1, nowSum);
	temp.push_back(arr[i]);
	sumSeq(i - 1, nowSum + arr[i]);
	temp.push_back(arr[i]);
	sumSeq(i - 1, nowSum + 2 * arr[i]);
	temp.pop_back();
	temp.pop_back();
}
