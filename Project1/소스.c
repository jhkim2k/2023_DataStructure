#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// string.h�� strcpy, strcmp�� ����ϱ� ���� �����Ͽ���.
#define _CRT_SECURE_NO_WARNINGS
// �ʿ��� ���̺귯���� scanf ������ ���� �ʵ��� �����Ͽ���.
#define DataType char 
#define MAX 20
// DataType�� MAX�� ���� char, 20���� �����Ͽ���.
// �̴� ���, �л��� �̸� �迭�� ���Ǿ���.
typedef struct Node {
	struct Node* llink;
	DataType name[MAX];
	struct Node* rlink;
} Node;
// ��屸��ü �̴�. ���� ���߿��Ḯ��Ʈ�� �� ���̹Ƿ�, ���� ��ũ �ΰ��� �л��� �̸��� ���� �迭�� �����.
void add_student(Node** head, char* name) {
	// ���ο� ��带 �����ϰ�, ���� ��尡 �ִٸ� �̾��ִ� �Լ��̴�. 
	// head�� �ٲ� �� �����Ƿ� ���������͸� ����Ͽ���, �л��� �̸��� �޾� ��带 �����.
	Node* student = (Node*)malloc(sizeof(Node));
	strcpy(student->name, name);
	student->llink = NULL;
	student->rlink = NULL;
	// ��带 �ϳ� ����� �ȴ�.

	// ������ ��尡 ���� ��쿡 ��ũ �ΰ��� �ڽ��� ����Ű���� �Ѵ�.
	if (*head == NULL) {
		*head = student;
		(*head)->llink = *head;
		(*head)->rlink = *head;
	}
	// ������ ��尡 �ִ� ��쿡�� ������ ���� ������ �ϰ� �ȴ�.
	else {
		// ����, ������ ��� �߿� ���� ������ ��带 ã�Ƴ���.
		Node* last = (*head)->llink;

		// �׸��� ���ο� ��带 �����ϰ� �ȴ�.(���� ���߿��Ḯ��Ʈ ���·� �����.)
		last->rlink = student;
		student->llink = last;
		student->rlink = *head;
		(*head)->llink = student;
	}
}

void remove_student_R(Node** head, int n) {
	// �л����� ���� ���ڸ�ŭ �ð���� ��, ���������� �̵��ؼ� ��带 �����ϴ� �Լ��̴�.
	// ��尡 �ϳ��� ��쿡�� ��带 �ٷ� ����ϰ� ������.
	if (*head == (*head)->rlink) {
		printf("%s��(��) ���ҽ��ϴ�.\n", (*head)->name);
		free(*head);
		*head = NULL;
		exit(1);
	}

	// ����, ���������� �����Ѵ�.
	Node* start = *head;

	// �л����� ���� ���� n��° �л��� �����Ѵ�.
	for (int i = 0; i < n; i++) {
		start = start->rlink;
		// �̶� �̵��� ������ �������� �Ѵ�.
	}
	printf("%s��(��) ���ŵǾ����ϴ�.\n", start->name);
	// ���� �Ǿ��ٴ� ������ ���� �� ���������� �缳���Ѵ�.
	*head = start->rlink;
	// ���� �ٽ� ���� ���߿��Ḯ��Ʈ�� ����� ���ߵ��� �Ѵ�.
	start->llink->rlink = start->rlink;
	start->rlink->llink = start->llink;	
	// ���������� ������ �л� ��带 ��ȯ�Ѵ�.
	free(start);
}

void remove_student_L(Node** head, int n) {
	// �л����� ���� ���ڸ�ŭ �ݽð���� ��, �������� �̵��ؼ� ��带 �����ϴ� �Լ��̴�.
	// ��κ��� ���� ������ ���� ����.
	if (*head == (*head)->rlink) {
		printf("%s��(��) ���ҽ��ϴ�.\n", (*head)->name);
		free(*head);
		*head = NULL;
		exit(1);
	}

	Node* start = *head;

	for (int i = 1; i <= n; i++) {
		start = start->llink;
		// ���� �ٸ����� �̹����� �������� �̵��ϰ� �ȴ�.
	}
	printf("%s��(��) ���ŵǾ����ϴ�.\n", start->name);

	*head = start->rlink;

	start->llink->rlink = start->rlink;
	start->rlink->llink = start->llink;
	// ���������� ���ŵǴ� ���� ��ȯ�ϰ� �ȴ�.
	free(start);
}

void print_students(Node* head) {
	// �� �Լ��� �л����� ���ŵ� ������ ���� ������� �̸��� ����ϴ� �Լ��̴�.
	printf("���� �л���: ");
	if (head != NULL) {
		Node* start = head;
		do {
			printf("%s ", start->name);
			start = start->rlink;
		} while (start != head);
		// �����ִ� ��� ������� �̸��� ����ϰ�, ���������� �ٽ� ���ƿ����� �ϱ� ���� do-while���� ����ߴ�.
	}
	printf("\n");
}

void main() {
	Node* head = NULL;
	char name[MAX];
	int n;
	int i =0 ;
	printf("�л����� �̸��� ���������� �Է��� �ּ���.\n");
	printf("(�̸��� �ִ� 20���̰�, �����Ϸ��� �ҹ��� q�� �Է��� �ּ���.)\n");
	// ����ڷκ��� �л����� �̸��� �Է¹޴´�.
	while (1) {
		scanf("%s", name);
		if (strcmp(name, "q") == 0) {
			break;
		}
		// ���� strcmp�� �̿��Ͽ� q�� �Է��Ͽ��ٴ� ���� �������� break�� ���� �Է��� �����Ѵ�.
		add_student(&head, name);
		// �Է¹��� ������ add_student �Լ��� �̿��Ͽ� ���� ���߿��Ḯ��Ʈ�� �����.
	} 

	printf("�л����� ���� ���ڸ� �Է��ϼ���.: ");
	scanf("%d", &n);
	printf("\n");
	// �л����� ���� ���ڸ� �Է¹޵��� �Ѵ�.

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
		// ������ �Լ��� �̿��Ͽ� �ð� ����, �ݽð� �������� �̵��Ͽ� �л��� �����ϰ� �����Ҷ����� ���� �л��� ȣ���Ѵ�.
		// �̶�, �ݺ��� �ȿ��� i�� ���� ����Ͽ� ���������� ���� �Լ��� �������� ���� �Լ��� ����Ī�Ͽ� ȣ���ϰ� �ȴ�.
		// remove_student_R, remove_student_L �ȿ� �ִ� if (*head == (*head)->rlink) ���ǹ��� ���� ��尡 1�� ���� �Ǹ� ���� �л����� ����ϰ� ���α׷��� ������.
	}
}