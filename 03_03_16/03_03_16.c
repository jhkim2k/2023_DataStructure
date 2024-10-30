#include <stdio.h>
#include <stdlib.h>

typedef struct test {
	int data;
	struct test* link;
} test_str;
void main()
{
	int i;
	test_str *ptest;
	ptest = (double*)malloc(sizeof(test_str));
	// 포인터 ptest를 동적으로 메모리 할당
	ptest->data = 10;
	ptest->link = NULL;
	// 포인터를 이용하여 구조체 안에 데이터 넣기
	printf("%d %d\n", ptest->data, ptest->link);
	//포인터를 이용하여 구조체에 넣었던 데이터를 출력해보기
	free(ptest);
}