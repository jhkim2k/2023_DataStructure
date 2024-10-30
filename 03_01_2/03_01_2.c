#include <stdio.h>
#define SIZE 10

int matrix_diff(int a[], int b[], int c[]) {
	// 크기를 생략한 배열로 받고, 배열의 크기 또한 받는다.
	for (int n = 0; n < SIZE; n++)
		c[n] = a[n] - b[n];
	// a, b 배열의 차를 c 배열에 저장
}

int main() {
	int a[SIZE] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int b[SIZE] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int c[SIZE];
	// 임의의 값으로 배열 a, b 초기화 및 저장할 배열 c 만들기

	matrix_diff(a, b, c);
	// 함수로 배열의 이름 및 크기 전달
	 
	for (int n = 0; n < SIZE; n++) {

		printf("c[%d] : %d \n", n, c[n]);
	}
	// 연산이 잘 수행되어졌는지 파악하기 위한 반복분 출력

	return 0;
}