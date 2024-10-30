#include <stdio.h>

int main() {
	int i, j;
	int arr1[4] = {0, 1, 2, 3};
	int arr2[2][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}};
	int *p2i = arr1;
	int (*p2arr1)[4] = &arr1;
	int (*p2arr2)[4] = &arr2[0];  // (*p2arr2)[4] = arr2¿Í °°À½ 
	
	for(i-0; i<4; i++)
		printf("*(p2i+%d)=%d, (*p2arr1)[%d]=%d, p2arr1[0][%d]=%d\n", 
					i, *(p2i+i), i, (*p2arr1)[i], i, p2arr1[0][i]);
	for(i=0; i<2; i++) {
		for(j=0; j<4; j++)
			printf("(*(p2arr2+%d))[%d]=%d ", i, j, (*(p2arr2+i))[j]);
		printf("\n");
	}
}


