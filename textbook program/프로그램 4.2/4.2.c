#include <stdio.h>
#include <stdlib.h>

int main() {
	int row, col;
	int *arr1=NULL, **arr2=NULL;
	int i = 0, j = 0;
	
	printf("1차원 배열의 크기: ");
	scanf("%d", &col);
	arr1 = (int *)malloc(sizeof(int) * col);
	for (i = 0; i < col; i++) {
		arr1[i] = i;
		printf("arr1[%d]=%d ", i, arr1[i]);
	}
	printf("\n");
	free(arr1);
	
	printf("2차원 배열의 크기: ");
	scanf("%d %d", &row, &col);
	arr2 = (int **)malloc(sizeof(int *) * row);
	for (i = 0; i < row; i++) {
		arr2[i] = (int *)malloc(sizeof(int) * col);
		for (j = 0; j < col; j++) {
			arr2[i][j] = col * i + j;
			printf("arr2[%d][%d]=%d ", i, j, arr2[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < row; i++) free(arr2[i]);
	free(arr2);
}
