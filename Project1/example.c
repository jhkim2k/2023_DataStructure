#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef char DataType; // 스택에 저장할 데이터 타입

typedef struct {
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

int isMatchingPair(char left, char right) {
    if (left == '(' && right == ')')      // 소괄호의 짝인지 확인
        return 1;
    else if (left == '[' && right == ']') // 대괄호의 짝인지 확인
        return 1;
    else if (left == '{' && right == '}') // 중괄호의 짝인지 확인
        return 1;
    else
        return 0;                         // 짝이 맞지 않는 경우
}

int isBalanced(char* expression) {
    ArrayStack stack;
    init_stack(&stack);

    int i;
    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            if (is_stack_full(&stack)) {
                printf("Stack overflow\n");
                return 0;
            }
            stack.stack[++stack.top] = expression[i]; // 왼쪽 괄호를 스택에 push
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (is_stack_empty(&stack)) {
                printf("Unbalanced parentheses at index %d\n", i);
                return 0;
            }
            DataType top = stack.stack[stack.top]; // 스택의 상단 괄호를 확인
            if (!isMatchingPair(top, expression[i])) {
                printf("Unbalanced parentheses at index %d\n", i);
                return 0;
            }
            stack.top--; // 짝이 맞는 경우 상단 괄호를 pop
        }
    }

    if (!is_stack_empty(&stack)) {
        printf("Unbalanced parentheses at index %d\n", stack.top);
        return 0;
    }

    return 1;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    if (isBalanced(expression))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are not balanced.\n");
    return 0;
}
