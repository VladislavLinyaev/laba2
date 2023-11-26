#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func1.h"
void write(struct film * arr, int n){
	if (n <= 0)
	{
		
		return;
	}
	FILE *f=fopen("file.txt","w");
	if(!f)
		return;
	fprintf(f,"%d\n", n);
	for(int i=0; i<n; i++)
		fprintf(f,"%s %d %d %s %s %s %d\n", arr[i].title, arr[i].year, arr[i].length, arr[i].country, arr[i].genre, arr[i].director, arr[i].rank);
fclose(f);
}
void read(struct film **arr, int *n){
FILE *f=fopen("file.txt","r");
	if(!f)
	return;

if(fscanf(f,"%d", n)!= 1)
return;
	if(*n<=0)
	return;
*arr=(struct film *)calloc(*n,sizeof(struct film));
for (int i = 0; i < *n; i++)
	fscanf(f, "%s %d %d %s %s %s %d\n", (*arr)[i].title, &(*arr)[i].year, &(*arr)[i].length, (*arr)[i].country, (*arr)[i].genre, (*arr)[i].director, &(*arr)[i].rank );
fclose(f);
}
void create(struct film **arr,int *n){
	printf("n=");
	scanf("%d",n);
		if(*n<= 0)
		return;
*arr =(struct film *)calloc(*n,sizeof(struct film));
for(int i=0; i<*n;i++){
	printf("title=");
	scanf("%s",(*arr)[i].title);
	printf("year=");
	scanf("%d", &(*arr)[i].year);
	printf("length=");
	scanf("%d", &(*arr)[i].length);
	printf("country=");
	scanf("%s", (*arr)[i].country);
	printf("genre=");
	scanf("%s", (*arr)[i].genre);
	printf("director=");
	scanf("%s", (*arr)[i].director);
	printf("rank=");
	scanf("%d", &(*arr)[i].rank);
}
}
void search_field(struct film* arr, int i, char * field, char* search_name) {
	char* find_string = strstr(field, search_name);
	if (find_string != NULL)
		printf("find - %s %d %d %s %s %s %d\n", arr[i].title, arr[i].year, arr[i].length, arr[i].country, arr[i].genre, arr[i].director, arr[i].rank);
}



void search(struct film** arr, int* n) {
	int key;
	char search_name[100];
	printf("Enter the search field\n");
	printf("1-title, 2-year, 3-length, 4-country, 5-genre, 6-director, 7-rank\n");
	scanf("%d", &key);
	switch (key) {
	case 1:
		printf("Enter the search -> title <- name:");
		scanf("%s", search_name);
		for (int i = 0; i < *n; i++)
		{
			char* find_string = strstr((*arr)[i].title, search_name);
			if (find_string != NULL)
				printf("find - %s %d %d %s %s %s %d\n", (*arr)[i].title, (*arr)[i].year, (*arr)[i].length, (*arr)[i].country, (*arr)[i].genre, (*arr)[i].director, (*arr)[i].rank);
		}
		break;
	case 2:
		printf("Enter the search -> year <- name:");
		scanf("%s", search_name);
		for (int i = 0; i < *n; i++)
		{
			char digit[100];
			sprintf(digit,"%i",(*arr)[i].year);
			char* find_string = strstr(digit, search_name);
			if (find_string != NULL)
				printf("find - %s %d %d %s %s %s %d\n", (*arr)[i].title, (*arr)[i].year, (*arr)[i].length, (*arr)[i].country, (*arr)[i].genre, (*arr)[i].director, (*arr)[i].rank);
		}
		break;
	case 3:
		printf("Enter the search -> length <- name:");
		scanf("%s", search_name);
		for (int i = 0; i < *n; i++)
		{
			char digit[100];
			sprintf(digit, "%i", (*arr)[i].length);
			char* find_string = strstr(digit, search_name);
			if (find_string != NULL)
				printf("find - %s %d %d %s %s %s %d\n", (*arr)[i].title, (*arr)[i].year, (*arr)[i].length, (*arr)[i].country, (*arr)[i].genre, (*arr)[i].director, (*arr)[i].rank);
		}
		break;
	case 4:
		printf("Enter the search -> country <- name:");
		scanf("%s", search_name);
		for (int i = 0; i < *n; i++)
		{
			char* find_string = strstr((*arr)[i].country, search_name);
			if (find_string != NULL)
				printf("find - %s %d %d %s %s %s %d\n", (*arr)[i].title, (*arr)[i].year, (*arr)[i].length, (*arr)[i].country, (*arr)[i].genre, (*arr)[i].director, (*arr)[i].rank);
		}
		break;
	case 5:
		printf("Enter the search -> genre <- name:");
		scanf("%s", search_name);
		for (int i = 0; i < *n; i++)
		{
			char* find_string = strstr((*arr)[i].genre, search_name);
			if (find_string != NULL)
				printf("find - %s %d %d %s %s %s %d\n", (*arr)[i].title, (*arr)[i].year, (*arr)[i].length, (*arr)[i].country, (*arr)[i].genre, (*arr)[i].director, (*arr)[i].rank);
		}
		break;
	case 6:
		printf("Enter the search -> director <- name:");
		scanf("%s", search_name);
		for (int i = 0; i < *n; i++)
		{
			char* find_string = strstr((*arr)[i].director, search_name);
			if (find_string != NULL)
				printf("find - %s %d %d %s %s %s %d\n", (*arr)[i].title, (*arr)[i].year, (*arr)[i].length, (*arr)[i].country, (*arr)[i].genre, (*arr)[i].director, (*arr)[i].rank);
		}
		break;
	case 7:
		printf("Enter the search -> rank <- name:");
		scanf("%s", search_name);
		for (int i = 0; i < *n; i++)
		{
			char digit[100];
			sprintf(digit, "%i", (*arr)[i].rank);
			char* find_string = strstr(digit, search_name);
			if (find_string != NULL)
				printf("find - %s %d %d %s %s %s %d\n", (*arr)[i].title, (*arr)[i].year, (*arr)[i].length, (*arr)[i].country, (*arr)[i].genre, (*arr)[i].director, (*arr)[i].rank);
		}
		break;
	default:
		printf("enter only from 1-7!\n");
		break;
	}
}

