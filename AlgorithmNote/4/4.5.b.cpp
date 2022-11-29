#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int size;
	while(~scanf("%d", &size)){
		int arr[size];
		for(int j = 0; j < size; j++){
			cin >> arr[j];
		}
		for(int j = 0; j < size; j++){
			if(j == 0){
				if(arr[j] != arr[j + 1]) cout << j << " ";
			} else if(j == size - 1){
				if(arr[j] != arr[j - 1]) cout << j << " ";
			} else {
				if((arr[j] > arr[j + 1] && arr[j] > arr[j - 1]) || (arr[j] < arr[j + 1] && arr[j] < arr[j - 1])){
					cout << j << " ";
				}
			}
		}
		cout << endl;
	}
}
