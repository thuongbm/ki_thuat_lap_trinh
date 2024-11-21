#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct nhanvien{
	char mnv[50];
	char ten[50];
	int luong;
	char phong;
};
void nhap(nhanvien *nv, FILE *f1){
	fgets(nv->mnv, 20, f1);
	nv->mnv[strlen(nv->mnv)-1]='\0';
	fgets(nv->ten, 20, f1);
	nv->ten[strlen(nv->ten)-1]='\0';
	fscanf (f1, "%d\n", &nv->luong);
	fscanf (f1,"%c\n", &nv->phong);
}
void nhap(int n, nhanvien *nv, FILE *f1){
	for (int i=0;i<n;i++){
		nhap(nv+i, f1);
	}
}
void xuat(nhanvien nv){
	printf ("%s %s %d %c\n", nv.mnv, nv.ten, nv.luong, nv.phong);
}
void xuat (int n, nhanvien *nv){
	for (int i=0;i<n;i++){
		xuat(*(nv+i));
	}
}
float luongtb(int n, nhanvien *nv, char x){
	int check=0;
	int tong=0;
	for (int i=0; i<n;i++){
		if (nv[i].phong==x){
			tong+=nv[i].luong;
			check++;
		}
	}
	return (float)(tong/check);
}
int sosanh(int a, int b){
	(a?b)
}
void swap(nhanvien *a, nhanvien *b) {
    nhanvien temp = *a;
    *a = *b;
    *b = temp;
}
void arrange(nhanvien *nv, int n){
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if (nv[j].luong<nv[j+1].luong){
				swap(&nv[j],&nv[j+1]);
			}
		}
	}
}
main(){
	FILE *f1;
	f1=fopen("inputnv.txt", "r");
	int n;
	fscanf (f1, "%d\n", &n);
	nhanvien *nv;
	nv=(nhanvien*) malloc(n*sizeof(nhanvien));
	nhap(n,nv, f1);
	xuat(n,nv);
}
