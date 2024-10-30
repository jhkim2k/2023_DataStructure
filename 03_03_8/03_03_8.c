#include <stdio.h>
char *pa[] = {
	"에러 1",
	"에러 2",
	"에러 3",
	"에러 4",
	"에러 5",
	"에러 6"
};// 포인터 배열 선언
void error(int err_num)
{
	printf(pa[err_num]); // 값을 받아 포인터 배열을 호출한다.
}
main()
{
	error(1);
}