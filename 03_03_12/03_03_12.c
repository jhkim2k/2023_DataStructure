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
	// �� �����Ϳ� �ڷ����� �´� ũ�� ��ŭ 100���� ����Ʈ�� �������� �Ҵ�
	for (int i = 0; i < 100; i++) {
		*(pc + i) = i;
		*(pi + i) = i;
		*(pf + i) = i;
		*(pd + i) = i;
	}
	// �����Ͱ� ����Ű�� ���� ���� 100���� ���� �Է�
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
	// ������ �����Ͱ� ����Ű�� ������ ���� ���

	/*
	free(pc);
	free(pi);
	free(pf);
	free(pd);
	*/
	// �������� �Ҵ�� �޸� ������ ���� ���� �ʰ� ���α׷� ����
}