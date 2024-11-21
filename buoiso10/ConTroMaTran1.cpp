#include<stdio.h>
#include<stdlib.h>
void nhap(int **a, int n, int m){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			printf("Nhap a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
}
void xuat(int **a, int n, int m){
	for(int i=0;i<n;i++){
		printf("\n");
		for(int j=0;j<m;j++)
			printf("%d ", a[i][j]);
	}
}
int main(){
	int **a;
	int n, m;
	printf("Nhap hang va cot: ");
	scanf("%d%d", &n, &m);
	a = (int**)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++){
		a[i] = (int*)malloc(m*sizeof(int));
	}
	nhap(a, n, m);
	xuat(a, n, m);
}
