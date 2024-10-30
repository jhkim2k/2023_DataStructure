#include <stdio.h>
#include <stdlib.h>
// �ʿ��� ���̺귯�� ����
// �л��� �̸��� ��� ���� ��� ����ü ����
typedef struct Qnode {
    char name[20];
    struct Qnode* link;
} Qnode;
// ť�� ����� ���� ����
typedef struct LinkedQueue{
    Qnode* front;
    Qnode* rear;
} LinkedQueue;
// ť�� �ʱ�ȭ �ϱ� ���� �Լ��� front�� rear�� NULL�̸� �ȴ�.
void init_queue(LinkedQueue* LQ) {
    LQ->front = LQ->rear = NULL;
}
// ť�� ���� �� �ִ��� �ľ��ϴ� �Լ�
int is_queue_full(Qnode *node) {
    return node == NULL;
}
// ť�� ����ִ��� �ľ��ϴ� �Լ�
int is_queue_empty(LinkedQueue* LQ) {
    return LQ->front == NULL;
}
// ť�� �����͸� �ֵ��� �ϴ� �Լ�
void enqueue(LinkedQueue* LQ, char* data) {
    Qnode* new = (Qnode*)malloc(sizeof(Qnode));
    // ���ο� ��带 ���� ������ �Ҵ�޴´�.
    if (is_queue_full(new)) {
        printf("��ȭ ť�̹Ƿ� �׸� ������ �Ұ����մϴ�.\n");
        exit(1);
    } // �����͸� �ֱ� ���� ��ȭ ť��� �޽����� ����ϰ� ���α׷��� �����Ѵ�.
    else {
        strcpy(new->name, data);
        new->link = NULL;
        if (is_queue_empty(LQ)) {
            LQ->front = LQ->rear = new;
        }
        else {
            LQ->rear->link = new;
            LQ->rear = new;
        }
    } // �����͸� �ְ� ���Ḯ��Ʈ ���·� �����͸� �̾� ������ش�.
}
// ť�� ������ �ϳ��� �����ϴ� �Լ�
void dequeue(LinkedQueue* LQ) {
    if (is_queue_empty(LQ)) {
        printf("���� ť�̹Ƿ� �׸� ������ �Ұ����մϴ�.\n");
        exit(1);
    } // �����͸� �����ϱ� ���� ���� ť��� �޽����� ����ϰ� ���α׷��� �����Ѵ�.
    else {
        Qnode* deleted = LQ->front;
        // �Ǿ� ��带 ������ ���̱⿡ ����Ű�� �����͸� �����Ѵ�.
        LQ->front = LQ->front->link;
        if (is_queue_empty(LQ)) { LQ->rear = NULL; }
        free(deleted);
    } // ������ ��带 ���� ���Ḯ��Ʈ ���¸� ���� �� ��ȯ�Ѵ�.
}
// ť�� �� �տ� �ִ� ���� �������� �Լ�
char* peek(LinkedQueue* LQ) {
    if (is_queue_empty(LQ)) {
        printf("���� ť�̹Ƿ� �����Ͱ� �����ϴ�.\n");
        exit(1);
    } // ���� ť�̸� ������ �����Ͱ� �����Ƿ� �޽����� ����ϰ� ���α׷��� �����Ѵ�.
    return LQ->front->name;
}

int main() {
    LinkedQueue maleQueue, femaleQueue;
    // ���л��� ���л��� ���� ť�� ���� 2�� �����.
    char name[20];
    char gender;

    init_queue(&maleQueue);
    init_queue(&femaleQueue);
    // ������ ť�� �ʱ�ȭ�Ѵ�.
    printf("���� �ּ� ���α׷��Դϴ�.\n");

    while (1) {
        printf("\n�� �̸�: ");
        scanf("%s", name);
        printf("������ �Է��ϼ���. (f or m): ");
        scanf(" %c", &gender);
        // �̸��� ������ �Է¹޾� name �迭�� gender ������ �ִ´�.
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
