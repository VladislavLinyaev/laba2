#include <stdio.h>
#include <stdlib.h>
#include "func1.h"
int main() {
	struct film* arr = NULL;
	int n = 0;

	int stop = 0;
	while (stop != 1) {
		int key;
		printf("1-create, 2-read, 3-print, 4-search\n");
		scanf("%d", &key);
		switch (key) {
		case 1:
			create(&arr, &n);
			if (arr)
				write(arr, n);
			break;
		case 2:
			read(&arr, &n);
			if (!arr)
				printf("read error\n");
			else
				printf("loaded %d\n", n);
			break;
		case 3:
			for (int i = 0; i < n; i++)
				printf("%s %d %d %s %s %s %d\n", arr[i].title, arr[i].year, arr[i].length, arr[i].country, arr[i].genre, arr[i].director, arr[i].rank);
			break;
		case 4:
			search(&arr, &n);
			break;
		default:
			printf("enter only from 1-4!\n");
			break;
		}
	}
	if (arr)
		free(arr);
	return 0;
}
