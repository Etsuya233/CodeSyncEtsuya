//Succuess: Partition
#include <cstdio>

int n;
int arr[100001] = { 0 };
long long sum = 0;

void func(int head, int foot);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	func(0, n - 1);
	printf("%lld", sum);
	return 0;
}

void func(int head, int foot) {
	if (head == foot) {
		sum += arr[head];
		return;
	}
	int filled = 0;
	int lastLoc = head;
	for (int i = head; i <= foot + 1; i++) {
		if (arr[i]) {
			filled = 1;
			arr[i] --;
		}
		else if (filled && !arr[i]) {
			sum++;
			//			for(int j = lastLoc; j < i; j++) arr[i] --;
			func(lastLoc, i - 1);
			lastLoc = i + 1;
			filled = 0;
		}
		else if (!arr[i]) {
			lastLoc = i + 1;
		}
	}
}