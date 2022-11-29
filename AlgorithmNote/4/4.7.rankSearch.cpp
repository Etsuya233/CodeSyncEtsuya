#include <cstdio>
#include <ctime>
#include <cstdlib>

int main(){
	srand((unsigned)time(NULL));
	
	int n;
	scanf("%d", &n);
	int search;
	scanf("%d", &search);
	int data[n];
	for(int i = 0; i < n; i++) scanf("%d", &data[i]);
	
	int l = 0, r = n - 1;
	int head = 0, foot = n - 1;
	while(true) {
		int half = rand() % (r - l + 1) + l;
		int temp = data[half];
		
		//swap
		int temp1 = data[0];
		data[0] = data[half];
		data[half] = temp1;
		
		//quickSort
		while (l < r) {
			while (l < r && data[r] > temp) r--;
			data[l] = data[r];
			while (l < r && data[l] < temp) l++;
			data[r] = data[l];
		}
		data[l] = temp;
		
		if (l == search - 1) {
			printf("%d", data[l]);
			break;
		} else if (l > search - 1) {
			foot = r = r - 1;
			l = head;
		} else {
			head = l = l + 1;
			r = foot;
		}
	}
}
