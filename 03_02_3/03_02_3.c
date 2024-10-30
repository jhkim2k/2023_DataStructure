#include <stdio.h>
#include <string.h>
#include <math.h> // pow �Լ��� sqrt �Լ� ���� ���� ���̺귯��

typedef struct student {
	char name[100];
	int student_number;
	int score;
} student;

int get_mean(student *students, int n) { // ��� ���ϱ� �Լ�
	int sum = 0, mean = 0;
	for (int i = 0; i < n; i++) {
		sum += students[i].score; // �л����� ������ �� ���ؼ� ����
	}
	mean = sum / n; // �л� ����� ���� �л� ���� ������.
	return mean; // ��հ� ��ȯ
}

double get_deviation(student *students, int n) {
	int sum = 0, mean = 0;
	double deviation = 0;
	for (int i = 0; i < n; i++) {
		sum += students[i].score;
	} // �л����� ������ ���� ���Ѵ�.
	mean = sum / n; // �л� ������ ����� ���Ѵ�.
	for (int i = 0; i < n; i++) {
		deviation += pow(students[i].score - mean, 2);
	} // �л� ������ ������ ����� �� ���� �����Ѵ�.
	deviation = deviation / n; // ������ ���� �л����� ������.
	deviation = sqrt(deviation); // ���� ���� �������� ���Ѵ�.
	return deviation;
}

void main() {
	student students[1000] = {
		{"A", 11111111, 90},
		{"B", 22222222, 80},
		{"C", 33333333, 70}
	};

	int mean = get_mean(students, 3); // get_mean �Լ��� ��հ��� �����´�.
	double deviation = get_deviation(students, 3); // get_deviation �Լ��� ǥ������ ���� �����´�.

	printf("mean = %d, deviation = %f", mean, deviation); // ��հ� ǥ������ ���� ���� ����Ѵ�.
}