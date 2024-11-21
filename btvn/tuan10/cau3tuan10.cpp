#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
//void nhap(int **a, int m,int n){
//	for (int i=0;i<m;i++){
//		for (int j=0;j<n;j++){
//			printf ("nhap a[%d][%d]", i,j);
//			scanf ("%d", &a[i][j]);
//		}
//	}
//}
//void xuat(int **a, int m, int n){
//	for (int i=0;i<m;i++){
//		for (int j=0;j<n;j++){
//			printf ("%d ", a[i][j]);
//		}
//		printf ("\n");
//	}
//}
void nhap(int *a, int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf ("nhap a[%d][%d]", i,j);
			scanf ("%d", a+i*m+j);
		}
	}
}
void xuat(int *a, int m, int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf ("%3d",*(a+i*m+j));
		}
		printf ("\n");
	}
}
int tong(int *a, int m,int n){
	int tong=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			tong+=*(a+i*m+j);
		}
	}
	return tong;
}
float tbn(int *a, int m, int n,int *check){
	*check=0;
	int tich=1;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (*(a+i*m+j)%2!=0){
				(*check)++;
				tich*=*(a+i*m+j);
			}
		}
	}
	return (float)(pow(tich,1.0/(*check)));
}
//float tbn(int **a, int m, int n, int *check){
//	*check=0;
//	int tich=1;
//	for (int i=0;i<m;i++){
//		for (int j=0;j<n;j++){
//			tich*=a[i][j];
//			*check++;
//		}
//	}
//	return (float)(pow(tich, 1/(*check)));
//}
//int tong(int **a, int m, int n){
//	int tong=0;
//	for (int i=0;i<m;i++){
//		for (int j=0;j<n;j++){
//			tong+=a[i][j];
//		}
//	}
//	return tong;
//}
void xuatday(int *a, int m){
	for (int i=0;i<m;i++){
		printf ("\ntong hang %d: ", i);
		printf ("%d", a[i]);
	}
}
int *hang(int *a, int m, int n){
	int *b;
	b=(int*) calloc(m,sizeof (int));
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			b[i]+=*(a+i*m+j);
		}
	}
	return b;
}
int hangln(int *b, int m){
	int max=INT_MIN;
	int *a;
	a=(int*) calloc(m,sizeof (int));
	for (int i=0;i<m;i++){
		if (b[i]>max){
			max=b[i];
		}
	}
	int vt;
	for (int i=0;i<m;i++){
		if (b[i]==max){
			vt=i;
			break;	
		}
	}
	return vt;
}
main(){
	int m,n;
	printf ("nhap so hang va so cot cua ma tran: ");
	scanf ("%d%d", &m, &n);
	int *a;
	a=(int*) malloc(m*n*sizeof (int));
//	int **a;
//	a=(int**) malloc (m*sizeof (int*));
//	for (int i=0;i<n;i++){
//		a[i]=(int*) malloc(n*sizeof(int));
//	}
	nhap(a,m,n);
	xuat(a,m,n);
	int b=tong(a,m,n);
	printf ("\ntong cua ma tran la: %d", b);
	float c=tbn(a,m,n,&b);
	if (b==0) printf ("\nma tran khong co so le");
	if (b!=0) printf ("\ntrung binh nhan cua so trong ma tran la: %.2f", c);
	int *d=hang(a,m,n);
	xuatday(d,m);
	b=hangln(d, m);
	printf ("\nhang lon nhat la: %d", b);
	free(a);
}
