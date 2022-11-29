#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct permutations{
	int storage[8];
} Permutations;

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 1; i <= n; i++) arr[i - 1] = i;
	vector<Permutations> storage;
	
	//Algorithm
	do{
		stack<int> my;
		my.push(0);
		
		int tsuki = 1;
		int isValid = 1;
		for(int i = 0; i < n; i++){
			if(arr[i] < my.top()){
				isValid = 0;
				break;
			} else if(arr[i] > my.top()){
				for(; tsuki <= arr[i]; tsuki++){
					my.push(tsuki);
				}
				my.pop();
			} else {
				my.pop();
			}
		}
		
		if(isValid){
			Permutations temp;
			for(int j = 0; j < n; j++){
				temp.storage[j] = arr[j];
			}
			storage.push_back(temp);
		}
	} while(next_permutation(arr, arr + n));
	
	//Travesal
	for(vector<Permutations>::iterator it = storage.begin(); it != storage.end(); it++){
		for(int i = 0; i < n; i++){
			printf("%d", it->storage[i]);
			if(i != n - 1) printf(" ");
		}
		if(it != storage.end() - 1) printf("\n");
	}
	
	return 0;	
}
