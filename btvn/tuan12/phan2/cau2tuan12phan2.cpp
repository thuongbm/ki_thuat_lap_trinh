#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
struct sinhvien{
	char msv[100];
	char ten[100];
	int nams;
	int toan, ly, hoa, tb;
};
void nhap(sinhvien *sv){
	printf ("nhap ma sinh vien: ");
	fflush(stdin);
	gets(sv->msv);
	printf ("nhap ten sinh vien: ");
	fflush (stdin);
	gets(sv->ten);
	printf ("nhap nam sinh: ");
	scanf ("%d", &sv->nams);
	printf ("nhap diem toan ly hoa: ");
	scanf ("%d%d%d", &sv->toan, &sv->ly, &sv->hoa);
	printf ("nhap diem trung binh: ");
	scanf ("%d", &sv->tb);
}
void nhap(sinhvien *sv, int n){
	for (int i=0;i<n;i++){
		nhap(sv+i);
	}
}
void xuat1(sinhvien *sv){
	printf ("%s\n%s\n%d\n%d %d %d\n%d\n", sv->msv,sv->ten,sv->nams,sv->toan,sv->ly,sv->hoa,sv->tb);
}
void xuat(sinhvien *sv, int n){
	for (int i=0;i<n;i++){
		xuat1((sv+i));
	}
}
sinhvien *maxsv(sinhvien *sv, int n){
	int max=INT_MIN;
	sinhvien *b;
	b=(sinhvien*) malloc(n*sizeof(sinhvien));
	for (int i=0;i<n;i++){
		if (sv[i].tb>max){
			max=sv[i].tb;
			b[i]=sv[i];
		}	
	}
	return b;
}
void sx(sinhvien *sv, int n){
	for (int i=1;i<n;i++){
		int j=i;
		while(sv[j].tb<=sv[j-1].tb&&j>0){
			sinhvien temp=sv[j];
				sv[j]=sv[j-1];
				sv[j-1]=temp;
			j--;
		}
	}
}
sinhvien *timsv(sinhvien *sv, int n, int *k){
	sinhvien *b;
	*k=0;
	b=(sinhvien*) malloc(n*sizeof(sinhvien));
	for (int i=0;i<n;i++){
		if (sv[i].tb>5&&sv[i].toan>=3&&sv[i].ly>=3&&sv[i].hoa>=3){
			b[*k]=sv[i];
			(*k)++;
		}
	}
	return b;
}
sinhvien *maxtuoi(sinhvien *sv, int n){
	int min=INT_MAX;
	sinhvien *b;
	b=(sinhvien*) malloc(n*sizeof(sinhvien));
	for (int i=0;i<n;i++){
		if (sv[i].nams<min){
			min=sv[i].nams;
			b[i]=sv[i];
		}	
	}
	return b;
}
sinhvien *timsv2(sinhvien *sv, int n,char x[], int *k){
	sinhvien *b;
	*k=0;
	b=(sinhvien*) malloc(n*sizeof(sinhvien));
	for (int i=0;i<n;i++){
		if(strcmp(sv[i].ten,x)==0){
			b[*k]=sv[i];
			(*k)++;
		}
	}
	return b;
}
main(){
	int n;
	printf ("nhap so sinh vien: ");
	scanf ("%d", &n);
	sinhvien *sv;
	sv=(sinhvien*) malloc(n*sizeof(sinhvien));
	nhap(sv,n);
	xuat(sv,n);
	sinhvien *b;
	b=maxsv(sv,n);
	printf ("\nsinh vien diem cao nhat la: \n");
	xuat1(b);
	sx(sv,n);
	printf ("\ndanh sach sinh vien sau khi sap xep la: \n");
	xuat(sv,n);
	int c;
	b=timsv(sv,n,&c);
	if (c==0) printf ("\nkhong co sinh vien nao thoa man");
	else{
		printf ("\nsinh vien thoa man la: ");
		xuat(b,c);
	}
	printf ("\nsinh vien tuoi cao nhat la: \n");
	xuat1(b);
	char x[100];
	printf ("\nnhap ten sv can tim: ");
	fflush(stdin);
	gets(x);
	b=timsv2(sv,n,x,&c);
	if (c==0) printf ("\nkhong co sinh vien nao de tim");
	else{
		printf ("\nsinh vien can tim la: ");
		xuat(b,c);
	}
}
