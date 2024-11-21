#include<stdio.h>
#include<stdlib.h>
void nhap(int n, float *a, FILE *f){
	for(int i=0;i<=n;i++)
		fscanf(f, "%f", a+i);
}
void xuat(int n, float *a){
	printf("\n");
	for(int i=0;i<=n;i++)
		printf("%.2f  ", *(a+i));
}
int main(){
	int n, m;
	float *a, *b;
	FILE *f;
	char tenTep[100];
	printf("Nhap ten tep: ");
	gets(tenTep);
	f = fopen(tenTep, "rt");
	fscanf(f, "%d", &n);
	a = (float *)malloc(n*sizeof(float));
	nhap(n, a, f);
	fscanf(f, "%d", &m);
	b = (float *)malloc(m*sizeof(float));
	nhap(m, b, f);
	xuat(n, a);
	xuat(m, b);
}
