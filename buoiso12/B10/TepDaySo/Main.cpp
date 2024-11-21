// viet chuong trinh nhap vao mot day so nguyen
// co n phan tu, in ra man hinh tren cùng 1 dong
#include<stdio.h>
#include<stdlib.h>
void nhap(int n, int *a, FILE *f){
	for(int i=0;i<n;i++){
		//printf("Nhap ptu thu %d: ", i);
		fscanf(f, "%d", a+i);
	}
}
void nhap2(int *n, int **a, FILE *f){
	fscanf(f, "%d", n);
	*a = (int *)malloc(*n*sizeof(int));
	for(int i=0;i<*n;i++){
		fscanf(f, "%d", *a+i);
	}
}
void xuat(int n, int *a){
	for(int i=0;i<n;i++){
		printf("%d ", *(a+i));
	}
}
int main(){
	FILE *f;
	int n;
	int *a;
	char tenTep[100];
	printf("Nhap ten tep: ");
	gets(tenTep);
	f = fopen(tenTep, "rt");
	nhap2(&n, &a, f);
	xuat(n, a);
}


