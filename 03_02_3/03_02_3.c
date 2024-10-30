#include <stdio.h>
#include <string.h>
#include <math.h> // pow 함수와 sqrt 함수 쓰기 위한 라이브러리

typedef struct student {
	char name[100];
	int student_number;
	int score;
} student;

int get_mean(student *students, int n) { // 평균 구하기 함수
	int sum = 0, mean = 0;
	for (int i = 0; i < n; i++) {
		sum += students[i].score; // 학생들의 성적을 다 더해서 누적
	}
	mean = sum / n; // 학생 평균의 합을 학생 수에 나눈다.
	return mean; // 평균값 반환
}

double get_deviation(student *students, int n) {
	int sum = 0, mean = 0;
	double deviation = 0;
	for (int i = 0; i < n; i++) {
		sum += students[i].score;
	} // 학생들의 성적의 합을 구한다.
	mean = sum / n; // 학생 성적의 평균을 구한다.
	for (int i = 0; i < n; i++) {
		deviation += pow(students[i].score - mean, 2);
	} // 학생 각각의 성적에 평균을 뺀 값을 제곱한다.
	deviation = deviation / n; // 제곱한 값을 학생수에 나눈다.
	deviation = sqrt(deviation); // 나눈 값의 제곱근을 구한다.
	return deviation;
}

void main() {
	student students[1000] = {
		{"A", 11111111, 90},
		{"B", 22222222, 80},
		{"C", 33333333, 70}
	};

	int mean = get_mean(students, 3); // get_mean 함수로 평균값을 가져온다.
	double deviation = get_deviation(students, 3); // get_deviation 함수로 표준편차 값을 가져온다.

	printf("mean = %d, deviation = %f", mean, deviation); // 평균과 표준편차 값을 각각 출력한다.
}