#include <stdio.h>
#include <stdlib.h>
struct nhanvien{
	char name[50];
	int money;
	int codej;
};
void input(nhanvien *nv){
	fflush(stdin);
	gets(nv->name);
	scanf ("%d", &nv->money);
	scanf ("%d", &nv->codej);
}
void input(int n, nhanvien *nv){
	for (int i=0;i<n;i++){
		input(nv+i);
	}
}
void output(nhanvien nv, FILE *f){
	fprintf (f,"%s %d %d\n", nv.name, nv.money, nv.codej);
}
void output(int n, nhanvien *nv, FILE *f){
	for (int i=0;i<n;i++){
		output(*(nv+i), f);
	}
}
int average(int n, nhanvien *nv, int x){
	int sum=0;
	int cnt=0;
	for (int i=0;i<n;i++){
		if (nv[i].codej==x){
			sum+=nv[i].money;
			cnt++;
		}
	}
	if (cnt==0) return 0;
	else return (float)(sum/cnt);
}
main(){
	FILE *f;
	f=fopen("cau2output.txt", "w");
	int n;
	scanf ("%d", &n);
	fprintf (f,"%d\n", n);
	nhanvien *nv;
	nv=(nhanvien*) malloc(n*sizeof(nhanvien));
	input(n,nv);
	output(n,nv,f);
	float a=average(n,nv,1);
	if (a==0) printf ("\nkhong co nhan vien 1");
	else printf ("\ntrung binh luong ma 1 la: %.2f", a);
	a=average(n,nv,2);
	if (a==0) printf ("\nkhong co nhan vien 2");
	else printf ("\ntrung binh luong ma 2 la: %.2f", a);
	a=average(n,nv,3);
	if (a==0) printf ("\nkhong co nhan vien 3");
	else printf ("\ntrung binh luong ma 3 la: %.2f", a);
}
