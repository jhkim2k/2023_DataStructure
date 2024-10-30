#include <stdio.h>
#define MAX_SIZE 100
#define DataType char
#define TRUE 1;
#define FALSE 0;
// �ʿ��� ��ó�������� include �ϰ�, MAX_SIZE, DataType, TRUE, FALSE�� ���� 100, char, 1, 0 ���� �����Ѵ�.
// ������ ����ϱ� ���� ���� ����ü�� �����.
typedef struct ArrayStack {
	int top;
	DataType stack[MAX_SIZE];
} ArrayStack;
// ������ �ʱ�ȭ �ϴ� �Լ��̰�, top�� ���� -1�̸� �ȴ�.
void init_stack(ArrayStack* AS) {
	AS->top = -1;
}
// ������ ���� �� �ִ��� �Ǵ��ϴ� �Լ��̴�. ���� ���� �� �ִٸ� 1�� return �Ѵ�.
int is_stack_full(ArrayStack* AS) {
	return AS->top == MAX_SIZE - 1;
}
// ������ ��� �ִ��� �Ǵ��ϴ� �Լ��̴�. ���� ��� �ִٸ� 1�� return �Ѵ�.
int is_stack_empty(ArrayStack* AS) {
	return AS->top == -1;
}
// ���ÿ� �Ű������� ���� ���� �����ϴ� �Լ��̴�.
void push(ArrayStack* AS, char c) {
	if (is_stack_full(AS)) {
		printf("������ ���� �� �ֽ��ϴ�!\n");
		exit(1);
	}
    // ���� ������ ���� �� �ִٸ� ������ ����ϰ� ���α׷��� �����Ѵ�.
	AS->stack[++AS->top] = c;
}
// ���ÿ� ����ִ� �� �ϳ��� ���� �Լ��̴�.
DataType pop(ArrayStack* AS) {
	if (is_stack_empty(AS)) {
		printf("������ ��� �ֽ��ϴ�!\n");
		exit(1);
	}
    // ���� ������ ����ִٸ� ������ ����ϰ�, �����Ѵ�.
	return AS->stack[AS->top--];
}
// �Ʒ��� �Լ��� ������ ��ȣ�� ¦�� �´��� �Ǻ��ϴ� �ڵ��̴�.
// �� �Ű������� �ް� �� �Ű������� ¦�� ������ 1, Ʋ���� 0�� ����Ѵ�.
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
    // ������ ��ȣ�� ���� ���ߴ� ������ �Ǻ��ϰ� �ȴ�.
}
// �� �Լ��� �Է¹��� �Ŀ��� ���ߴ� ������ ���� ��ȣ�� ������ ���ÿ� �Է��� ó���ϰ�, ������ ��ȣ ������ ¦�� �´��� ���� check �Լ��� ������ ������ �����Ѵ�. 
int Fairing(char* expression) {
    ArrayStack stack;
    init_stack(&stack);
    // ���� ������ �ʱ�ȭ �Ѵ�.
    // �Է� ���� ���� ������, ��, ���ڿ��� ������ ��ĵ�Ѵ�. NULL�� ���ö����� ��ĵ�ϸ� �ȴ�.
    for (int i = 0; expression[i] != NULL; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        }
        // �ް�ȣ�� ������ �ȴٸ� ���ÿ� ����ִ´�.
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (is_stack_empty(&stack)) {
                return FALSE;
            }
            // ������ȣ�� ���Դµ� ������ ����ִٸ� 0�� return �Ѵ�.
            else {
                DataType top = pop(&stack);
                if (!check(top, expression[i])) {
                    return FALSE;
                }
            }
            // ������� �ʴٸ� stack�� ���� ���� ���ϰ� ¦�� ���� �ʴٸ� 0�� return �Ѵ�.
        }
    }
    if (!is_stack_empty(&stack)) {
        return FALSE;
    }
    // ���� ������ �������� ���ÿ� ���� ����ִٸ� �̴� �� ��ȣ�� �����ִٴ� ���̰�, ¦�� ���� �ʴ� ���̹Ƿ� 0�� return �Ѵ�.
    return TRUE;
    // �� ��� ������ ��ġ�� ¦�� �´� ���̹Ƿ� 1�� return �Ѵ�.
}
// main �Լ������� ����ڷκ��� ��(���ڿ�)�� �Է¹ް�, Fairing �Լ��� �Ű������� �Ѱ��ش�.
int main() {
    char expression[MAX_SIZE];
    printf("���� �Է��� �ּ���.: ");
    scanf("%s", expression);
    if (Fairing(expression))
        printf("¦�� �´� �� �Դϴ�.\n");
    else
        printf("¦�� ���� �ʴ� �� �Դϴ�.\n");
    // return �� ���� ���� 1�̸� ¦�� �°�, 0�̸� ¦�� ���� �����Ƿ� ������ �ش��ϴ� ����� ����Ѵ�.
    return 0;
}