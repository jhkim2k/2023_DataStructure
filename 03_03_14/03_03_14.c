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
	// �� �ڷ����� �´� �����͸� �����, �������� �޸� �Ҵ�
	printf("pc = %lu\n", pc);
	printf("pc+1 = %lu\n", pc + 1);
	printf("pc-1 = %lu\n", pc - 1);
	// ������ pc�� ���� 1�� ���ϰ� �������� �� ���
	printf("pi = %lu\n", pi);
	printf("pi+1 = %lu\n", pi + 1);
	printf("pi-1 = %lu\n", pi - 1);
	// ������ pi�� ���� 1�� ���ϰ� �������� �� ���
	printf("pf = %lu\n", pf);
	printf("pf+1 = %lu\n", pf + 1);
	printf("pf-1 = %lu\n", pf - 1);
	// ������ pf�� ���� 1�� ���ϰ� �������� �� ���
	printf("pd = %lu\n", pd);
	printf("pd+1 = %lu\n", pd + 1);
	printf("pd-1 = %lu\n", pd - 1);
	// ������ pd�� ���� 1�� ���ϰ� �������� �� ���
	free(pc);
	free(pi);
	free(pf);
	free(pd);
	// ���� �Ҵ� �޸� ����
}