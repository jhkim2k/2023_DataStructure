#include <stdio.h>
#define SIZE 10

int matrix_diff(int a[], int b[], int c[]) {
	// ũ�⸦ ������ �迭�� �ް�, �迭�� ũ�� ���� �޴´�.
	for (int n = 0; n < SIZE; n++)
		c[n] = a[n] - b[n];
	// a, b �迭�� ���� c �迭�� ����
}

int main() {
	int a[SIZE] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int b[SIZE] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int c[SIZE];
	// ������ ������ �迭 a, b �ʱ�ȭ �� ������ �迭 c �����

	matrix_diff(a, b, c);
	// �Լ��� �迭�� �̸� �� ũ�� ����
	 
	for (int n = 0; n < SIZE; n++) {

		printf("c[%d] : %d \n", n, c[n]);
	}
	// ������ �� ����Ǿ������� �ľ��ϱ� ���� �ݺ��� ���

	return 0;
}