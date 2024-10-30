#include <stdio.h>
#define MAX_SIZE 100
#define DataType char
#define TRUE 1;
#define FALSE 0;
// 필요한 전처리구문을 include 하고, MAX_SIZE, DataType, TRUE, FALSE를 각각 100, char, 1, 0 으로 정의한다.
// 스택을 사용하기 위해 스택 구조체를 만든다.
typedef struct ArrayStack {
	int top;
	DataType stack[MAX_SIZE];
} ArrayStack;
// 스택을 초기화 하는 함수이고, top의 값이 -1이면 된다.
void init_stack(ArrayStack* AS) {
	AS->top = -1;
}
// 스택이 가득 차 있는지 판단하는 함수이다. 만약 가득 차 있다면 1을 return 한다.
int is_stack_full(ArrayStack* AS) {
	return AS->top == MAX_SIZE - 1;
}
// 스택이 비어 있는지 판단하는 함수이다. 만약 비어 있다면 1을 return 한다.
int is_stack_empty(ArrayStack* AS) {
	return AS->top == -1;
}
// 스택에 매개변수로 받은 값을 삽입하는 함수이다.
void push(ArrayStack* AS, char c) {
	if (is_stack_full(AS)) {
		printf("스택이 가득 차 있습니다!\n");
		exit(1);
	}
    // 만약 스택이 가득 차 있다면 문구를 출력하고 프로그램을 종료한다.
	AS->stack[++AS->top] = c;
}
// 스택에 들어있는 값 하나를 빼는 함수이다.
DataType pop(ArrayStack* AS) {
	if (is_stack_empty(AS)) {
		printf("스택이 비어 있습니다!\n");
		exit(1);
	}
    // 만약 스택이 비어있다면 문구를 출력하고, 종료한다.
	return AS->stack[AS->top--];
}
// 아래의 함수는 각각의 괄호가 짝이 맞는지 판별하는 코드이다.
// 두 매개변수를 받고 두 매개변수의 짝이 맞으면 1, 틀리면 0을 출력한다.
int check(char left, char right) {
    if (left == '(' && right == ')') {
        return TRUE;
    }
    else if (left == '{' && right == '}') {
        return TRUE;
    }
    else if (left == '[' && right == ']') {
        return TRUE;
    }
    else {
        return FALSE;
    }
    // 각각의 괄호를 각각 소중대 순으로 판별하게 된다.
}
// 이 함수는 입력받은 식에서 소중대 각각의 왼쪽 괄호를 만나면 스택에 입력해 처리하고, 오른쪽 괄호 만나면 짝이 맞는지 위의 check 함수로 보내는 과정을 수행한다. 
int Fairing(char* expression) {
    ArrayStack stack;
    init_stack(&stack);
    // 먼저 스택을 초기화 한다.
    // 입력 받은 식의 끝까지, 즉, 문자열의 끝까지 스캔한다. NULL이 나올때까지 스캔하면 된다.
    for (int i = 0; expression[i] != NULL; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        }
        // 왼괄호가 나오게 된다면 스택에 집어넣는다.
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (is_stack_empty(&stack)) {
                return FALSE;
            }
            // 오른괄호가 나왔는데 스택이 비어있다면 0을 return 한다.
            else {
                DataType top = pop(&stack);
                if (!check(top, expression[i])) {
                    return FALSE;
                }
            }
            // 비어있지 않다면 stack의 값을 꺼내 비교하고 짝이 맞지 않다면 0을 return 한다.
        }
    }
    if (!is_stack_empty(&stack)) {
        return FALSE;
    }
    // 위의 과정을 했음에도 스택에 값이 들어있다면 이는 왼 괄호가 남아있다는 것이고, 짝이 맞지 않는 식이므로 0을 return 한다.
    return TRUE;
    // 이 모든 과정을 거치면 짝이 맞는 식이므로 1을 return 한다.
}
// main 함수에서는 사용자로부터 식(문자열)을 입력받고, Fairing 함수의 매개변수로 넘겨준다.
int main() {
    char expression[MAX_SIZE];
    printf("식을 입력해 주세요.: ");
    scanf("%s", expression);
    if (Fairing(expression))
        printf("짝이 맞는 식 입니다.\n");
    else
        printf("짝이 맞지 않는 식 입니다.\n");
    // return 된 값에 따라 1이면 짝이 맞고, 0이면 짝이 맞지 않으므로 각각에 해당하는 결과를 출력한다.
    return 0;
}