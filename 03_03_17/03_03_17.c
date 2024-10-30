#include <stdio.h>
#include <stdlib.h>

void main() {
	int *pi;
	pi = (int*)malloc(100 * sizeof(char));
	// 동적할당이 된 공간은 char 타입이나, 포인터는 int 이다.
	// char 100개 만큼의 공간을 받았으나 int 포인터인 경우
}