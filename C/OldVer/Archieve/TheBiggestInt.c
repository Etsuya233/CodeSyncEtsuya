#include <stdio.h>
int main(){
	int a=0;
	while(a>=0){
		a++;
	}
	a-=1;
	printf("%u\n",a);
	// Above are int, below are unsigned int.
	unsigned int b=1;
	while(b>0){
		b++;
	}
	b-=1;
	printf("%u\n",b);
	
//	unsigned int c=0;
//	c=4294967295;
//	c-=1;
//	printf("%d",c);
	
	
	
	
	
	return 0;
}
