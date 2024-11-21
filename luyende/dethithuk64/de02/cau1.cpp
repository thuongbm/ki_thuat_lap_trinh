#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void input(int m, int n, int **a, FILE *f){
	for (int i=0; i<m;i++){
		for (int j=0;j<n;j++){
			fscanf (f, "%d ", &a[i][j]);
		}
	}
}
void output(int m, int n, int **a){
	for (int i=0;i<m;i++){
		printf ("\n");
		for (int j=0;j<n;j++){
			printf ("%d ", a[i][j]);
		}
	}
}
float ave_nega(int m, int n, int **a, int *k){
	(*k)=INT_MIN;
	int check=0;
	int sum=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]<0){
				sum+=a[i][j];
				check++;
			}
			if (a[i][j]<0&&a[i][j]>(*k)){
				(*k)=a[i][j];
			}
		}
	}
	if (check==0) return 0;
	else return (float)(sum/check);
}
int sum_of_oddcol(int m, int n, int **a){
	int sum=0;
	for (int j=0;j<n-1;j+=2){
		for (int i=0;i<m;i++){
			if (j%2==0){
				sum+=a[i][j];
			}
		}
	}
	return sum;
}
main(){
	int m,n;
	FILE *f;
	f=fopen("cau1input.txt", "r");
	fscanf (f, "%d %d", &m,&n);
	int **a;
	a=(int**) malloc(m*sizeof (int*));
	for (int i=0;i<m;i++){
		a[i]=(int*) malloc(n*sizeof(int));
	}
	input(m,n,a,f);
	output(m,n,a);
	int b;
	if (ave_nega(m,n,a,&b)==0) printf ("\nkhong co phan tu nao am");
	else{
		printf ("\ntbc cac phan tu am la: %.2f", ave_nega(m,n,a,&b));
		printf ("\nso am lon nhat la: %d", b);
	}
	printf ("\ntong cua cac cot le la: %d", sum_of_oddcol(m,n,a));
}
