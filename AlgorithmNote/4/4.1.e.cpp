#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

/*
  请写一个程序，对于一个m行m列的（1<m<10）的方阵，求其每一行，
  每一列及主对角线元素之和，最后按照从大到小的顺序依次输出。
  
  输入
  共一组数据，输入的第一行为一个正整数，表示m，接下来的m行，每行m个整数表示方阵元素。
  
  输出
  从大到小排列的一行整数，每个整数后跟一个空格，最后换行。
 */

bool cmpNumber(int a, int b);

int main(){
	int m;
	cin >> m;
	int arr[m][m];
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	int result[2 * m + 2];
	
	for(int i = 0; i < m; i++){
		int sum = 0;
		for(int j = 0; j < m; j++){
			sum += arr[i][j];
		}
		result[i] = sum;
	}
	
	for(int i = 0; i < m; i++){
		int sum = 0;
		for(int j = 0; j < m; j++){
			sum += arr[j][i];
		}
		result[m + i] = sum;
	}
	
	int sum = 0;
	for(int i = 0; i < m; i++){
		sum += arr[i][i];
	}
	result[2 * m] = sum;
	
	sum = 0;
	for(int i = 0; i < m; i++){
		sum += arr[m - i - 1][i];
	}
	result[2 * m + 1] = sum;
	
	sort(result, result + 2 * m + 2, cmpNumber);
	
	for(int i = 0; i < 2 * m + 2; i++){
		cout << result[i] << " ";
	}
}

bool cmpNumber(int a, int b){
	return (a > b);
}
