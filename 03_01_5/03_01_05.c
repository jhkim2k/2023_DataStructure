#include <stdio.h>
#define LIST_SIZE 10
int list[LIST_SIZE] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };
// 배열의 크기만큼 배열을 초기화 하여 선언
main()
{
	int i;
	for (i = 0; i < LIST_SIZE; i++) {
		printf("list[%d]의 주소 = %p\n", i, &list[i]);
	}
	// for 반복문을 이용하여 각각 배열의 원소에 대한 주소를 호출한다. 이때 각 원소의 주소를 호출할때는 %p 연산자를 사용하여 호출하게 된다.
}