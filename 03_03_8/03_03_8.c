#include <stdio.h>
char *pa[] = {
	"���� 1",
	"���� 2",
	"���� 3",
	"���� 4",
	"���� 5",
	"���� 6"
};// ������ �迭 ����
void error(int err_num)
{
	printf(pa[err_num]); // ���� �޾� ������ �迭�� ȣ���Ѵ�.
}
main()
{
	error(1);
}