#include <stdio.h>
#include <stdlib.h>
void input(int n, int **a, FILE *f){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			fscanf (f, "%d", &a[i][j]);
		}
	}
}
void output(int n, int **a){
	for (int i=0;i<n;i++){
		printf ("\n");
		for (int j=0;j<n;j++){
			printf ("%d ", a[i][j]);
		}
	}
}
int **pro_of_2_mat(int n, int **a, int **b){
	int **c;
	c=(int**) malloc(n*sizeof(int*));
	for (int i=0;i<n;i++){
		c[i]=(int*) malloc(n*sizeof(int));
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			c[i][j]=0;
			for (int k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return c;
}
main(){
	FILE *f;
	f=fopen("de3cau1input.txt", "r");
	int n;
	fscanf (f,"%d",&n);
	int **a;
	a=(int**) malloc(n*sizeof(int*));
	for (int i=0;i<n;i++){
		a[i]=(int*) malloc(n*sizeof(int));
	}
	int **b;
	b=(int**) malloc(n*sizeof(int*));
	for (int i=0;i<n;i++){
		b[i]=(int*) malloc(n*sizeof(int));
	}
	input(n,a,f);
	input(n,b,f);
	printf ("ma tran 1");
	output(n,a);
	printf ("\nma tran 2");
	output(n,b);
	printf ("\ntich cua 2 ma tran la:\n");
	int **c=pro_of_2_mat(n,a,b);
	output(n,c);
}
