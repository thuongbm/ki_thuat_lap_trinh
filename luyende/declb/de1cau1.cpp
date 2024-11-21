#include <stdio.h>
#include <stdlib.h>
void input(int n, int **a, FILE *f){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			fscanf (f,"%d", &a[i][j]);
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
int abo_tri_mat(int n , int **a){
	for (int i=0;i<n;i++){
		for (int j=0;j<i;j++){
			if (a[i][j]!=0){
				return 0;
			}
		}
	}
	return 1;
}
main(){
	int n;
	FILE *f;
	f=fopen("de1cau1input.txt", "r");
	fscanf (f, "%d", &n);
	int **a;
	a=(int**) malloc(n*sizeof(int*));
	for (int i=0;i<n;i++){
		a[i]=(int*) malloc(n*sizeof(int));
	}
	input(n,a,f);
	output(n,a);
	int b=abo_tri_mat(n,a);
	if (b) printf ("\nla ma tran tam giac tren");
	else printf ("\nkhong la ma tran tam giac tren");
}
