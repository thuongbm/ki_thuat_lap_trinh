#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct nhanvien{
	char name[50];
	int wage;
	char jod;
};
void input(nhanvien *nv, FILE *f1){
	fgets(nv->name, 50, f1);
	nv->name[strlen(nv->name)-1]='\0';
	fscanf (f1, "%d\n", &nv->wage);
	fscanf (f1, "%c\n", &nv->jod);
}
void input(int n, nhanvien *nv, FILE *f1){
	for (int i=0;i<n;i++){
		input(nv+i, f1);
	}
}
void output(nhanvien nv, FILE *f2){
	fprintf (f2, "%s %d %c\n", nv.name, nv.wage, nv.jod);
}
void output(int n, nhanvien *nv, FILE *f2){
	for (int i=0;i<n;i++){
		output(*(nv+i),f2);
	}
}
float average(int n, nhanvien *nv, char x, int *k){
	*k=0;
	int sum=0;
	for (int i=0;i<n;i++){
		if (nv[i].jod==x){
			sum+=nv[i].wage;
			(*k)++;
		}
	}
	if (*k==0) return 0;
	return (float)(sum/(*k));
}
int sumwage(int n, nhanvien *nv, char x){
	int sum=0;
	for (int i=0;i<n;i++){
		if (nv[i].jod==x){
			sum+=nv[i].wage;
		}
	}
	return sum;
}
int compare(int a, int b){
	return (a>b) ? a:b;
}
int count(int n, nhanvien *nv, char x){
	int check=0;
	for (int i=0;i<n;i++){
		if (nv[i].jod==x){
			(check)++;
		}
	}
	return check;
}
main(){
	int n;
	FILE *f1, *f2;
	f1=fopen("inputcau6.txt", "r");
	f2=fopen("outputcau6.txt", "w");
	fscanf (f1, "%d\n", &n);
	fprintf (f2,"%d\n", n);
	nhanvien *nv;
	nv=(nhanvien*) malloc (n*sizeof(nhanvien));
	input(n,nv, f1);
	int k;
	float a;
	a=average(n, nv, '1', &k);
	if (k==0) printf ("khong co nhan vien nao lam viec 1");
	else printf ("trung binh luong cua cong viec 1 la: %.2f", a);
	a=average(n, nv, '2', &k);
	if (k==0) printf ("\nkhong co nhan vien nao lam viec 2");
	else printf ("\ntrung binh luong cua cong viec 2 la: %.2f", a);
	a=average(n, nv, '3', &k);
	if (k==0) printf ("\nkhong co nhan vien nao lam viec 3");
	else printf ("\ntrung binh luong cua cong viec 3 la: %.2f", a);
	output(n,nv,f2);
	k=sumwage(n,nv,'2');
	if (k==0) printf ("\nkhong co nhan vien lam viec 2");
	else printf ("\ntong luong cua cong viec 2 la: %d", k);
	int check1=count(n, nv, '1');
	int check2=count(n, nv, '2');
	int check3=count(n, nv, '3');
	int max;
	if (compare(check1, compare(check2, check3))==check1) max=1;
	else if (compare(check1, compare(check2, check3))==check2) max=2;
	else  max=3;
	printf ("\ncong viec co nhieu nv lam nhat la : %d", max);
}
