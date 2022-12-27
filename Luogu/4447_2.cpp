#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	// Data getting
	int n;
	scanf("%d", &n);
	int arr1[n];
	vector<int> arr[1000];
	for(int i = 0; i < n; i++) scanf("%d", &arr1[i]);
	// Sorting
	sort(arr1, arr1 + n);
	// Classification
	int stack = 0, last = arr1[0];
	arr[0].push_back(arr1[0]);
	for(int i = 1; i < n; i++){
		if(arr1[i] == last){
			arr[++stack].push_back(last);
		} else {
			arr[0].push_back(arr1[i]);
			stack = 0;
			last = arr1[i];
		}
	}
	// Calculating
	int min = 0x7fffffff;
	for(int i = 0; !arr[i].empty(); i++){
		for(int j = 0; j < arr[i].size();){
			int ret = 1;
			for(int k = j + 1; k < arr[i].size(); k++){
				if(arr[j][k] == arr[j][k - 1] + 1) ret++;
				else break;
			}
			min = (ret < min)? ret: min;
			j += ret;
		}
	}
	
	printf("%d", min);
}
