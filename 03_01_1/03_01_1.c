#include <stdio.h>

int main() {
	int i;
	int day[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// for 반복문을 위한 변수 i와 배열 초기화

	for ( i = 0; i < 12; i++)
		printf("%d월은 %d일까지 있습니다.\n", i+1, day[i]);
	// for 반복문으로 1월부터 12월까지의 일 수를 출력
	
	return 0;
}