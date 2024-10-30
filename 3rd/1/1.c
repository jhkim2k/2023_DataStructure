#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
// ispunct�� tolower�� ���� ���� �����Ѵ�.
#include<string.h>
#define MAX_SIZE 100
#define DataType char
#define TRUE 1
#define FALSE 0
// �ʿ��� ��ó�� ������ MAX_SIZE, DataType, TRUE, FALSE�� ���� 100, char, 1, 0���� �����Ѵ�.
// ���� ����ü�� �����.
typedef struct ArrayStack {
	int top;
	DataType stack[MAX_SIZE];
} ArrayStack;
// ������ �ʱ�ȭ �ϴ� �Լ��̰�, top�� -1�� �ϸ� �ȴ�.
void init_stack(ArrayStack* AS) {
	AS->top = -1;
}
// ������ �� �� �ִ����� Ȯ���ϴ� �Լ��̴�.
int is_stack_full(ArrayStack* AS) {
	return AS->top == MAX_SIZE - 1;
	// �� ���ִٸ� 1�� return �Ѵ�.
}
// ������ ����ִ��� Ȯ���ϴ� �Լ��̴�.
int is_stack_empty(ArrayStack* AS) {
	return AS->top == -1;
	// ����ִٸ� 1�� retrun �ϰ� �ȴ�.
}
// �Ű������� �޾�, ���ÿ� �����ϴ� �Լ��̴�.
void push(ArrayStack* AS, char c) {
	if (is_stack_full(AS)) {
		printf("������ ���� �� �ֽ��ϴ�!\n");
		exit(1);
	}
	AS->stack[++AS->top] = c;
	// ������ �� ���ִ��� Ȯ���ϰ�, �ƴ϶�� �����Ѵ�.
	// ���� �� ���ִٸ� �޽����� ����ϰ� ���α׷��� �����Ѵ�.
}
// ������ ���� ������ ���� �Լ��̴�.
char pop(ArrayStack* AS) {
	if (is_stack_empty(AS)) {
		printf("������ ��� �ֽ��ϴ�!\n");
		exit(1);
	}
	return AS->stack[AS->top--];
	// ���� �� �����̶�� �޽��� ��� �� �����ϰ�, �ƴ϶�� ���� ������ ����.
}
// ȸ������ �Ǵ��ϴ� �Լ��̴�. �Ű������� �Է¹��� ���ڿ��� �޴´�.
int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str);

	init_stack(&s); // ������ �ʱ�ȭ�϶�
	// ���� ������ �ʱ�ȭ�Ѵ�. 
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if (ch == ' ' || ispunct(ch)) continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		push(&s, ch); // ���ÿ� �����Ѵ�.
	}
	// �����̽� �� �������� �����ϰ�, �ҹ��ڷ� �ٲپ� ���ÿ� �����Ѵ�.
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if (ch == ' ' || ispunct(ch)) continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		chs = pop(&s); // ���ÿ��� ���ڸ� ������
		if (ch != chs) return FALSE; // ����
	}
	// ���ÿ��� ������ ���ڿ��� ������ ���Ƿ� �����鼭 �������� �Ǵ��ϰ�, �̸� ���� ȸ������ �˾Ƴ���.
	return TRUE; // ����
}

int main() {
	char str[MAX_SIZE];
	printf("���ڿ��� �Է��ϼ���: ");
	scanf("%[^\n]s", str);
	// �̰��� �ٹٲ��� �Ͼ�� �������� ��� ���ڸ� �Է¹޵����ϴ� ���̴�. 
	// �� �ڵ忡���� �����̽��� ���� ������ ������ ��� ���ڿ��� �� �Է� �޾ƾ� �ϹǷ� �̷��� ����� ����ؾ� �Ѵ�.
	if (palindrome(str)) {
		printf("ȸ���Դϴ�.\n");
	}
	else {
		printf("ȸ���� �ƴմϴ�.\n");
	}
	// palindrome �Լ��� ����Ͽ� retrun ���� ������ ȸ������ �ƴ��� ����ڿ��� �˷��ְ� ���α׷��� �����Ѵ�.
	return 0;
}
