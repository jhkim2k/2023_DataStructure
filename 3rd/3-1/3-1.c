#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
// 코드에 필요한 라이브러리 선언 및 MAX_SIZE를 100으로 설정
// 큐를 만들기 위한 구조체
typedef struct ArrayQueue{
    int front;
    int rear;
    char queue[MAX_SIZE][20];
    // 이름은 문자열이므로 배열로 담아야 하고, 그러기 위해 2차원 배열 사용
} ArrayQueue;
// 큐를 초기화 하는 함수
void init_queue(ArrayQueue* AQ) {
    AQ->front = AQ->rear = 0;
    // front와 rear가 각각 0이면 된다.
}
// 큐가 가득 찼는지 확인하는 함수
int is_queue_full(ArrayQueue* AQ) {
    return ((AQ->rear + 1) % MAX_SIZE) == AQ->front;
    // 원형 큐로 구현하므로, % 연산을 통해 원형일때, 포화인지를 확인하는 과정을 거친다.
}
// 큐가 비어있는지 확인하는 함수
int is_queue_empty(ArrayQueue* AQ) {
    return AQ->front == AQ->rear;
    // front와 rear의 값이 같다면 비어있는 큐이다.
}
// 큐에 항목을 삽입하는 함수이다. data를 받아 입력하게 된다.
void enqueue(ArrayQueue* AQ, char* data) {
    if (is_queue_full(AQ)) {
        printf("포화 큐이므로 항목 삽입이 불가능 합니다.\n");
        exit(1);
    } // 만약 포화 큐라면 메시지를 보내고 프로그램을 종료한다.
    else {
        AQ->rear = (AQ->rear + 1) % MAX_SIZE;
        strcpy(AQ->queue[AQ->rear], data);
    } // rear 값을 한칸 이동하고, data를 입력한다. 이때, 원형 큐이므로 % 연산과정을 수행한다.
}
// 큐에 있는 항목을 하나 삭제하는 함수
void dequeue(ArrayQueue* AQ) {
    if (is_queue_empty(AQ)) {
        printf("공백 큐이므로 항목 삭제가 불가능 합니다.\n");
        exit(1);
    } // 만약 공백 큐라면 메시지를 보내고 프로그램을 종료한다.
    else {
        AQ->front = (AQ->front + 1) % MAX_SIZE;
        return AQ->queue[AQ->front];
    } // 값이 삭제되는 것은 front의 값을 1 증가하여 반환하면 된다. 마찬가지로 % 연산을 수행한다.
}
// 큐에서의 맨 앞의 값을 알려주는 함수 char* peek인 이유는 큐에 들어있는 문자열 배열을 반환하는 것이기 때문이다.
char* peek(ArrayQueue* AQ) {
    if (is_queue_empty(AQ)) {
        printf("공백 큐이므로 데이터가 없습니다.\n");
        exit(1);
    } // 공백 큐이면 데이터가 없기에 메시지를 보내고 프로그램을 종료한다.
    else {
        return AQ->queue[(AQ->front + 1) % MAX_SIZE];
    } // dequeue와 비슷하지만 front의 값을 변화시키진 않는다.
}

int main() {
    ArrayQueue maleQueue, femaleQueue;
    // 남학생 큐 maleQueue와 여학생 큐 femaleQueue 두개를 만든다.
    char name[MAX_SIZE];
    char gender;

    init_queue(&maleQueue);
    init_queue(&femaleQueue);
    // 두 큐를 초기화 한다.
    printf("미팅 주선 프로그램입니다.\n");

    while (1) {
        printf("\n고객이름: ");
        scanf("%s", name);
        printf("성별을 입력하세요.(f or m): ");
        scanf(" %c", &gender);
        // 이름과 성별을 입력받게 된다.
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
