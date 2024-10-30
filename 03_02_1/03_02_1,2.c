#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[100]; // 크기가 100인 문자열 저장 배열
	int student_number; // 학번을 나타냄
	int score; // 학생들 성적이 기록됨
} student;

int main() {
	student students[1000] = {
		{"A", 11111111, 90},
		{"B", 22222222, 80},
		{"C", 33333333, 70}
	};
	// A,B,C 학생에 대한 이름, 학번, 성적 정보 저장
}