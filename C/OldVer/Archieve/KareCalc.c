#include <stdio.h>
int main()
{
	int sum=0,a=0;   //sum是总结果，a是用来临时读取数字并参与后续运算的
	char c=' ';      //初始化字符
	scanf("%d",&sum);//先读取一个数字，作为初值
	while(1){        //用一个暂时的死循环进行重复读取，后续处理的时候跳出死循环
		c=getchar(); //读取一个字符
		switch(c){   //判断字符是哪一种类型，执行不同操作
			case '+': scanf("%d",&a);sum+=a;break;
			case '-': scanf("%d",&a);sum-=a;break;
			case '*': scanf("%d",&a);sum*=a;break;
			case '/': //除法的时候如果读取的下一个数字是0，就直接跳出死循环结束程序
			{
				scanf("%d",&a);
				if(a==0){
					printf("ERROR");
					return 0;
				}
				else{
					sum/=a;
				}
				break;
			}
			case '=': //如果一路正常走到了最后读取‘=’，那么肯定有一个计算好的sum，输出即可
			{
				printf("%d",sum);
				return 0;
			}
			default: //读取到其他奇怪字符的时候，同除数为0，直接跳出死循环
			{
				printf("ERROR");
				return 0;
			}
		}
	}
}
