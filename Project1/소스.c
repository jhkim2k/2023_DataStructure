#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// string.h는 strcpy, strcmp를 사용하기 위해 선언하였다.
#define _CRT_SECURE_NO_WARNINGS
// 필요한 라이브러리와 scanf 오류가 뜨지 않도록 선언하였다.
#define DataType char 
#define MAX 20
// DataType과 MAX를 각각 char, 20으로 지정하였다.
// 이는 노드, 학생들 이름 배열에 사용되었다.
typedef struct Node {
	struct Node* llink;
	DataType name[MAX];
	struct Node* rlink;
} Node;
// 노드구조체 이다. 원형 이중연결리스트를 쓸 것이므로, 노드당 링크 두개와 학생들 이름을 위한 배열을 만든다.
void add_student(Node** head, char* name) {
	// 새로운 노드를 생성하고, 이전 노드가 있다면 이어주는 함수이다. 
	// head는 바뀔 수 있으므로 이중포인터를 사용하였고, 학생들 이름을 받아 노드를 만든다.
	Node* student = (Node*)malloc(sizeof(Node));
	strcpy(student->name, name);
	student->llink = NULL;
	student->rlink = NULL;
	// 노드를 하나 만들게 된다.

	// 이전의 노드가 없는 경우에 링크 두개를 자신을 가리키도록 한다.
	if (*head == NULL) {
		*head = student;
		(*head)->llink = *head;
		(*head)->rlink = *head;
	}
	// 이전의 노드가 있는 경우에는 이전의 노드와 결합을 하게 된다.
	else {
		// 먼저, 이전의 노드 중에 제일 마지막 노드를 찾아낸다.
		Node* last = (*head)->llink;

		// 그리고 새로운 노드를 연결하게 된다.(원형 이중연결리스트 형태로 만든다.)
		last->rlink = student;
		student->llink = last;
		student->rlink = *head;
		(*head)->llink = student;
	}
}

void remove_student_R(Node** head, int n) {
	// 학생들이 정한 숫자만큼 시계방향 즉, 오른쪽으로 이동해서 노드를 삭제하는 함수이다.
	// 노드가 하나인 경우에는 노드를 바로 출력하고 끝낸다.
	if (*head == (*head)->rlink) {
		printf("%s이(가) 남았습니다.\n", (*head)->name);
		free(*head);
		*head = NULL;
		exit(1);
	}

	// 먼저, 시작지점을 설정한다.
	Node* start = *head;

	// 학생들이 뽑은 수인 n번째 학생을 삭제한다.
	for (int i = 0; i < n; i++) {
		start = start->rlink;
		// 이때 이동을 오른쪽 방향으로 한다.
	}
	printf("%s이(가) 제거되었습니다.\n", start->name);
	// 제거 되었다는 문장을 보낸 후 시작지점을 재설정한다.
	*head = start->rlink;
	// 이제 다시 원형 이중연결리스트의 모습을 갖추도록 한다.
	start->llink->rlink = start->rlink;
	start->rlink->llink = start->llink;	
	// 마지막으로 삭제된 학생 노드를 반환한다.
	free(start);
}

void remove_student_L(Node** head, int n) {
	// 학생들이 정한 숫자만큼 반시계방향 즉, 왼쪽으로 이동해서 노드를 삭제하는 함수이다.
	// 대부분의 연산 과정은 위와 같다.
	if (*head == (*head)->rlink) {
		printf("%s이(가) 남았습니다.\n", (*head)->name);
		free(*head);
		*head = NULL;
		exit(1);
	}

	Node* start = *head;

	for (int i = 1; i <= n; i++) {
		start = start->llink;
		// 위와 다른점은 이번에는 왼쪽으로 이동하게 된다.
	}
	printf("%s이(가) 제거되었습니다.\n", start->name);

	*head = start->rlink;

	start->llink->rlink = start->rlink;
	start->rlink->llink = start->llink;
	// 마찬가지로 제거되는 노드는 반환하게 된다.
	free(start);
}

void print_students(Node* head) {
	// 이 함수는 학생들이 제거될 때마다 남은 사람들의 이름을 출력하는 함수이다.
	printf("남은 학생들: ");
	if (head != NULL) {
		Node* start = head;
		do {
			printf("%s ", start->name);
			start = start->rlink;
		} while (start != head);
		// 남아있는 모든 사람들의 이름을 출력하고, 시작점으로 다시 돌아오도록 하기 위해 do-while문을 사용했다.
	}
	printf("\n");
}

void main() {
	Node* head = NULL;
	char name[MAX];
	int n;
	int i =0 ;
	printf("학생들의 이름을 순차적으로 입력해 주세요.\n");
	printf("(이름은 최대 20자이고, 종료하려면 소문자 q를 입력해 주세요.)\n");
	// 사용자로부터 학생들의 이름을 입력받는다.
	while (1) {
		scanf("%s", name);
		if (strcmp(name, "q") == 0) {
			break;
		}
		// 만약 strcmp를 이용하여 q를 입력하였다는 것이 밝혀지면 break를 통해 입력을 종료한다.
		add_student(&head, name);
		// 입력받은 값들을 add_student 함수를 이용하여 원형 이중연결리스트로 만든다.
	} 

	printf("학생들이 정한 숫자를 입력하세요.: ");
	scanf("%d", &n);
	printf("\n");
	// 학생들이 정한 숫자를 입력받도록 한다.

	while (1) {
		if (i % 2 == 0) {
			remove_student_R(&head, n);
			print_students(head);
			i++;
		}
		else {
			remove_student_L(&head, n);
			print_students(head);
			i++;
		}
		// 각각의 함수를 이용하여 시계 방향, 반시계 방향으로 이동하여 학생을 제거하고 제거할때마다 남은 학생을 호출한다.
		// 이때, 반복문 안에서 i의 값을 사용하여 오른쪽으로 도는 함수와 왼쪽으로 도는 함수를 스위칭하여 호출하게 된다.
		// remove_student_R, remove_student_L 안에 있는 if (*head == (*head)->rlink) 조건문을 통해 노드가 1개 남게 되면 남은 학생들을 출력하고 프로그램을 끝낸다.
	}
}