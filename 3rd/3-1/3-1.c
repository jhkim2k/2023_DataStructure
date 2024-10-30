#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
// �ڵ忡 �ʿ��� ���̺귯�� ���� �� MAX_SIZE�� 100���� ����
// ť�� ����� ���� ����ü
typedef struct ArrayQueue{
    int front;
    int rear;
    char queue[MAX_SIZE][20];
    // �̸��� ���ڿ��̹Ƿ� �迭�� ��ƾ� �ϰ�, �׷��� ���� 2���� �迭 ���
} ArrayQueue;
// ť�� �ʱ�ȭ �ϴ� �Լ�
void init_queue(ArrayQueue* AQ) {
    AQ->front = AQ->rear = 0;
    // front�� rear�� ���� 0�̸� �ȴ�.
}
// ť�� ���� á���� Ȯ���ϴ� �Լ�
int is_queue_full(ArrayQueue* AQ) {
    return ((AQ->rear + 1) % MAX_SIZE) == AQ->front;
    // ���� ť�� �����ϹǷ�, % ������ ���� �����϶�, ��ȭ������ Ȯ���ϴ� ������ ��ģ��.
}
// ť�� ����ִ��� Ȯ���ϴ� �Լ�
int is_queue_empty(ArrayQueue* AQ) {
    return AQ->front == AQ->rear;
    // front�� rear�� ���� ���ٸ� ����ִ� ť�̴�.
}
// ť�� �׸��� �����ϴ� �Լ��̴�. data�� �޾� �Է��ϰ� �ȴ�.
void enqueue(ArrayQueue* AQ, char* data) {
    if (is_queue_full(AQ)) {
        printf("��ȭ ť�̹Ƿ� �׸� ������ �Ұ��� �մϴ�.\n");
        exit(1);
    } // ���� ��ȭ ť��� �޽����� ������ ���α׷��� �����Ѵ�.
    else {
        AQ->rear = (AQ->rear + 1) % MAX_SIZE;
        strcpy(AQ->queue[AQ->rear], data);
    } // rear ���� ��ĭ �̵��ϰ�, data�� �Է��Ѵ�. �̶�, ���� ť�̹Ƿ� % ��������� �����Ѵ�.
}
// ť�� �ִ� �׸��� �ϳ� �����ϴ� �Լ�
void dequeue(ArrayQueue* AQ) {
    if (is_queue_empty(AQ)) {
        printf("���� ť�̹Ƿ� �׸� ������ �Ұ��� �մϴ�.\n");
        exit(1);
    } // ���� ���� ť��� �޽����� ������ ���α׷��� �����Ѵ�.
    else {
        AQ->front = (AQ->front + 1) % MAX_SIZE;
        return AQ->queue[AQ->front];
    } // ���� �����Ǵ� ���� front�� ���� 1 �����Ͽ� ��ȯ�ϸ� �ȴ�. ���������� % ������ �����Ѵ�.
}
// ť������ �� ���� ���� �˷��ִ� �Լ� char* peek�� ������ ť�� ����ִ� ���ڿ� �迭�� ��ȯ�ϴ� ���̱� �����̴�.
char* peek(ArrayQueue* AQ) {
    if (is_queue_empty(AQ)) {
        printf("���� ť�̹Ƿ� �����Ͱ� �����ϴ�.\n");
        exit(1);
    } // ���� ť�̸� �����Ͱ� ���⿡ �޽����� ������ ���α׷��� �����Ѵ�.
    else {
        return AQ->queue[(AQ->front + 1) % MAX_SIZE];
    } // dequeue�� ��������� front�� ���� ��ȭ��Ű�� �ʴ´�.
}

int main() {
    ArrayQueue maleQueue, femaleQueue;
    // ���л� ť maleQueue�� ���л� ť femaleQueue �ΰ��� �����.
    char name[MAX_SIZE];
    char gender;

    init_queue(&maleQueue);
    init_queue(&femaleQueue);
    // �� ť�� �ʱ�ȭ �Ѵ�.
    printf("���� �ּ� ���α׷��Դϴ�.\n");

    while (1) {
        printf("\n���̸�: ");
        scanf("%s", name);
        printf("������ �Է��ϼ���.(f or m): ");
        scanf(" %c", &gender);
        // �̸��� ������ �Է¹ް� �ȴ�.
        if (gender == 'm') {
            enqueue(&maleQueue, name);
            if (!is_queue_empty(&maleQueue) && !is_queue_empty(&femaleQueue)) {
                printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", peek(&maleQueue), peek(&femaleQueue));
                dequeue(&maleQueue);
                dequeue(&femaleQueue);
            }
            else {
                printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
            }
        } // ���� ���ڶ�� maleQueue�� �̸��� �ְ�, ���л� ť�� ���л� ť �ΰ��� �����Ͱ� �ִٸ� Ŀ�÷� ����� ť���� �����͸� �����Ѵ�.
        else if (gender == 'f') {
            enqueue(&femaleQueue, name);
            if (!is_queue_empty(&maleQueue) && !is_queue_empty(&femaleQueue)) {
                printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", peek(&maleQueue), peek(&femaleQueue));
                dequeue(&maleQueue);
                dequeue(&femaleQueue);
            }
            else {
                printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
            }
        } // ���� ���ڶ�� femaleQueue�� �̸��� �ְ�, ���л� ť�� ���л� ť �ΰ��� �����Ͱ� �ִٸ� Ŀ�÷� ����� ť���� �����͸� �����Ѵ�.
        else {
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
        } // ���� �߸��� �����Ͱ� �ԷµǾ��ٸ� ������ ����Ѵ�.
    }
    return 0;
}
