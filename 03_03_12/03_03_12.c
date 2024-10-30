#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void main() {
	char* pc;
	int* pi;
	float* pf;
	double* pd;

	pc = (char*)malloc(100 * sizeof(char));
	pi = (int*)malloc(100 * sizeof(int));
	pf = (float*)malloc(100 * sizeof(float));
	pd = (double*)malloc(100 * sizeof(double));
	// 각 포인터에 자료형에 맞는 크기 만큼 100개의 바이트를 동적으로 할당
	for (int i = 0; i < 100; i++) {
		*(pc + i) = i;
		*(pi + i) = i;
		*(pf + i) = i;
		*(pd + i) = i;
	}
	// 포인터가 가리키는 곳에 각각 100개의 값을 입력
	for (int i = 0; i < 100; i++) {
		printf("%d ", *(pc + i));
	}
	printf("\n");
	for (int i = 0; i < 100; i++) {
		printf("%d ", *(pi + i));
	}
	printf("\n");
	for (int i = 0; i < 100; i++) {
		printf("%f ", *(pf + i));
	}
	printf("\n");
	for (int i = 0; i < 100; i++) {
		printf("%f ", *(pd + i));
	}
	printf("\n");
	// 각각의 포인터가 가리키는 곳들의 값을 출력

	/*
	free(pc);
	free(pi);
	free(pf);
	free(pd);
	*/
	// 동적으로 할당된 메모리 공간을 해제 하지 않고 프로그램 종료
}