#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void input(int m,int n, int **a, FILE *f){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			fscanf (f,"%d", &a[i][j]);
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
int *acc_odd_of_col(int m, int n, int **a){
	int acc[n]={1};
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (a[j][i]%2!=0) acc[i]*=a[j][i];	
		}
	}
	return acc;
}
int eve_num(int m, int n, int **a){
	int max=INT_MIN;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]%2==0) max=a[i][j];
		}
	}
	return max;
}
main(){
	int m,n;
	FILE *f;
	f=fopen("cau1input.txt", "r");
	fscanf (f,"%d %d", &m, &n);
	int **a;
	a=(int**) malloc (m*sizeof(int*));
	for (int i=0;i<m;i++){
		a[i]=(int*) malloc (n*sizeof(int));
	}
	input(m,n,a,f);
	output(m,n,a);
	printf ("\ntich cac phan tu le theo tung cot cua ma tran la: \n");
	int *b;
	b=acc_odd_of_col(m,n,a);
	for (int i=0;i<n;i++){
		printf ("cot %d: %d\n", i, b[i]);
	}
	printf ("\nphan tu chan lon nhat cua ma tran la: %d o", eve_num(m,n,a));
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]==eve_num(m,n,a)){
				printf ("\ncot: %d\nhang: %d", i,j);
				break;
			}
		}
	}
}
