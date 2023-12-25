#include <iostream>
#include <algorithm>
using namespace std;

typedef struct NumberMine{
	int val, cnt = 0;
} num;

int arr[70];

int n;
int maxlen = -1;
int sum = 0;
int flag = 0;
int numcnter[55] = {0};
num numhash[55];
int numcnt = 0;
int total = 0;

void dfs(int now, int target, int layer, int maxLayer, int nextPosition);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
 		maxlen = max(maxlen, arr[i]);
		sum += arr[i];
		numcnter[arr[i]]++;
	}
	for(int i = 1; i <= 50; i++){
		if(numcnter[i] > 0){
			num temp;
			temp.cnt = numcnter[i];
			temp.val = i;
			numhash[numcnt++] = temp;
		}
	}
	int i = maxlen;
	for( ; i <= sum; i++){
		if(sum % i != 0) continue;
		int times = sum / i;
		dfs(0, i, 1, times, numcnt - 1);
		if(flag == 1){
			break;
		}
	}
	cout << i;
	cout << "\n" << total;
	return 0;
}

void dfs(int now, int target, int layer, int maxLayer, int nextPosition){
	if(layer == maxLayer){
		flag = 1;
		return;
	}
	total++;
	for(int i = nextPosition; i >= 0; i--){
		if(numhash[i].cnt <= 0) continue;
		if(now + numhash[i].val < target){
			numhash[i].cnt --;
			dfs(now + numhash[i].val, target, layer, maxLayer, i);
			numhash[i].cnt ++;
		} else if(now + numhash[i].val == target){
			numhash[i].cnt --;
			dfs(0, target, layer + 1, maxLayer, numcnt - 1);
			numhash[i].cnt ++;
			return;//��һ��ƴ���ã���ʣ�µ�һ����ƴ����
		}
		if(now == 0) return;//��һ����ѡ���� ʣ�µĿ϶����� ��Ϊ������綼Ҫѡ
		if(flag == 1) return;
	}
}
