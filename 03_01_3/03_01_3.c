#include <stdio.h>
#include <stdlib.h>

int random(int a[], int s) {
	for (int n = 0; n < s; n++)
		a[n] = rand();
	// �迭�� ���鸶�� ���� ���� �ο��ϱ�
}


int main() {
	int arr[10];
	// ũ�Ⱑ 10�� �迭 arr ����

	random(arr, 10);
	// random �Լ��� �迭�� �̸��� ũ�� ����

	int max = arr[0], min = arr[0];
	// �ִ밪, �ּҰ� ���� max, min ���� �� �迭�� ù��° ���� �ʱ�ȭ

	for (int i = 0; i < 10; i++) {
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min) {
			min = arr[i];
		}
		// �迭 �� ������ ũ�� ���� �ִ�, �ּҰ����� ���Ƴֱ�
	}

	for (int n = 0; n < 10; n++)
		printf("%d ", arr[n]);
	// �迭�� ���� ȣ���Ͽ� ��� ���� ����ִ��� Ȯ��

	printf("�ִ� : %d, �ּ� : %d\n", max, min);
	// �ִ�, �ּҰ� ���

	return 0;
}


