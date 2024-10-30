#include <stdio.h >
void swap1(int i, int j);
void swap2(int* i, int* j);
// 값을 넘기는 swap1, 포인터를 사용해 주소를 주는 swap2 함수를 만든다.
void main()
{
	int num1, num2;
	num1 = 100;
	num2 = 200;
	swap1(num1, num2);
	printf("num1 : %d num2 : %d\n", num1, num2);
	swap2(&num1, &num2);
	printf("num1 : %d num2 : %d\n", num1, num2);
	// 각 함수에 대한 결과 값을 호출한다.
}
// 값을 넘겨주는 함수 생성
void swap1(int i, int j)
{
	int temp;
	temp = i;
	i = j;
	j = temp;
}
// 포인터를 이용해 주소를 넘겨주는 함수 생성
void swap2(int* i, int* j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}