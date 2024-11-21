#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void nhap(int *a, int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf ("%d", a+i*n+j);
		}
	}
}
void xuat(int *a, int n){
	for (int i=0;i<n;i++){
		printf("\n");
		for (int j=0;j<n;j++){
			printf ("%3d", *(a+i*n+j));
		}
	}
}
int mttren(int *a, int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<i;j++){
			if (*(a+i*n+j)==0) return 1;
			else{
				return 0;
				break;
			}	
		}
	}
}
int tich(int *a, int n){
	int tich=1;
	for (int j=0;j<n;j++){
		for (int i=0;i<j;i++){
			tich*=*(a+i*n+j);
		}
	}
	return tich;
}
int *tongcot(int *a, int n){
	int *b;
	b=(int*)calloc(n,sizeof(int));
	for (int j=0;j<n;j++){
		for (int i=0;i<n;i++){
			*(b+i)=*(a+i*n+j);
		}
	}
	return b;
	free(b);
}
int *tong2mt(int *a, int *b, int n){
	int *c;
	c=(int*)malloc(n*n*sizeof(int));
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			*(c+i*n+j)=*(a+i*n+j)+*(b+i*n+j);
		}
	}
	return c;
	free(c);
}
int tong(int *a, int n){
	int tong=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			tong+=*(a+i*n+j);
		}
	}
	return tong;
}
int max(int *a, int n){
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (max<*(a+i*n+j)) max=*(a+i*n+j);
		}
	}
	return max;
}
//c2
//void nhap(int **a, int n){
//	for (int i=0;i<n;i++){
//		for (int j=0;j<n;j++){
//			scanf ("%d", &a[i][j]);
//		}
//	}
//}
//void xuat(int **a, int n){
//	for (int i=0;i<n;i++){
//		printf ("\n");
//		for (int j=0;j<n;j++){
//			printf ("%3d", a[i][j]);
//		}
//	}
//}
//int mttren(int **a, int n){
//	for (int i=1;i<n;i++){
//		for (int j=1;j<i;j++){
//			if (a[i][j]==0) return 1;
//			else{
//				return 0;
//				break;
//			}	
//		}
//	}
//}
main(){
	int n;
	printf ("nhap kich thuoc ma tran: ");
	scanf ("%d", &n);
//	int **a;
//	a=(int **) malloc(n*sizeof(int *));
//	for (int i=0;i<n;i++){
//		a[i]=(int *) malloc(n*sizeof(int));
//	}
	int *a;
	a=(int*)malloc(n*n*sizeof(int));
	nhap(a,n);
	xuat(a,n);
	int d=mttren(a,n);
	if (d==0) printf ("\nkhong la ma tran tren");
	if (d==1) printf ("\nla ma tran tren");
	d=tich(a,n);
	printf ("\ntich cua ma tran la: %d", d);
	int *c;
	c=tongcot(a,n);
	int check=0;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (c[i]==c[j]) check++;
		}
	}
	if (check==0) printf ("\nkhong co cot nao bang nhau");
	else{
		printf ("\n nhung cot co tong bang nhau la: ");
		for (int i=0;i<n-1;i++){
			for (int j=i+1;j<n;j++){
			if (c[i]==c[j]) printf ("%d %d, ",i,j);
			}
		}
	}
	int *b;
	b=(int*)malloc(n*n*sizeof(int));
	printf ("\nnhap ma tran b");
	printf ("\n");
	nhap(b,n);
	xuat(b,n);
	c=tong2mt(a,b,n);
	printf ("\ntong cua a+b la: ");
	xuat(c,n);
	d=tong(a,n);
	int e=tong(b,n);
	if (d>e) printf ("\nma tran a tong lon hon");
	if (d<e) printf ("\nma tran b tong lon hon");
	if (d==e) printf ("\n2 ma tran bang nhau");
	d=max(a,n);
	e=max(b,n);
	if (d>e) printf ("\nma tran a max lon hon");
	if (d<e) printf ("\nma tran b max lon hon");
	if (d==e) printf ("\n2 ma tran max bang nhau");
	free(a);
}
