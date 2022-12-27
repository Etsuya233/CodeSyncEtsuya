// My super and unique answer! NO ERROR!
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> arr[1000];
	int arr1[n];
	for(int i = 0; i < n; i++) scanf("%d", &arr1[i]);
	sort(arr1, arr1 + n);
	int stack = 0;
	arr[0].push_back(arr1[0]);
	for(int i = 1; i < n; i++){	//Put every number into the vector
		int minimum = 0x7fffffff, loc = -1;
		for(int j = 0; !arr[j].empty(); j++){
			if(arr[j].back() == arr1[i] - 1 && arr[j].size() < minimum){	//Put the number in a proper location which has the min size of the vector
				//Optimize: The min size vector is always located near the back of the vector array 
				minimum = (int)arr[j].size();
				loc = j;
			}
		}
		if(loc == -1){	//If we cant find a proper vector, we should move it to a unused vector
			stack ++;
			arr[stack].push_back(arr1[i]);
		} else {
			arr[loc].push_back(arr1[i]);
		}
	}
	int min = 0x7fffffff;
	for(int i = 0; !arr[i].empty(); i++){
		min = ((int)arr[i].size() < min)? (int)arr[i].size(): min;
	}
	printf("%d", min);
	return 0;
}
