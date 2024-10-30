#include <stdio.h>
#include <stdlib.h>

int random(int a[], int s) {
	for (int n = 0; n < s; n++)
		a[n] = rand();
	// 배열의 값들마다 랜덤 값을 부여하기
}


int main() {
	int arr[10];
	// 크기가 10인 배열 arr 선언

	random(arr, 10);
	// random 함수에 배열의 이름과 크기 전달

	int max = arr[0], min = arr[0];
	// 최대값, 최소값 변수 max, min 선언 후 배열의 첫번째 원소 초기화

	for (int i = 0; i < 10; i++) {
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min) {
			min = arr[i];
		}
		// 배열 각 원소의 크기 비교후 최대, 최소값으로 몰아넣기
	}

	for (int n = 0; n < 10; n++)
		printf("%d ", arr[n]);
	// 배열의 값을 호출하여 어떠한 값이 들어있는지 확인

	printf("최대 : %d, 최소 : %d\n", max, min);
	// 최대, 최소값 출력

	return 0;
}


