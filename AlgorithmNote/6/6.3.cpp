#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string a, b;
	cin >> a;
	int head, foot;
	cin >> head >> foot >> b;
	cout << a.replace(head, foot, b);
}
