#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct monhoc{
	char mamon[100];
	char tenmon[100];
	int sotin;
};
struct kyhoc{
	char maky[100];
	int somon;
	monhoc *mon;
	int tongtin;
};
void nhapmh(monhoc &mh){
	printf("nhap ma mon: ");
    fflush(stdin);
    gets(mh.mamon);
    printf("nhap ten mon: ");
    fflush(stdin);
    gets(mh.tenmon);
    printf("nhap so tin: ");
    scanf("%d", &mh.sotin);
}
void nhap(kyhoc *kh){
	printf ("nhap ma ky: ");
	fflush(stdin);
	gets (kh->maky);
	printf ("nhap so mon: ");
	scanf ("%d", &kh->somon);
	printf ("nhap mon hoc\n");
//	monhoc *mon;
	kh->mon = (monhoc*)malloc((kh->somon) * sizeof(monhoc));
	for (int i=0;i<kh->somon;i++){
		nhapmh(kh->mon[i]);
	}
}
void nhap(kyhoc *kh, int n){
	for (int i=0;i<n;i++){
		nhap(kh+i);
	}
}
void xuatmh(monhoc mh){
	printf ("%s %s %d\n", mh.mamon, mh.tenmon, mh.sotin);
}
void xuat(kyhoc *kh){
	printf ("%s %d\n", kh->maky, kh->somon);
	for (int i=0;i<kh->somon;i++){
		xuatmh(kh->mon[i]);
	}
}
void xuat(kyhoc *kh, int n){
	for (int i=0;i<n;i++){
		xuat(kh);
	}
}
kyhoc *tinhtin(kyhoc *kh, int n){
	kyhoc *a;
	a=(kyhoc*) calloc ((n+1),sizeof (kyhoc));
	for (int i=0;i<kh->somon;i++){
		a[i].tongtin+=kh->mon[i].sotin;
	}
	return a;
}
int timky(kyhoc *kh, int n,kyhoc *a){
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		if (a[i].tongtin>max){
			max=a[i].tongtin;
		}
	}
	return max;
}
main(){
	int m,n;
	printf ("nhap so mon va so ky: ");
	scanf ("%d%d", &m,&n);
	kyhoc *kh;
	kh=(kyhoc*) malloc ((n+1)*sizeof (kyhoc));
	nhap(kh,n);
	xuat(kh,n);
	int b;
	kyhoc *a;
	a=(kyhoc*) malloc ((n+1)*sizeof (kyhoc));
	a=tinhtin(kh, n);
	printf ("\ntong tin cua cac ky hoc theo tung ky la: ");
	for (int i=0;i<kh->somon;i++){
		printf ("\n%s", kh[i].maky);
		printf ("\n%d", a[i].tongtin);
	}
	printf ("\nky co tong tin lon nhat la: ");
	b=timky(kh,n,a);
	for (int i=0;i<n;i++){
		if (a[i].tongtin==b){
			printf ("%s ", kh[i].maky);
		}
	}
	free(kh);
	free(a);
}
