#include<stdio.h>
#include <math.h>
#include<string.h>

int main(void)
{
	char str[500001];
	char* p;
	int i, len, flag = 0;							//flag检测空格
	
	gets(str);
	
	len = strlen(str);								//字符串长度
	
	for (i = len; i >= 0; i--) {					//从字符串末尾倒着读
		if (str[i] == ' '&& flag) {					//当读到空格且是单词前一位的空格时
			p = &str[i];							//指针指向空格所在地址
			printf("%s", p + 1);					//输出p+1字符串
			if (str[0]!=' ') printf(" ");			//避免前有空格多输出空格(第3测试点)
			*p = '\0';								//p后字符串扔掉
			flag = 0;								//再碰到空格不输出
		}
		if (str[i] == ' ') {						//仅仅只有空格
			p = &str[i];
			*p = '\0';
			flag = 0;								
		}
		if (str[i]!=' ' && str[i]!='\0') flag = 1;	//读到非空格且不是'\0'('\0'也是非空格,小心),重新立flag
	}
	p = &str[0];
	printf("%s", p);								//读第一个单词
	
	return 0;
}



