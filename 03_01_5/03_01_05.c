#include <stdio.h>
#define LIST_SIZE 10
int list[LIST_SIZE] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };
// �迭�� ũ�⸸ŭ �迭�� �ʱ�ȭ �Ͽ� ����
main()
{
	int i;
	for (i = 0; i < LIST_SIZE; i++) {
		printf("list[%d]�� �ּ� = %p\n", i, &list[i]);
	}
	// for �ݺ����� �̿��Ͽ� ���� �迭�� ���ҿ� ���� �ּҸ� ȣ���Ѵ�. �̶� �� ������ �ּҸ� ȣ���Ҷ��� %p �����ڸ� ����Ͽ� ȣ���ϰ� �ȴ�.
}