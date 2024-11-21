#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct olym{
	char name[50];
	int score;
	char uni;
};
void input(int n, olym *o, FILE *f){
	for (int i=0;i<n;i++){
		fgets(o[i].name, sizeof(o[i].name),f);
		o[i].name[strlen(o[i].name)-1]='\0';
		fscanf (f, "%d\n", &o[i].score);
		fscanf (f, "%c\n", &o[i].uni);
	}
}
void output(olym o){
	printf ("%s %d %c\n", o.name, o.score, o.uni);
}
void output(int n, olym *o){
	for (int i=0;i<n;i++){
		output(*(o+i));
	}
}
int min (int a, int b){
	return (a<b)?a:b;
}
int max(int a, int b){
	return (a>b)?a:b;
}
int sum(int n, olym *o, char x){
	int sum=0;
	for(int i=0;i<n;i++){
		if (o[i].uni==x){
			sum+=o[i].score;
		}
	}
	return sum;
}

olym *highest(int n, olym *o, int *k){
	olym *h;
	*k=0;
	h=(olym*) malloc(n*sizeof(olym));
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		if (max<o[i].score) max=o[i].score;
	}
	for (int i=0;i<n;i++){
		if (o[i].score==max){
			h[*k]=o[i];
			(*k)++;
		}
	}
	return h;
}
float second_name(int n, olym *o, int a, char x[]){
	int sum;
	int check;
	for (int i=0;i<n;i++){
		if (strncmp(o[i].name, x,a)==0){
			sum+=o[i].score;
			check++;
		}
	}
	return (float)(sum/check);
}
main(){
	int n;
	FILE *f1, *f2;
	f1=fopen("cau2input.txt", "r");
	f2=fopen("caonhat.txt", "w");
	fscanf (f1, "%d\n",&n);
	olym *o;
	o=(olym*) malloc(n*sizeof(olym));
	input(n,o,f1);
	output(n,o);
	if (sum(n,o,'A')==0) printf ("\nkhong co truong a");
	else printf ("\ntong diem truong a la: %d", sum(n,o,'A'));
	if (sum(n,o,'B')==0) printf ("\nkhong co truong b");
	else printf ("\ntong diem truong b la: %d", sum(n,o,'B'));
	if (sum(n,o,'C')==0) printf ("\nkhong co truong c");
	else printf ("\ntong diem truong c la: %d", sum(n,o,'C'));
	int b;
	olym *h=highest(n,o,&b);
	printf ("\n%d", b);
	for (int i=0;i<b;i++){
		fprintf (f2,"%s %d %c\n", h[i].name, h[i].score, h[i].uni);
	}
	printf ("\nnhap ho: ");
	char x[50];
	gets(x);
	int a=strlen(x);
	printf ("diem trung binh cua ho tren la: %.2f", second_name(n,o,a,x));
	fclose(f1);
	fclose(f2);
	free(o);
}
