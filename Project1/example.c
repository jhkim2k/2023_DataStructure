#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef char DataType; // ���ÿ� ������ ������ Ÿ��

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
    if (left == '(' && right == ')')      // �Ұ�ȣ�� ¦���� Ȯ��
        return 1;
    else if (left == '[' && right == ']') // ���ȣ�� ¦���� Ȯ��
        return 1;
    else if (left == '{' && right == '}') // �߰�ȣ�� ¦���� Ȯ��
        return 1;
    else
        return 0;                         // ¦�� ���� �ʴ� ���
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
            stack.stack[++stack.top] = expression[i]; // ���� ��ȣ�� ���ÿ� push
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (is_stack_empty(&stack)) {
                printf("Unbalanced parentheses at index %d\n", i);
                return 0;
            }
            DataType top = stack.stack[stack.top]; // ������ ��� ��ȣ�� Ȯ��
            if (!isMatchingPair(top, expression[i])) {
                printf("Unbalanced parentheses at index %d\n", i);
                return 0;
            }
            stack.top--; // ¦�� �´� ��� ��� ��ȣ�� pop
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
