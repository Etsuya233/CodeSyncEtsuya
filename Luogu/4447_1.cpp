#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int arr1[n];
	vector<int> arr[100000];
	for(int i = 0; i < n; i++) scanf("%d", &arr1[i]);
	
	sort(arr, arr + n);
	
	int stack = 0;
	arr[0].push_back(arr1[0]);
	for(int i = 1; i < n; i++){
		if(arr1[i] == arr1[i - 1]){
			int ret = 1;
			for(int j = i + 1; j < n; j++){
				if(arr1[i] == arr1[i - 1]){
					ret++;
					arr[stack++].push_back(arr1[i]);
				}
				else break;
			}
			stack = 0;
			i += ret;
		} else {
			arr[0].push_back(arr1[i]);
		}
	}
	
}
