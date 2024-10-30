#include <stdio.h>
void printArrayAddress(int[][3]);
void main(void)
{
	int array[2][3] = { {1, 2, 3}, {4, 5, 6} };
	printf("배열 array의 출력 : \n");
	printArrayAddress(array);
}
// 2차원 배열을 초기화 하여 선언하고, printArrayAddress 함수에 배열의 이름을 준다.
void printArrayAddress(int a[][3])
{
	int i, j;
	for (i = 0; i <= 1; i++) {
		for (j = 0; j <= 2; j++)
			printf("%p ", &a[i][j]);
		printf("\n");
	}
	
	// 각 행과 열에 맞추어 각각의 주소를 출력하게 된다.
	// 이때 같은 행의 값들이 우선적으로 먼저 출력되는 것을 알 수 있다.
}
