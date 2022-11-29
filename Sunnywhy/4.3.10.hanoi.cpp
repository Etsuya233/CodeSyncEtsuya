#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int index, char one, char two, char three);
void move(char a, char b);

int main(){
	int stack;
	cin >> stack;
	printf("%d\n", (int)pow(2.0, 1.0 * stack) - 1);
	hanoi(stack, 'A', 'B', 'C');
}

void hanoi(int index, char one, char two, char three){
	if(index == 1){
		move(one, three);
		return;
	} else {
		hanoi(index - 1, one, three, two);
		move(one, three);
		hanoi(index - 1, two, one, three);
	}
}

void move(char a, char b){
	cout << a << "->" << b << endl;
}
