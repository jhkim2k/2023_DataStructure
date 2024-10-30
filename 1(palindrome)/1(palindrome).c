#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_SIZE 100
#define DataType int
#define TRUE 1
#define FALSE 0

typedef struct ArrayStack {
	int top;
	DataType stack[MAX_SIZE];
} ArrayStack;

void init_stack(ArrayStack* AS) {
	AS->top = -1;
}

int is_stack_full(ArrayStack* AS) {
	return AS->top == MAX_SIZE - 1;
}

int is_stack_empty(ArrayStack* AS) {
	return AS->top == -1;
}

void push(ArrayStack* AS, char c) {
	if (is_stack_full(AS)) {
		printf("������ ���� �� �ֽ��ϴ�!\n");
		exit(1);
	}
	AS->stack[++AS->top] = c;
}

char pop(ArrayStack* AS) {
	if (is_stack_empty(AS)) {
		printf("������ ��� �ֽ��ϴ�!\n");
		exit(1);
	}
	return AS->stack[AS->top--];
}

int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str);

	init_stack(&s); // ������ �ʱ�ȭ�϶�
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if (ch == ' ' || ispunct(ch)) continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		push(&s, ch); // ���ÿ� �����Ѵ�.
	}
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// ���� ch�� �����̽��ų� �������̸�
		if (ch == ' ' || ispunct(ch)) continue;
		ch = tolower(ch); // ch�� �ҹ��ڷ� ����
		chs = pop(&s); // ���ÿ��� ���ڸ� ������
		if (ch != chs) return FALSE; // ����
	}
	return TRUE; // ����
}

int main() {
	char str[MAX_SIZE];
	printf("���ڿ��� �Է��ϼ���: ");
	scanf("%[^\n]s", str);
	if (palindrome(str)) {
		printf("ȸ���Դϴ�.\n");
	}
	else {
		printf("ȸ���� �ƴմϴ�.\n");
	}
	return 0;
}
