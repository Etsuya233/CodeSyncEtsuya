#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
	vector<int> ve;
	Node(): ve(1){}
} node;

node arr[30];

int main(){
	arr[1].ve[0] = 1;
	return 0;
}