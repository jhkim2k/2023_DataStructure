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
	// ������ ptest�� �������� �޸� �Ҵ�
	ptest->data = 10;
	ptest->link = NULL;
	// �����͸� �̿��Ͽ� ����ü �ȿ� ������ �ֱ�
	printf("%d %d\n", ptest->data, ptest->link);
	//�����͸� �̿��Ͽ� ����ü�� �־��� �����͸� ����غ���
	free(ptest);
}