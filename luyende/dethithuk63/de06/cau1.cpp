#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	char name[50];
	float score;
	char uni;
};
void input(int n, student *s, FILE *f){
	for (int i=0;i<n;i++){
		fgets(s[i].name, sizeof(s[i].name), f);
		s[i].name[strlen(s[i].name)-1]='\0';
		fscanf (f,"%f\n", &s[i].score);
		fscanf (f,"%c\n", &s[i].uni);
	}
}
void output(student s, FILE *f){
	fprintf (f, "%s %.2f %c\n", s.name, s.score,s.uni);
}
void output(int n, student *s, FILE *f){
	for (int i=0;i<n;i++){
		output(*(s+i), f);
	}
}
void swap(student *a, student *b){
	student temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int n, student *s, FILE *f){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (strcmp(s[i].name, s[j].name)<0){
				swap(&s[i], &s[j]);
			}
		}
		
	}
}
main(){
	FILE *f, *f2;
	f=fopen("cau1input.txt","r");
	f2=fopen("cau1output.txt", "w");
	int n;
	fscanf (f,"%d\n", &n);
	student *s;
	s=(student*) malloc (n*sizeof(student));
	input (n,s,f);
	output(n,s,f2);
	sort(n,s,f);
	fprintf (f2,"\n");
	output(n,s,f2);
}
