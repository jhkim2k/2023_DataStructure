#include <stdio.h >
void swap1(int i, int j);
void swap2(int* i, int* j);
// ���� �ѱ�� swap1, �����͸� ����� �ּҸ� �ִ� swap2 �Լ��� �����.
void main()
{
	int num1, num2;
	num1 = 100;
	num2 = 200;
	swap1(num1, num2);
	printf("num1 : %d num2 : %d\n", num1, num2);
	swap2(&num1, &num2);
	printf("num1 : %d num2 : %d\n", num1, num2);
	// �� �Լ��� ���� ��� ���� ȣ���Ѵ�.
}
// ���� �Ѱ��ִ� �Լ� ����
void swap1(int i, int j)
{
	int temp;
	temp = i;
	i = j;
	j = temp;
}
// �����͸� �̿��� �ּҸ� �Ѱ��ִ� �Լ� ����
void swap2(int* i, int* j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}