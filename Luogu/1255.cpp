#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

typedef struct bigN{
	int num[5000] = {0};
	int digit = 1;
	int used = 0;
} BigN;

BigN zero;
BigN one;
BigN res[5001];
BigN unused;

BigN newBigN();
BigN plusBigN(BigN a, BigN b);
void showBigN(BigN a);
BigN stair(int step);

int main(){
	fill(res, res + 5000, unused);
	zero.used = 0;
	one.used = 1;
	one.num[0] = 1;
	int step;
	scanf("%d", &step);
	showBigN(stair(step - 1));
	return 0;
}

BigN stair(int step){
	if(step == 0) return zero;
	if(step == 1) return one;
	if(res[step].used) return res[step];
	return res[step] = plusBigN(stair(step - 1), stair(step - 2));
}

BigN newBigN(){
	BigN a;
	a.used = 1;
	char str[5005];
	scanf("%s", str);
	a.digit = strlen(str);
	for(int i = 0; i < a.digit; i++){
		a.num[i] = str[i] - '0';
	}
	reverse(a.num, a.num + a.digit);
	return a;
}

BigN plusBigN(BigN a, BigN b){
	BigN ret;
	ret.used = 1;
	int i, carry = 0;
	int number;
	for(i = 0; i < a.digit || i < b.digit; i++){
		number = carry + a.num[i] + b.num[i];
		ret.num[i] = number % 10;
		carry = number / 10;
	}
	ret.digit = i;
	if(carry){
		ret.num[i] = carry;
		ret.digit++;
	}
	return ret;
}

void showBigN(BigN a){
	for(int i = 0; i < a.digit; i++){
		printf("%d", a.num[i]);
	}
}
