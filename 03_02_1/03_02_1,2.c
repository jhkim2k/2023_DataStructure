#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[100]; // ũ�Ⱑ 100�� ���ڿ� ���� �迭
	int student_number; // �й��� ��Ÿ��
	int score; // �л��� ������ ��ϵ�
} student;

int main() {
	student students[1000] = {
		{"A", 11111111, 90},
		{"B", 22222222, 80},
		{"C", 33333333, 70}
	};
	// A,B,C �л��� ���� �̸�, �й�, ���� ���� ����
}