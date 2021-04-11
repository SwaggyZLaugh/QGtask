#include "calculator.h"
#include <stdio.h>

int symboljudge(char x,char y)//判断运算符号优先级 
{
	if((x=='*'||x=='/')&&(y=='+'||y=='-')) return 1;//x运算优先级大于y则返回1 
	else return 0;//否则返回0 
}
