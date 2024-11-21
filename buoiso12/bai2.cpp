#include <stdio.h>
#include <stdlib.h>
void nhap(int *a, int n, int m,FILE *f){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			fscanf (f,"%d", (a+n*i+j));
		}
	}
}
void xuat(int *a, int n,int m){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			printf ("%3d", *(a+n*i+j));
		}
		printf ("\n");
	}
}
main(){
	FILE *f;
	int m,n;
	int *a;
	f=fopen("input.txt","rt");
	fscanf (f,"%d", &n);
	fscanf (f,"%d", &m);
	a=(int *) malloc(n*m*sizeof(int));
	nhap(a,n,m,f);
	xuat(a,n,m);
	//chuaxong
}
