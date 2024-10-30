#include <stdio.h>
#include <stdlib.h>
// 필요한 라이브러리 선언
// 학생의 이름을 담기 위한 노드 구조체 선언
typedef struct Qnode {
    char name[20];
    struct Qnode* link;
} Qnode;
// 큐의 헤드노드 구조 정의
typedef struct LinkedQueue{
    Qnode* front;
    Qnode* rear;
} LinkedQueue;
// 큐를 초기화 하기 위한 함수로 front와 rear이 NULL이면 된다.
void init_queue(LinkedQueue* LQ) {
    LQ->front = LQ->rear = NULL;
}
// 큐가 가득 차 있는지 파악하는 함수
int is_queue_full(Qnode *node) {
    return node == NULL;
}
// 큐가 비어있는지 파악하는 함수
int is_queue_empty(LinkedQueue* LQ) {
    return LQ->front == NULL;
}
// 큐에 데이터를 넣도록 하는 함수
void enqueue(LinkedQueue* LQ, char* data) {
    Qnode* new = (Qnode*)malloc(sizeof(Qnode));
    // 새로운 노드를 위한 공간을 할당받는다.
    if (is_queue_full(new)) {
        printf("포화 큐이므로 항목 삽입이 불가능합니다.\n");
        exit(1);
    } // 데이터를 넣기 전에 포화 큐라면 메시지를 출력하고 프로그램을 종료한다.
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
    } // 데이터를 넣고 연결리스트 형태로 포인터를 이어 만들어준다.
}
// 큐의 데이터 하나를 삭제하는 함수
void dequeue(LinkedQueue* LQ) {
    if (is_queue_empty(LQ)) {
        printf("공백 큐이므로 항목 삭제가 불가능합니다.\n");
        exit(1);
    } // 데이터를 삭제하기 전에 공백 큐라면 메시지를 출력하고 프로그램을 종료한다.
    else {
        Qnode* deleted = LQ->front;
        // 맨앞 노드를 삭제할 것이기에 가리키는 포인터를 지정한다.
        LQ->front = LQ->front->link;
        if (is_queue_empty(LQ)) { LQ->rear = NULL; }
        free(deleted);
    } // 삭제할 노드를 빼고 연결리스트 형태를 만든 후 반환한다.
}
// 큐의 맨 앞에 있는 값을 가져오는 함수
char* peek(LinkedQueue* LQ) {
    if (is_queue_empty(LQ)) {
        printf("공백 큐이므로 데이터가 없습니다.\n");
        exit(1);
    } // 공백 큐이면 가져올 데이터가 없으므로 메시지를 출력하고 프로그램을 종료한다.
    return LQ->front->name;
}

int main() {
    LinkedQueue maleQueue, femaleQueue;
    // 남학생과 여학생을 위한 큐를 각각 2개 만든다.
    char name[20];
    char gender;

    init_queue(&maleQueue);
    init_queue(&femaleQueue);
    // 각각의 큐를 초기화한다.
    printf("미팅 주선 프로그램입니다.\n");

    while (1) {
        printf("\n고객 이름: ");
        scanf("%s", name);
        printf("성별을 입력하세요. (f or m): ");
        scanf(" %c", &gender);
        // 이름과 성별을 입력받아 name 배열과 gender 변수에 넣는다.
        if (gender == 'm') {
            enqueue(&maleQueue, name);
            if (!is_queue_empty(&maleQueue) && !is_queue_empty(&femaleQueue)) {
                printf("커플이 탄생했습니다! %s과 %s\n", peek(&maleQueue), peek(&femaleQueue));
                dequeue(&maleQueue);
                dequeue(&femaleQueue);
            }
            else {
                printf("아직 대상자가 없습니다. 기다려주십시요.\n");
            }
        } // 만약 남자라면 maleQueue에 이름을 넣고, 여학생 큐와 남학생 큐 두개에 데이터가 있다면 커플로 만들고 큐에서 데이터를 삭제한다.
        else if (gender == 'f') {
            enqueue(&femaleQueue, name);
            if (!is_queue_empty(&maleQueue) && !is_queue_empty(&femaleQueue)) {
                printf("커플이 탄생했습니다! %s과 %s\n", peek(&maleQueue), peek(&femaleQueue));
                dequeue(&maleQueue);
                dequeue(&femaleQueue);
            }
            else {
                printf("아직 대상자가 없습니다. 기다려주십시요.\n");
            }
        } // 만약 여자라면 femaleQueue에 이름을 넣고, 여학생 큐와 남학생 큐 두개에 데이터가 있다면 커플로 만들고 큐에서 데이터를 삭제한다.
        else {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        } // 만약 잘못된 데이터가 입력되었다면 오류를 출력한다.
    }
    return 0;
}
