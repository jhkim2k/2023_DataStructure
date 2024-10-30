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
		printf("스택이 가득 차 있습니다!\n");
		exit(1);
	}
	AS->stack[++AS->top] = c;
}

char pop(ArrayStack* AS) {
	if (is_stack_empty(AS)) {
		printf("스택이 비어 있습니다!\n");
		exit(1);
	}
	return AS->stack[AS->top--];
}

int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str);

	init_stack(&s); // 스택을 초기화하라
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// 만약 ch가 스페이스거나 구두점이면
		if (ch == ' ' || ispunct(ch)) continue;
		ch = tolower(ch); // ch를 소문자로 변경
		push(&s, ch); // 스택에 삽입한다.
	}
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// 만약 ch가 스페이스거나 구두점이면
		if (ch == ' ' || ispunct(ch)) continue;
		ch = tolower(ch); // ch를 소문자로 변경
		chs = pop(&s); // 스택에서 문자를 꺼낸다
		if (ch != chs) return FALSE; // 실패
	}
	return TRUE; // 성공
}

int main() {
	char str[MAX_SIZE];
	printf("문자열을 입력하세요: ");
	scanf("%[^\n]s", str);
	if (palindrome(str)) {
		printf("회문입니다.\n");
	}
	else {
		printf("회문이 아닙니다.\n");
	}
	return 0;
}
