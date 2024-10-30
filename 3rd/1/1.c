#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
// ispunct와 tolower을 쓰기 위해 선언한다.
#include<string.h>
#define MAX_SIZE 100
#define DataType char
#define TRUE 1
#define FALSE 0
// 필요한 전처리 구문과 MAX_SIZE, DataType, TRUE, FALSE를 각각 100, char, 1, 0으로 정의한다.
// 스택 구조체를 만든다.
typedef struct ArrayStack {
	int top;
	DataType stack[MAX_SIZE];
} ArrayStack;
// 스택을 초기화 하는 함수이고, top를 -1로 하면 된다.
void init_stack(ArrayStack* AS) {
	AS->top = -1;
}
// 스택이 꽉 차 있는지를 확인하는 함수이다.
int is_stack_full(ArrayStack* AS) {
	return AS->top == MAX_SIZE - 1;
	// 꽉 차있다면 1을 return 한다.
}
// 스택이 비어있는지 확인하는 함수이다.
int is_stack_empty(ArrayStack* AS) {
	return AS->top == -1;
	// 비어있다면 1을 retrun 하게 된다.
}
// 매개변수를 받아, 스택에 삽입하는 함수이다.
void push(ArrayStack* AS, char c) {
	if (is_stack_full(AS)) {
		printf("스택이 가득 차 있습니다!\n");
		exit(1);
	}
	AS->stack[++AS->top] = c;
	// 스택이 꽉 차있는지 확인하고, 아니라면 삽입한다.
	// 만약 꽉 차있다면 메시지를 출력하고 프로그램을 종료한다.
}
// 스택의 값을 밖으로 빼는 함수이다.
char pop(ArrayStack* AS) {
	if (is_stack_empty(AS)) {
		printf("스택이 비어 있습니다!\n");
		exit(1);
	}
	return AS->stack[AS->top--];
	// 만약 빈 스택이라면 메시지 출력 후 종료하고, 아니라면 값을 밖으로 뺀다.
}
// 회문인지 판단하는 함수이다. 매개변수로 입력받을 문자열을 받는다.
int palindrome(char in_str[]) {
	ArrayStack s;
	int i;
	char ch, chs;
	int len = strlen(in_str);

	init_stack(&s); // 스택을 초기화하라
	// 먼저 스택을 초기화한다. 
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// 만약 ch가 스페이스거나 구두점이면
		if (ch == ' ' || ispunct(ch)) continue;
		ch = tolower(ch); // ch를 소문자로 변경
		push(&s, ch); // 스택에 삽입한다.
	}
	// 스페이스 및 구두점은 배제하고, 소문자로 바꾸어 스택에 삽입한다.
	for (i = 0; i < len; i++) {
		ch = in_str[i];
		// 만약 ch가 스페이스거나 구두점이면
		if (ch == ' ' || ispunct(ch)) continue;
		ch = tolower(ch); // ch를 소문자로 변경
		chs = pop(&s); // 스택에서 문자를 꺼낸다
		if (ch != chs) return FALSE; // 실패
	}
	// 스택에서 꺼내면 문자열은 뒤집어 지므로 꺼내면서 같은지를 판단하고, 이를 통해 회문인지 알아낸다.
	return TRUE; // 성공
}

int main() {
	char str[MAX_SIZE];
	printf("문자열을 입력하세요: ");
	scanf("%[^\n]s", str);
	// 이것은 줄바꿈이 일어나기 전까지의 모든 문자를 입력받도록하는 것이다. 
	// 이 코드에서는 스페이스로 인한 공백을 포함한 모든 문자열을 다 입력 받아야 하므로 이러한 방식을 사용해야 한다.
	if (palindrome(str)) {
		printf("회문입니다.\n");
	}
	else {
		printf("회문이 아닙니다.\n");
	}
	// palindrome 함수를 사용하여 retrun 받을 값으로 회문인지 아닌지 사용자에게 알려주고 프로그램을 종료한다.
	return 0;
}
