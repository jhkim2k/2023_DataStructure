#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h> 

typedef struct Movie {
	char title[50];
	int release;
	int viewers;
} Movie;

typedef struct ArrayBO {
	int length;
	Movie movies[MAX_SIZE];
} ArrayBO;

void add_movie(ArrayBO* BO, Movie m) {
	if (BO->length == MAX_SIZE) {
		printf("영화를 더 이상 추가할 수 없습니다.\n");
		exit(1);
	}
	BO->movies[BO->length] = m;
	BO->length++;
}

ArrayBO merge_BO(ArrayBO* a, ArrayBO* b) {
	ArrayBO c;
	int idx_a = 0, idx_b = 0;

	c.length = 0;

	while (idx_a < a->length && idx_b < b->length) {
		if (a->movies[idx_a].viewers >= b->movies[idx_b].viewers) {
			add_movie(&c, a->movies[idx_a]);
			idx_a++;
		}
		else {
			add_movie(&c, b->movies[idx_b]);
			idx_b++;
		}
	}

	for (; idx_a < a->length; idx_a++) add_movie(&c, a->movies[idx_a]);

	for (; idx_b < b->length; idx_b++) add_movie(&c, b->movies[idx_b]);
	return c;
}

int main() {
	int i;
	ArrayBO domestic = { 4, { {"명량", 2014, 1761},
							  {"베테랑", 2015, 1341},
							  {"도둑들", 2012, 1298},
							  {"암살", 2015, 1270} } };
	ArrayBO  foreign = { 3, { {"아바타", 2009, 1333},
							  {"인터스텔라", 2014, 1030},
							  {"겨울왕국", 2014, 1029} } };
	ArrayBO merged = merge_BO(&domestic, &foreign);

	for ( i = 0; i < merged.length; i++) {
		printf("제목=%s, 관객수=%d\n",
			merged.movies[i].title, merged.movies[i].viewers);
	}
}






