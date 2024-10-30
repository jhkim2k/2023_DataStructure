#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void main()
{
	int i;
	char* pc;
	pc = (char*)malloc(100);
	// 동적 메모리 할당으로 100바이트 만큼의 공간을 할당
	for (i = 0; i < 100; i++) {
		*pc = 100;
	}
	// 포인터 pc가 가리키는 곳에 100 값을 100번 저장한다.
	free(pc);
	// pc의 동적로 할당한 메모리 공간을 해제한다.
}