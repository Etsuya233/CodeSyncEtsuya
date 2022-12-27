#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	long long sum = arr[n - 1] * arr[n - 1];
	int head = 0, foot = n - 1, opera = 1;
	while(head < foot){
		sum += ((arr[foot] - arr[head]) * (arr[foot] - arr[head]));
		if(opera) foot --;
		else head ++;
		opera = !opera;
	}
	cout << sum;
	return 0;
}
