#include <stdio.h>
#include <stdlib.h>
void nhap(int *a,int n, FILE *f){
	for (int i=0;i<n;i++){
		fscanf (f,"%d", a+i);
	}
}
void xuat(int *a, int n){
	for (int i=0;i<n;i++){
		printf ("%d ", *(a+i));
	}
}
main(){
	FILE *f;
	int m,n;
	int *a,*b;
//	char filename[50];
//	gets(filename);
	f=fopen("input.txt","rt");
	fscanf (f,"%d", &n);
	a=(int*) malloc(n*sizeof(int));
	nhap(a,n,f);
//	printf ("\n");
	fscanf (f,"%d", &m);
	b=(int*) malloc(m*sizeof(int));
	nhap(b,m,f);
	xuat(a,n);
	printf ("\n");
	xuat(b,m);
	free(a);
	free(b);	
	fclose(f);
}
