#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Sach{
	char ma[100];
	char ten[100];
	char tg[100];
	int tien;
};
//c1
void nhap(Sach *s, int n){
	for (int i=0;i<n;i++){
		printf ("nhap ma sach: ");
		fflush(stdin);
		gets(s->ma);
		printf ("nhap ten sach: ");
		fflush(stdin);
		gets(s->ten);
		printf ("nhap tg sach: ");
		fflush(stdin);
		gets(s->tg);
		printf ("nhap so tien: ");
		scanf ("%d", &s->tien);
	}
}
/*void nhap(Sach *s){
		printf ("nhap ma sach: ");
		fflush(stdin);
		gets(s->ma);
		printf ("nhap ten sach: ");
		fflush(stdin);
		gets(s->ten);
		printf ("nhap tg sach: ");
		fflush(stdin);
		gets(s->tg);
		printf ("nhap so tien: ");
		scanf ("%d", &s->tien);
}
void nhap(int n, Sach *s){
	for (int i=0;i<n;i++){
		nhap(s+i);
	}
}*///c2
//c1
void xuat(Sach *s, int n){
	for (int i=0;i<n;i++){
		printf ("\n%s %s %s %d", s[i].ma,s[i].ten, s[i].tg, s[i].tien);
	}
}
/*void xuat(Sach s){
	printf ("\n%s %s %s %d", s.ma,s.ten, s.tg, s.tien);
}
void xuat(int n, Sach *s){
	for (int i=0;i<n;i++){
		xuat(*(s+i));
	}
}*///c2
void xuat1s(Sach s){
	printf ("\n%s %s %s %d", s.ma,s.ten, s.tg, s.tien);
}
Sach *timsach(int n, Sach *s, char tg[50], int *k, int *check){
	*k=0;
	Sach *a=(Sach*) malloc((n+1)*sizeof(Sach));
	for (int i=0;i<n;i++){
		if (strcmp(s[i].tg,tg)==0){
			a[*k]=s[i];
			*k+=1;
			*check=1;
		}
	}
	return a;
}
main(){
	int n;
	scanf ("%d", &n);
	Sach *s;
	s=(Sach*) malloc((n+1)*sizeof(Sach));
	nhap(s,n);
	xuat(s,n);
	int c,d;
	Sach *b=timsach(n,s,"at", &c,&d);
	//Sach *a=(Sach*) malloc((n+1)*sizeof(Sach));
	if (d==1) xuat(timsach(n,s,"at", &c,&d));
	else printf ("\nkhong co ");
}
