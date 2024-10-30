#include <stdio.h>
#include <stdlib.h>
#define DataType Movie

typedef struct Movie {
	char title[50];
	int release;
	int viewers;
} Movie;

typedef struct Node {
	DataType data;
	struct Node *link;
} Node;

typedef struct LinkedBO {
	int length;
	Node *head;
	Node *tail;
} LinkedBO;

Node *create_node(DataType data) {
	Node *new = (Node *)malloc(sizeof(Node));
	if (!new) {
		printf("노드 생성에 실패하였습니다.\n");
		exit(1);
	}
	new->data = data;
	new->link = NULL;
	return new;
}

void init_list(LinkedBO *BO) {
	BO->length = 0;
	BO->head = BO->tail = NULL;
}

void print_list(LinkedBO *BO) {
	int i;
	Node *ptr = BO->head;
	for ( i = 1; i <= BO->length; i++) {
		printf("제목=%s, 개봉연도=%d, 관객수=%d\n", 
			ptr->data.title, ptr->data.release, ptr->data.viewers);
		ptr = ptr->link;
	}
}

void insert_node_last(LinkedBO *BO, Node *new) {
	BO->length++;
	if (BO->tail == NULL)
		BO->head = BO->tail = new;
	else {
		BO->tail->link = new;
		BO->tail = new; 	
	}
}

LinkedBO merge_BO(LinkedBO *a, LinkedBO *b) {
	LinkedBO c;
	Node *p2a=a->head, *p2b=b->head;
	
	init_list(&c);
	while (p2a &&p2b) {
		if (p2a->data.viewers >= p2b->data.viewers) {
			insert_node_last(&c, create_node(p2a->data));
			p2a = p2a->link;
		}
		else {
			insert_node_last(&c, create_node(p2b->data));
			p2b = p2b->link;
		}
	}
	
	while (p2a) {
		insert_node_last(&c, create_node(p2a->data));
		p2a = p2a->link;
	}
	
	while (p2b) {
		insert_node_last(&c, create_node(p2b->data));
		p2b = p2b->link;
	}
	return c;
}

int main() {
	LinkedBO domestic, foreign;
	Movie m1 = {"명량", 2014, 1761};
	Movie m2 = {"베테랑", 2015, 1341};
	Movie m3 = {"도둑들", 2012, 1298};
	Movie m4 = {"암살", 2015, 1270};
	Movie m5 = {"아바타", 2009, 1333};
	Movie m6 = {"인터스텔라", 2014, 1030};
	Movie m7 = {"겨울왕국", 2014, 1029};
	
	init_list(&domestic);
	init_list(&foreign);
	
	insert_node_last(&domestic, create_node(m1));
	insert_node_last(&domestic, create_node(m2));
	insert_node_last(&domestic, create_node(m3));
	insert_node_last(&domestic, create_node(m4));
	
	insert_node_last(&domestic, create_node(m5));
	insert_node_last(&domestic, create_node(m6));
	insert_node_last(&domestic, create_node(m7));
	
	LinkedBO merged = merge_BO(&domestic, &foreign);
	print_list(&merged);
}








