#include "calculator.h"
#include <stdio.h>

int symboljudge(char x,char y)//�ж�����������ȼ� 
{
	if((x=='*'||x=='/')&&(y=='+'||y=='-')) return 1;//x�������ȼ�����y�򷵻�1 
	else return 0;//���򷵻�0 
}
