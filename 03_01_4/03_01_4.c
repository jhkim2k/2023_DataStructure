#include <stdio.h>

void search(int a[], int num, int *l) {
	// loc 값이 바뀌어야 하기에 포인터를 사용한다.
	for (int n = 0; n < 10; n++) {
		if (a[n] == num) {
			*l = n;
			return;
		}
		// for 반복문을 이용하여 각각의 원소들을 사용자가 원하는 값과 비교하고 맞으면 return한다.
	}
	*l = -1;
	// 만약 찾고자 하는 값이 없다면 loc 값에 -1을 넣게 된다.
}

int main() {
	int a[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };
	int num = 0, loc = 0;
	// 배열을 문제에서 제시한대로 초기화 한다.
	// 찾고자 하는 값을 num, 위치를 loc 변수로 선언한다.

	printf("원하는 값을 입력하시오. : ");
	scanf("%d", &num);
	// 사용자로부터 찾고자 하는 값을 입력받는다.

	search(a, num, &loc);
	// search 함수에 배열은 이름을 주고 num 값과 loc 변수의 주소를 준다.

	if (loc == -1)
		printf("찾는 값의 위치가 없음\n");
	else
		printf("찾는 값은 배열의 %d 번째 원소\n", loc + 1);
	// loc 값이 -1이면 찾고자 하는 값이 없는 것이고, 아니라면 loc값에 1을 더해서 출력한다.(첫번째 요소가 a[0]이기 때문)
	return 0;
}