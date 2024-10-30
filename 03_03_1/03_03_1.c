#include <stdio.h>
#include <stdlib.h>

void main() {
	char *pc;
	int *pi;
	float *pf;
	double *pd;
	// 포인터들을 선언
	pc = NULL;
	pi = NULL;
	pf = NULL;
	pd = NULL;
	// 포인터 pc, pi, pf, pd를 NULL 초기화
	char c;
	int i;
	float f;
	double d;

	printf("pc = %lu\n", pc);
	// 변수들을 선언
	printf("초기화 하기 전의 pc = %lu, pi = %lu, pf = %lu, pd = %lu\n", pc, pi, pf, pd); // pc, pi, pf, pd 값 출력
	pc = &c;
	pi = &i;
	pf = &f;
	pd = &d;
	// pc, pi, pf, pd 초기화
	printf("초기화 하기 후의 pc = %lu, pi = %lu, pf = %lu, pd = %lu\n", pc, pi, pf, pd); // pc, pi, pf, pd 값 출력
	*pc = 100;
	*pi = 100;
	*pf = 100;
	*pd = 100;
	// pc, pi, pf, pd가 가리키는 곳의 값 변경
	printf("c = %d, i = %d, f = %f, d = %f\n", c, i, f, d);
	// 변경된 값들을 출력
}




