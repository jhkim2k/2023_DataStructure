#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void main()
{
	int i;
	char* pc;
	pc = (char*)malloc(100);
	// ���� �޸� �Ҵ����� 100����Ʈ ��ŭ�� ������ �Ҵ�
	for (i = 0; i < 100; i++) {
		*pc = 100;
	}
	// ������ pc�� ����Ű�� ���� 100 ���� 100�� �����Ѵ�.
	free(pc);
	// pc�� ������ �Ҵ��� �޸� ������ �����Ѵ�.
}