#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>
struct sinhvien{
	char msv[50];
	char ten[50];
	int nams;
	float toan, ly, hoa, dtb;
};
void input(sinhvien *sv){
	printf("nhap msv: ");
	fflush(stdin);
	gets(sv->msv);
	printf("nhap ten: ");
	fflush(stdin);
	gets(sv->ten);
	printf ("nhap nam sinh: ");
	scanf ("%d", &sv->nams);
	printf ("nhap diem toan ly hoa dtb: ");
	scanf ("%f%f%f%f", &sv->toan, &sv->ly, &sv->hoa, &sv->dtb);
}
void input(sinhvien *sv, int n){
	for (int i=0;i<n;i++){
		input(sv+i);
	}
}
void output(sinhvien sv){
	printf ("%s %s %d %.2f %.2f %.2f %.2f\n", sv.msv, sv.ten,sv.nams, sv.toan,sv.ly, sv.hoa, sv.dtb);
}
void output(sinhvien *sv, int n){
	for (int i=0;i<n;i++){
		output(*(sv+i));
	}
}
sinhvien maxsv(sinhvien *sv, int n){
	sinhvien tim;
//	tim=(sinhvien*) malloc(1*sizeof(sinhvien));
	float max=FLT_MIN;
	for (int i=0;i<n;i++){
		if (sv[i].dtb>max){
			max=sv[i].dtb;
			tim=sv[i];
		}
	}
	return tim;
}
void swap(sinhvien *a, sinhvien *b){
	sinhvien temp;
		  temp=*a;
		  *a=*b;
		  *b=temp;
}
void arrange(sinhvien *sv, int n){
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n;j++){
			if (sv[i].dtb>sv[j].dtb){
				swap(&sv[i], &sv[j]);
			}
		}
	}
}
sinhvien *find(sinhvien *sv, int n, int *k){
	sinhvien *f;
	*k=0;
	f=(sinhvien*) malloc(n*sizeof(sinhvien));
	for (int i=0;i<n;i++){
		if (sv[i].hoa>3&&sv[i].toan>3&&sv[i].ly>3&&sv[i].dtb>5){
			sv[i]=f[*k];
			(*k)++;
		}
	}
	return f;
}
char *oldest(sinhvien *sv, int n){
	char *name;
	int min=INT_MAX;
	name=(char*) malloc (50*sizeof(char));
	for (int i=0;i<n;i++){
		if (sv[i].nams<min){
			min=sv[i].nams;
			name=sv[i].ten;
		}
	}
	return name;
}
sinhvien find2(sinhvien *sv, int n, char x[50], int *k){
	sinhvien tim;
	*k=0;
	for (int i=0;i<n;i++){
		if (strcmp(sv[i].msv,x)==0){
			tim=sv[i];
			*k=1;
		}
	}
	return tim;
}
main(){
	int n;
	scanf ("%d", &n);
	sinhvien *sv;
	sv=(sinhvien*) malloc(n*sizeof(sinhvien));
	input(sv,n);
	output(sv,n);
	printf ("\nsinh vien co diem trung binh lon nhat la: ");
	sinhvien maxtb=maxsv(sv,n);
	output(maxtb);
	arrange(sv, n);
	int k;
	sinhvien *tim=find(sv,n,&k);
	if (k==0) printf ("\nkhong co sinh vien thoa man");
	else{
		printf ("\nsinh vien thoa man la: ");
		output(tim,k);
	}
	char *c;
	printf ("\nsinh vien lon tuoi nhat la: ");
	c=oldest(sv, n);
	printf ("%s ", c);
	char x[50];
	fflush (stdin);
	gets(x);
	sinhvien d;
	d=find2(sv, n, x, &k);
	if (k==0) printf ("\nkhong co sinh vien can tim");
	else{
		printf ("\nsinh vien can tim la: ");
		output(d);
	}
	//chua kiem tra
}
