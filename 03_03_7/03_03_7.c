#include <stdio.h>
void main(void)
{
	char str[] = "What is Pointer?";
	char* p;
	int i;
	p = str; // 포인터에 배열의 주소를 준다.
	/* 널 문자가 발견될 때까지 반복한다. */
	for (i = 0; p[i] != NULL; i++)
		printf("%c", p[i]); 
}