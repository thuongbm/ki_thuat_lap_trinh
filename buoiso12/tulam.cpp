//#include <stdio.h>
//#include <stdlib.h>
//void nhap(int *a, int n, FILE *f){
//	for (int i=0;i<n;i++){
//		fscanf (f,"%d", a+i);
//	}
//}
//void xuat(int *a, int n){
//	for (int i=0;i<n;i++){
//		printf ("%d ", *(a+i));
//	}
//}
//main(){
//	FILE *f;
//	int n;
////	scanf ("%d", &n);
//	int *a;
//	char filename[50];
//	gets(filename);
//	f=fopen(filename, "rt");
//	fscanf (f,"%d", &n);
//	a=(int*)malloc(n*sizeof(int));	
//	nhap(a,n,f);
//	xuat(a,n);
//	fclose(f);
//}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void nhap(int *a, int n, int m){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			printf ("nhap a[%d][%d]", i,j);
			scanf ("%d", (a+n*i+j));
		}
	}
}
void xuat(int *a, int n, int m){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			printf ("%3d", *(a+n*i+j));
		}
		printf ("\n");
	}
}
main(){
	int n,m;
	scanf ("%d", &n);
	scanf ("%d", &m);
	int *a;
	a=(int*) malloc (n*n*sizeof(int));
	nhap(a,n,m);
	xuat(a,n,m);
}
