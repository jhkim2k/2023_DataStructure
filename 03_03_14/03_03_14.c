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
	// 각 자료형에 맞는 포인터를 만들고, 동적으로 메모리 할당
	printf("pc = %lu\n", pc);
	printf("pc+1 = %lu\n", pc + 1);
	printf("pc-1 = %lu\n", pc - 1);
	// 포인터 pc의 값과 1을 더하고 뺐을때의 값 출력
	printf("pi = %lu\n", pi);
	printf("pi+1 = %lu\n", pi + 1);
	printf("pi-1 = %lu\n", pi - 1);
	// 포인터 pi의 값과 1을 더하고 뺐을때의 값 출력
	printf("pf = %lu\n", pf);
	printf("pf+1 = %lu\n", pf + 1);
	printf("pf-1 = %lu\n", pf - 1);
	// 포인터 pf의 값과 1을 더하고 뺐을때의 값 출력
	printf("pd = %lu\n", pd);
	printf("pd+1 = %lu\n", pd + 1);
	printf("pd-1 = %lu\n", pd - 1);
	// 포인터 pd의 값과 1을 더하고 뺐을때의 값 출력
	free(pc);
	free(pi);
	free(pf);
	free(pd);
	// 동적 할당 메모리 해제
}