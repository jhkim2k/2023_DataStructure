#include <stdio.h>
#include <stdlib.h>

void main() {
	char *pc;
	int *pi;
	float *pf;
	double *pd;
	// �����͵��� ����
	pc = NULL;
	pi = NULL;
	pf = NULL;
	pd = NULL;
	// ������ pc, pi, pf, pd�� NULL �ʱ�ȭ
	char c;
	int i;
	float f;
	double d;

	printf("pc = %lu\n", pc);
	// �������� ����
	printf("�ʱ�ȭ �ϱ� ���� pc = %lu, pi = %lu, pf = %lu, pd = %lu\n", pc, pi, pf, pd); // pc, pi, pf, pd �� ���
	pc = &c;
	pi = &i;
	pf = &f;
	pd = &d;
	// pc, pi, pf, pd �ʱ�ȭ
	printf("�ʱ�ȭ �ϱ� ���� pc = %lu, pi = %lu, pf = %lu, pd = %lu\n", pc, pi, pf, pd); // pc, pi, pf, pd �� ���
	*pc = 100;
	*pi = 100;
	*pf = 100;
	*pd = 100;
	// pc, pi, pf, pd�� ����Ű�� ���� �� ����
	printf("c = %d, i = %d, f = %f, d = %f\n", c, i, f, d);
	// ����� ������ ���
}




