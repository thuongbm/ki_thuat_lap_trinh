#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
struct olym{
	char name[50];
	int score;
	char school;
};
void input(int n, olym *o, FILE *f){
	for (int i=0;i<n;i++){
		fgets(o[i].name, 50, f);
		o[i].name[strlen(o[i].name)-1]='\0';
		fscanf (f, "%d\n", &o[i].score);
		fscanf (f, "%c\n", &o[i].school);
	}
}
void output(olym o, FILE *f){
	fprintf (f, "%s %d %c\n", o.name, o.score, o.school);
}
void output(int n, olym *o, FILE *f){
	for (int i=0;i<n;i++){
		output(*(o+i), f);
	}
}
void output(int n, olym *o){
	for (int i=0;i<n;i++){
		printf ("%s %d %c\n", o[i].name, o[i].score, o[i].school);
	}
}
int sum(int n ,olym *o, char x){
	int sum=0;
	for (int i=0;i<n;i++){
		if (o[i].school==x) sum+=o[i].score;
	}
	return sum;
}
int max(int a, int b){
	return (a>b) ? a:b;
}
int maxsc(int n, olym *o){
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		if (o[i].score>max) max=o[i].score;
	}
	return max;
}
olym *list(int n, olym *o, int x, int *k){
	*k=0;
	olym *m;
	m=(olym*) malloc(n*sizeof(olym));
	for (int i=0;i<n;i++){
		if (o[i].score>=x){
			m[*k]=o[i];
			(*k)++;
		} 
	}
	return m;
}

main(){
	int n;
	FILE *f1, *f2;
	f1=fopen ("cau2input.txt", "r");
	f2=fopen ("cau2output.txt", "w");
	fscanf (f1, "%d\n", &n);
	olym *o;
	o=(olym*) malloc(n*sizeof(olym));
	int a,b,c,d,k;
	input(n,o,f1);
	output(n,o);
	a=sum(n,o,'A');
	if (a==0) printf ("\nkhong co truong a");
	else printf ("\ntong diem truong a la: %d", a);
	b=sum(n,o,'B');
	if (b==0) printf ("\nkhong co truong b");
	else printf ("\ntong diem truong b la: %d", b);
	c=sum(n,o,'C');
	if (c==0) printf ("\nkhong co truong c");
	else printf ("\ntong diem truong c la: %d", c);
	d=sum(n,o,'D');
	if (d==0) printf ("\nkhong co truong d");
	else printf ("\ntong diem truong d la: %d", d);
	printf ("\ntruong co tong diem cao nhat la: ");
	if (max(max(a,b), max(c,d))==a) printf ("a ");
	if (max(max(a,b), max(c,d))==b) printf ("b ");
	if (max(max(a,b), max(c,d))==c) printf ("c ");
	if (max(max(a,b), max(c,d))==d) printf ("d ");
	printf ("\ndiem cao nhat ma thi sinh dat duoc la: %d", maxsc(n,o));
	printf ("\ndanh sach thi sinh da diem cao nhat la: \n");
	olym *e=list(n,o,maxsc(n,o), &k);
	output(k,e);
	int x;
	scanf ("%d", &x);
	e=list(n,o,x,&k);
	if (k==0) fprintf (f2,"\nkhong sinh vien nao thoa man");
	else{
		fprintf (f2, "\ndanh sach sinh vien thoa man la: \n");
		output(k,e,f2);
	}
}
